/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_init_tex_2_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 23:32:07 by malourei          #+#    #+#             */
/*   Updated: 2024/09/01 00:56:18 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_init_player2(t_game *data)
{
	data->player2.img = mlx_xpm_file_to_image(data->mlx, data->player2.path,
			&data->player2.wid, &data->player2.hei);
	if (!data->player2.img || textures_width_height(data->player2,
			data->mlx) == 0)
	{
		ft_printf("Error\nFalha ao carregar textura %s\n", data->player2.path);
		free_map(&data->map);
		mlx_destroy_window(data->mlx, data->win.win);
		mlx_destroy_image(data->mlx, data->box.img);
		mlx_destroy_image(data->mlx, data->player.img);
		mlx_destroy_image(data->mlx, data->coll.img);
		mlx_destroy_image(data->mlx, data->wall.img);
		mlx_destroy_image(data->mlx, data->floor.img);
		mlx_destroy_image(data->mlx, data->exit.img);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(1);
	}
}

void	ft_init_player_back(t_game *data)
{
	data->player3.img = mlx_xpm_file_to_image(data->mlx, data->player3.path,
			&data->player3.wid, &data->player3.hei);
	if (!data->player3.img || textures_width_height(data->player3,
			data->mlx) == 0)
	{
		ft_printf("Error\nFalha ao carregar textura %s\n", data->player3.path);
		free_map(&data->map);
		mlx_destroy_window(data->mlx, data->win.win);
		mlx_destroy_image(data->mlx, data->box.img);
		mlx_destroy_image(data->mlx, data->player.img);
		mlx_destroy_image(data->mlx, data->coll.img);
		mlx_destroy_image(data->mlx, data->wall.img);
		mlx_destroy_image(data->mlx, data->floor.img);
		mlx_destroy_image(data->mlx, data->exit.img);
		mlx_destroy_image(data->mlx, data->player2.img);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(1);
	}
}

void	ft_init_player_front(t_game *data)
{
	data->player4.img = mlx_xpm_file_to_image(data->mlx, data->player4.path,
			&data->player4.wid, &data->player4.hei);
	if (!data->player4.img || textures_width_height(data->player4,
			data->mlx) == 0)
	{
		ft_printf("Error\nFalha ao carregar textura %s\n", data->player4.path);
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
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(1);
	}
}

void	ft_init_enemy(t_game *data, int i)
{
	data->enemy[i].enemy.img = mlx_xpm_file_to_image(data->mlx,
			data->enemy[i].enemy.path, &data->enemy[i].enemy.wid,
			&data->enemy[i].enemy.hei);
	if (!data->enemy[i].enemy.img || textures_width_height(
			data->enemy[i].enemy, data->mlx) == 0)
	{
		ft_printf("Error\nFalha ao carregar textura %s do inimigo n %d\n",
			data->enemy[i].enemy.path, i);
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
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		free(data->enemy);
		exit(1);
	}
}

void	ft_init_box(t_game *data)
{
	data->box.img = mlx_new_image(data->mlx, data->win.width, data->win.height);
	if (!data->box.img)
	{
		ft_printf("Error\nFalha ao criar a caixa\n");
		free_map(&data->map);
		mlx_destroy_window(data->mlx, data->win.win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(1);
	}
	data->box.data = mlx_get_data_addr(data->box.img,
			&data->box.bpp, &data->box.size_line,
			&data->box.endian);
}
