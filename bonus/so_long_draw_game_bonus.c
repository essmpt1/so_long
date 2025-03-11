/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_draw_game_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 22:54:40 by malourei          #+#    #+#             */
/*   Updated: 2024/08/31 22:40:30 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	draw_game_help(t_texture *data, t_texture *floor)
{
	data->data = mlx_get_data_addr(data->img, &data->bpp, &data->size_line,
			&data->endian);
	put_img_to_img(*data, *floor);
}

static void	print_box(t_game *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->box.hei)
	{
		x = 0;
		while (x < data->box.wid)
		{
			put_pixel_img(data->box, x, y, 0x000000);
			x++;
		}
		y++;
	}
}

static void	print_text(t_game *data)
{
	int		x_img;
	int		x_str_col;
	int		x_str_t_col;

	x_str_col = data->win.width - 180;
	x_str_t_col = data->win.width - 150;
	x_img = data->win.width - 70;
	print_box(data);
	mlx_string_put(data->mlx, data->win.win, data->win.width - 240,
		data->win.height - 15, 0xFF0000, "Collected: ");
	ft_putnbr_mlx(data, data->map.n_coll, &x_str_col, data->win.height - 15);
	mlx_string_put(data->mlx, data->win.win, data->win.width - 155,
		data->win.height - 15, 0xFF0000, "/");
	ft_putnbr_mlx(data, data->collected, &x_str_t_col, data->win.height - 15);
	mlx_string_put(data->mlx, data->win.win, data->win.width - 105,
		data->win.height - 15, 0xFF0000, "Moves: ");
	ft_putnbr_mlx(data, data->moves, &x_img, data->win.height - 15);
}

void	draw_game(t_game *data)
{
	int	i;

	data->floor.data = mlx_get_data_addr(data->floor.img, &data->floor.bpp,
			&data->floor.size_line, &data->floor.endian);
	draw_game_help(&data->curr_play, &data->floor);
	draw_game_help(&data->wall, &data->floor);
	draw_game_help(&data->coll, &data->floor);
	draw_game_help(&data->exit, &data->floor);
	draw_map(data);
	i = 0;
	while (i < data->map.n_enemies)
	{
		draw_game_help(&data->enemy[i].enemy, &data->floor);
		mlx_put_image_to_window(data->mlx, data->win.win,
			data->enemy[i].enemy.img, data->enemy[i].coor.x - data->camara.x,
			data->enemy[i].coor.y - data->camara.y);
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->win.win, data->curr_play.img,
		data->p_coor.x - data->camara.x, data->p_coor.y - data->camara.y);
	mlx_put_image_to_window(data->mlx, data->win.win, data->box.img,
		data->win.width - data->box.wid, data->win.height - data->box.hei);
	print_text(data);
}
