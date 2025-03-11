/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_clear_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 22:04:33 by malourei          #+#    #+#             */
/*   Updated: 2024/08/10 01:03:41 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
}

void	close_call(t_game *data)
{
	int	i;

	free_map(&data->map);
	mlx_destroy_window(data->mlx, data->win.win);
	mlx_destroy_image(data->mlx, data->box.img);
	mlx_destroy_image(data->mlx, data->player.img);
	mlx_destroy_image(data->mlx, data->coll.img);
	mlx_destroy_image(data->mlx, data->wall.img);
	mlx_destroy_image(data->mlx, data->floor.img);
	mlx_destroy_image(data->mlx, data->exit.img);
	mlx_destroy_image(data->mlx, data->player2.img);
	mlx_destroy_image(data->mlx, data->player3.img);
	mlx_destroy_image(data->mlx, data->player4.img);
	i = 0;
	while (i < data->map.n_enemies)
	{
		mlx_destroy_image(data->mlx, data->enemy[i].enemy.img);
		i++;
	}
	mlx_destroy_display(data->mlx);
	free(data->enemy);
	free(data->mlx);
	exit(0);
}

int	handle_close(t_game *data)
{
	close_call(data);
	return (0);
}

void	ft_player_dead(t_game *data)
{
	ft_printf("GAME OVER...\nJá foste!!!\nPerdeu, PLAYBOY!!\n");
	close_call(data);
}
