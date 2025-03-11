/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_draw_game.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 22:54:40 by malourei          #+#    #+#             */
/*   Updated: 2024/09/04 20:22:11 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_map_help(t_game *data, int i, int j)
{
	int	dst_x;
	int	dst_y;

	dst_x = (j * 64) - data->camara.x;
	dst_y = (i * 64) - data->camara.y;
	if (data->map.map[i][j] == '0' || (data->map.map[i][j] == 'E'
			&& data->collected != data->map.n_coll))
		mlx_put_image_to_window(data->mlx, data->window.window,
			data->floor.img, dst_x, dst_y);
	else if (data->map.map[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->window.window,
			data->wall.img, dst_x, dst_y);
	else if (data->map.map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx, data->window.window,
			data->coll.img, dst_x, dst_y);
	else if (data->map.map[i][j] == 'E'
				&& (data->collected == data->map.n_coll))
		mlx_put_image_to_window(data->mlx, data->window.window,
			data->exit.img, dst_x, dst_y);
}

static void	draw_map(t_game *data)
{
	int	i;
	int	j;

	i = data->camara.y / 64;
	while (i < (data->camara.y / 64) + (data->window.height / 64))
	{
		j = data->camara.x / 64;
		while (j < (data->camara.x / 64) + (data->window.width / 64))
		{
			draw_map_help(data, i, j);
			j++;
		}
		i++;
	}
}

static void	draw_game_help(t_texture *data, t_texture *floor)
{
	data->data = mlx_get_data_addr(data->img, &data->bpp, &data->size_line,
			&data->endian);
	put_img_to_img(*data, *floor);
}

void	draw_game(t_game *data)
{
	data->floor.data = mlx_get_data_addr(data->floor.img, &data->floor.bpp,
			&data->floor.size_line, &data->floor.endian);
	draw_game_help(&data->wall, &data->floor);
	draw_game_help(&data->coll, &data->floor);
	draw_game_help(&data->exit, &data->floor);
	draw_game_help(&data->player, &data->floor);
	draw_map(data);
	mlx_put_image_to_window(data->mlx, data->window.window, data->player.img,
		data->player.x - data->camara.x, data->player.y - data->camara.y);
}
