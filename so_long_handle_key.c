/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 23:04:19 by malourei          #+#    #+#             */
/*   Updated: 2024/08/29 21:04:03 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	change_player_map(t_game *data, int flag)
{
	if (data->map.map[data->player.y / 64][data->player.x / 64] != 'E' && flag)
		data->map.map[data->player.y / 64][data->player.x / 64] = '0';
	else
	{
		collect_collectable(data);
		data->map.map[data->player.y / 64][data->player.x / 64] = 'P';
	}
}

static void	move_viewport(t_game *data, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = data->camara.x + dx;
	new_y = data->camara.y + dy;
	change_player_map(data, 1);
	if (new_x + data->window.width <= data->map.width
		&& data->player.x > data->window.width / 2 && data->player.x
		<= (data->map.width - data->window.width / 2) && new_x >= 0)
	{
		data->player.x += dx;
		data->camara.x = new_x;
	}
	else
		data->player.x += dx;
	if (new_y + data->window.height <= data->map.height
		&& data->player.y > data->window.height / 2 && data->player.y
		<= (data->map.height - data->window.height / 2) && new_y >= 0)
	{
		data->player.y += dy;
		data->camara.y = new_y;
	}
	else
		data->player.y += dy;
	change_player_map(data, 0);
}

int	handle_key(int key, t_game *data)
{
	int	new_x;
	int	new_y;

	new_x = data->player.x;
	new_y = data->player.y;
	if (key == KEY_ESQ)
		close_call(data);
	if (key == KEY_W && new_y > 0
		&& (data->map.map[(new_y - 64) / 64][new_x / 64] != '1'))
		move_viewport(data, 0, -64);
	else if (key == KEY_S
		&& (data->map.map[(new_y + 64) / 64][new_x / 64] != '1'))
		move_viewport(data, 0, 64);
	else if (key == KEY_A && new_x > 0
		&& (data->map.map[new_y / 64][(new_x - 64) / 64] != '1'))
		move_viewport(data, -64, 0);
	else if (key == KEY_D
		&& (data->map.map[new_y / 64][(new_x + 64) / 64] != '1'))
		move_viewport(data, 64, 0);
	else
		return (1);
	data->moves++;
	ft_printf("Movimentos: %d\n", data->moves);
	draw_game(data);
	return (0);
}
