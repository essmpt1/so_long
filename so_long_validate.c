/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_validate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:14:30 by malourei          #+#    #+#             */
/*   Updated: 2024/09/04 22:45:21 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	valid_chars(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < (map->height / 64))
	{
		j = 0;
		while (j < map->width / 64)
		{
			if (ft_strchr("01PCE", map->map[i][j]) == 0)
			{
				ft_printf("ERROR\nCaracter de mapa errado!(01PCE)\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static int	valid_walls(t_map *map)
{
	int	i;

	i = 0;
	while (i <= (map->height / 64) - 1)
	{
		if (map->map[i][0] != '1' || map->map[i][(map->width / 64) - 1] != '1')
		{
			ft_printf("ERROR\nParede inválida!(ALtura)\n");
			return (0);
		}
		i++;
	}
	i = 0;
	while (i <= (map->width / 64) - 1)
	{
		if (map->map[0][i] != '1' || map->map[(map->height / 64) - 1][i] != '1')
		{
			ft_printf("ERROR\nParede inválida!(Largura)\n");
			return (0);
		}
		i++;
	}
	return (1);
}

static int	valid_rectangule(t_map *map)
{
	int	i;
	int	width;
	int	height;

	width = map->width / 64;
	height = map->height / 64;
	i = 0;
	if (width <= 3 || height <= 3 || width == height)
	{
		ft_printf("ERROR\nMapa muito pequeno ou quadrado!\n");
		return (0);
	}
	while (map->map[i] != NULL && i < (height - 1))
	{
		if ((int)(ft_strlen(map->map[i]) - 1) != width)
		{
			ft_printf("ERROR\nMapa não é retangular!\n");
			return (0);
		}
		i++;
	}
	if ((map->map[i][width] == '\0' || map->map[i][width] == '\n'))
		return (1);
	ft_printf("ERROR\nMapa não é retangular!\n");
	return (0);
}

static int	valid_components(t_map *map)
{
	int	i;
	int	j;

	map->n_players = 0;
	map->n_exits = 0;
	map->n_coll = 0;
	i = -1;
	while (++i < (map->height / 64))
	{
		j = -1;
		while (++j < (map->width / 64))
		{
			if (map->map[i][j] == 'P')
				map->n_players++;
			if (map->map[i][j] == 'E')
				map->n_exits++;
			if (map->map[i][j] == 'C')
				map->n_coll++;
		}
	}
	if (map->n_players == 1 && map->n_exits == 1 && map->n_coll > 0)
		return (1);
	ft_printf("ERROR\nComponentes inválidos!(P = 1, E = 1, C >= 1)\n");
	return (0);
}

int	validate_map(t_map *map)
{
	t_texture	player;

	if (valid_chars(map) == 0)
		return (0);
	if (valid_walls(map) == 0)
		return (0);
	if (valid_rectangule(map) == 0)
		return (0);
	if (valid_components(map) == 0)
		return (0);
	player = ft_validate_player_coor(map);
	if (validate_reachability(map, player.x, player.y) == 0)
		return (0);
	return (1);
}
