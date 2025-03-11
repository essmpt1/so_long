/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_validate_comp_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 23:50:56 by malourei          #+#    #+#             */
/*   Updated: 2024/09/04 19:20:43 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	valid_components_help(t_map *map, int i, int j)
{
	if (map->map[i][j] == 'P')
		map->n_players++;
	if (map->map[i][j] == 'E')
		map->n_exits++;
	if (map->map[i][j] == 'C')
		map->n_coll++;
	if (map->map[i][j] == 'R')
		map->n_enemies++;
}

int	valid_components(t_map *map)
{
	int	i;
	int	j;

	map->n_players = 0;
	map->n_exits = 0;
	map->n_coll = 0;
	map->n_enemies = 0;
	i = -1;
	while (++i < (map->height / 64))
	{
		j = -1;
		while (++j < (map->width / 64))
		{
			valid_components_help(map, i, j);
		}
	}
	if (map->n_players == 1 && map->n_exits == 1 && map->n_coll > 0
		&& map->n_enemies > 0)
		return (1);
	ft_printf("ERROR\nComponentes inválidos!(P = 1, E = 1, C >= 1, R >= 1)\n");
	return (0);
}

int	ft_validate_map_ber(char *path)
{
	char	*ber;
	int		n;

	ber = ft_strchr2(path, 46);
	if (ft_strlen(ber) != 4)
		return (0);
	n = ft_strncmp(ber, ".ber", 4);
	if (n == 0)
		return (1);
	return (0);
}
