/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_draw_map_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 22:21:16 by malourei          #+#    #+#             */
/*   Updated: 2024/08/26 23:41:22 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	draw_map_help(t_game *data, int i, int j)
{
	int	dst_x;
	int	dst_y;

	dst_x = (j * 64) - data->camara.x;
	dst_y = (i * 64) - data->camara.y;
	if (data->map.map[i][j] == '0' || (data->map.map[i][j] == 'E'
			&& data->collected != data->map.n_coll))
		mlx_put_image_to_window(data->mlx, data->win.win,
			data->floor.img, dst_x, dst_y);
	else if (data->map.map[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->win.win,
			data->wall.img, dst_x, dst_y);
	else if (data->map.map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx, data->win.win,
			data->coll.img, dst_x, dst_y);
	else if (data->map.map[i][j] == 'E'
			&& (data->collected == data->map.n_coll))
		mlx_put_image_to_window(data->mlx, data->win.win,
			data->exit.img, dst_x, dst_y);
}

void	draw_map(t_game *data)
{
	int	i;
	int	j;

	i = data->camara.y / 64;
	while (i < (data->camara.y / 64) + (data->win.height / 64))
	{
		j = data->camara.x / 64;
		while (j < (data->camara.x / 64) + (data->win.width / 64))
		{
			draw_map_help(data, i, j);
			j++;
		}
		i++;
	}
}
