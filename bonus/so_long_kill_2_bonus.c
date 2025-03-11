/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_kill_2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 00:04:53 by malourei          #+#    #+#             */
/*   Updated: 2024/08/31 22:09:05 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	enemy_coordenates_number(t_map *map, t_enemy *enemy, int z)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < (map->height / 64))
	{
		j = 0;
		while (j <= (map->width / 64))
		{
			if (map->map[i][j] == 'R')
			{
				if (k == z)
				{
					enemy->coor.x = j * 64;
					enemy->coor.y = i * 64;
				}
				k++;
			}
			j++;
		}
		i++;
	}
	enemy->direction = 1;
}

void	start_enemy(t_game *data)
{
	int	i;

	data->enemy = malloc(sizeof(t_enemy) * data->map.n_enemies);
	if (!data->enemy)
	{
		ft_printf("Error\nProblema ao alocar memória para os inimigos.\n");
		exit(1);
	}
	i = 0;
	while (i < data->map.n_enemies)
	{
		enemy_coordenates_number(&data->map, &data->enemy[i], i);
		ft_strcpy(data->enemy[i].enemy.path, "textures/enemy.xpm");
		ft_init_enemy(data, i);
		i++;
	}
}
