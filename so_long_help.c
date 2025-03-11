/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 21:55:51 by malourei          #+#    #+#             */
/*   Updated: 2024/09/01 01:38:26 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_texture	ft_validate_player_coor(t_map *map)
{
	t_texture	player;
	int			i;
	int			j;

	i = 0;
	while (i < map->height / 64)
	{
		j = 0;
		while (j < map->width / 64)
		{
			if (map->map[i][j] == 'P')
			{
				player.x = i;
				player.y = j;
			}
			j++;
		}
		i++;
	}
	return (player);
}

void	textures_coordenates(t_game *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < (data->map.height / 64))
	{
		j = 0;
		while (j <= (data->map.width / 64))
		{
			if (data->map.map[i][j] == 'P')
			{
				data->player.x = j * data->player.wid;
				data->player.y = i * data->player.hei;
			}
			if (data->map.map[i][j] == 'C')
				data->collected++;
			if (data->map.map[i][j] == 'E')
			{
				data->exit.x = j;
				data->exit.y = i;
			}
			j++;
		}
		i++;
	}
}

void	collect_collectable(t_game *data)
{
	if (data->map.map[data->player.y / 64][data->player.x / 64] == 'C')
	{
		data->map.map[data->player.y / 64][data->player.x / 64] = '0';
		data->map.n_coll++;
		ft_printf("Collect: %d / %d\n", data->map.n_coll, data->collected);
		if (data->collected == data->map.n_coll)
		{
			data->map.map[data->exit.y][data->exit.x] = 'E';
			draw_game(data);
		}
	}
	if (data->map.map[data->player.y / 64][data->player.x / 64] == 'E'
		&& (data->collected == data->map.n_coll))
	{
		ft_printf("Deste com a saida...\nParabéns... Ganhaste Playboy. :)\n");
		close_call(data);
	}
}

int	textures_width_height(t_texture tex, void *mlx)
{
	if (!tex.img)
		return (0);
	if (tex.wid != 64 || tex.hei != 64)
	{
		ft_printf("Error\nTextura com dimensões inválidas\n");
		mlx_destroy_image(mlx, tex.img);
		return (0);
	}
	return (1);
}
