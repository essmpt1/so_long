/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_flood_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 22:31:38 by malourei          #+#    #+#             */
/*   Updated: 2024/08/28 23:26:31 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	free_visited(char **visited, int i)
{
	int	tmp;

	tmp = 0;
	while (i > tmp)
	{
		free(visited[tmp]);
		tmp++;
	}
	free(visited);
}

static int	is_valid_position(t_map *map, int x, int y)
{
	if (x >= 0 && y >= 0 && x < (map->height / 64) && y < (map->width / 64))
		return (1);
	return (0);
}

static void	fill_flood(t_map *map, int x, int y, char **visited)
{
	if (map->map[x][y] == '1' || map->map[x][y] == 'R'
		|| !is_valid_position(map, x, y) || visited[x][y])
		return ;
	visited[x][y] = '1';
	fill_flood(map, x - 1, y, visited);
	fill_flood(map, x + 1, y, visited);
	fill_flood(map, x, y - 1, visited);
	fill_flood(map, x, y + 1, visited);
}

static int	validate_reachability_help(t_map *map, char **visited)
{
	int	i;
	int	j;
	int	valid;

	valid = 1;
	i = 0;
	while (i < (map->height / 64))
	{
		j = 0;
		while (j < (map->width / 64))
		{
			if ((map->map[i][j] == 'C' || map->map[i][j] == 'E')
				&& !visited[i][j])
			{
				valid = 0;
				break ;
			}
			j++;
		}
		i++;
	}
	free_visited(visited, i);
	if (!valid)
		ft_printf("Error\nMapa impossivel de jogar!\n");
	return (valid);
}

int	validate_reachability(t_map *map_data, int player_x, int player_y)
{
	int		i;
	char	**visited;

	visited = malloc((map_data->height / 64) * sizeof(char *));
	if (!visited)
		return (1);
	i = 0;
	while (i < (map_data->height / 64))
	{
		visited[i] = ft_calloc((map_data->width / 64), sizeof(char));
		if (!visited[i])
		{
			free_visited(visited, i);
			return (1);
		}
		i++;
	}
	fill_flood(map_data, player_x, player_y, visited);
	return (validate_reachability_help(map_data, visited));
}
