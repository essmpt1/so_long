/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_init_tex_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 22:05:48 by malourei          #+#    #+#             */
/*   Updated: 2024/09/01 01:15:38 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_init_player(t_game *data)
{
	data->player.img = mlx_xpm_file_to_image(data->mlx, data->player.path,
			&data->player.wid, &data->player.hei);
	if (!data->player.img || textures_width_height(data->player,
			data->mlx) == 0)
	{
		ft_printf("Error\nFalha ao carregar textura %s\n", data->player.path);
		free_map(&data->map);
		mlx_destroy_window(data->mlx, data->win.win);
		mlx_destroy_image(data->mlx, data->box.img);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(1);
	}
}

void	ft_init_collectable(t_game *data)
{
	data->coll.img = mlx_xpm_file_to_image(data->mlx, data->coll.path,
			&data->coll.wid, &data->coll.hei);
	if (!data->coll.img || textures_width_height(data->coll, data->mlx) == 0)
	{
		ft_printf("Error\nFalha ao carregar textura %s\n", data->coll.path);
		free_map(&data->map);
		mlx_destroy_window(data->mlx, data->win.win);
		mlx_destroy_image(data->mlx, data->box.img);
		mlx_destroy_image(data->mlx, data->player.img);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(1);
	}
}

void	ft_init_wall(t_game *data)
{
	data->wall.img = mlx_xpm_file_to_image(data->mlx, data->wall.path,
			&data->wall.wid, &data->wall.hei);
	if (!data->wall.img || textures_width_height(data->wall, data->mlx) == 0)
	{
		ft_printf("Error\nFalha ao carregar textura %s\n", data->wall.path);
		free_map(&data->map);
		mlx_destroy_window(data->mlx, data->win.win);
		mlx_destroy_image(data->mlx, data->box.img);
		mlx_destroy_image(data->mlx, data->player.img);
		mlx_destroy_image(data->mlx, data->coll.img);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(1);
	}
}

void	ft_init_floor(t_game *data)
{
	data->floor.img = mlx_xpm_file_to_image(data->mlx, data->floor.path,
			&data->floor.wid, &data->floor.hei);
	if (!data->floor.img || textures_width_height(data->floor, data->mlx) == 0)
	{
		ft_printf("Error\nFalha ao carregar textura %s\n", data->floor.path);
		free_map(&data->map);
		mlx_destroy_window(data->mlx, data->win.win);
		mlx_destroy_image(data->mlx, data->box.img);
		mlx_destroy_image(data->mlx, data->player.img);
		mlx_destroy_image(data->mlx, data->coll.img);
		mlx_destroy_image(data->mlx, data->wall.img);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(1);
	}
}

void	ft_init_exit(t_game *data)
{
	data->exit.img = mlx_xpm_file_to_image(data->mlx, data->exit.path,
			&data->exit.wid, &data->exit.hei);
	if (!data->exit.img || textures_width_height(data->exit, data->mlx) == 0)
	{
		ft_printf("Error\nFalha ao carregar textura %s\n", data->exit.path);
		free_map(&data->map);
		mlx_destroy_window(data->mlx, data->win.win);
		mlx_destroy_image(data->mlx, data->box.img);
		mlx_destroy_image(data->mlx, data->player.img);
		mlx_destroy_image(data->mlx, data->coll.img);
		mlx_destroy_image(data->mlx, data->wall.img);
		mlx_destroy_image(data->mlx, data->floor.img);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(1);
	}
}
