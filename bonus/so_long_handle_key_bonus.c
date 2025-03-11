/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_handle_key_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 22:13:33 by malourei          #+#    #+#             */
/*   Updated: 2024/08/29 23:25:56 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	change_player_img(t_game *data, int flag)
{
	if (data->map.map[data->p_coor.y / 64][data->p_coor.x / 64] != 'E' && flag)
		data->map.map[data->p_coor.y / 64][data->p_coor.x / 64] = '0';
	else
	{
		collect_collectable(data);
		data->map.map[data->p_coor.y / 64][data->p_coor.x / 64] = 'P';
	}
}

static void	move_viewport(t_game *data, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = data->camara.x + dx;
	new_y = data->camara.y + dy;
	change_player_img(data, 1);
	if (new_x + data->win.width <= data->map.width
		&& data->p_coor.x > data->win.width / 2 && data->p_coor.x
		<= (data->map.width - data->win.width / 2) && new_x >= 0)
	{
		data->p_coor.x += dx;
		data->camara.x = new_x;
	}
	else
		data->p_coor.x += dx;
	if (new_y + data->win.height <= data->map.height
		&& data->p_coor.y > data->win.height / 2 && data->p_coor.y
		<= (data->map.height - data->win.height / 2) && new_y >= 0)
	{
		data->p_coor.y += dy;
		data->camara.y = new_y;
	}
	else
		data->p_coor.y += dy;
	change_player_img(data, 0);
}

static void	handle_key_help(int x, int y, t_game *data, t_texture player)
{
	data->curr_play = player;
	move_viewport(data, x, y);
}

int	handle_key(int key, t_game *data)
{
	int	new_x;
	int	new_y;

	new_x = data->p_coor.x;
	new_y = data->p_coor.y;
	if (key == KEY_ESQ)
		close_call(data);
	if (key == KEY_W && new_y > 0
		&& (data->map.map[(new_y - 64) / 64][new_x / 64] != '1'))
		handle_key_help(0, -64, data, data->player3);
	else if (key == KEY_S
		&& (data->map.map[(new_y + 64) / 64][new_x / 64] != '1'))
		handle_key_help(0, 64, data, data->player4);
	else if (key == KEY_A && new_x > 0
		&& (data->map.map[new_y / 64][(new_x - 64) / 64] != '1'))
		handle_key_help(-64, 0, data, data->player2);
	else if (key == KEY_D
		&& (data->map.map[new_y / 64][(new_x + 64) / 64] != '1'))
		handle_key_help(64, 0, data, data->player);
	else
		return (1);
	data->moves++;
	ft_printf("Movimentos: %d\n", data->moves);
	return (0);
}
