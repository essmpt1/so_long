/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_help_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 23:04:19 by malourei          #+#    #+#             */
/*   Updated: 2024/09/01 00:47:16 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_coor	ft_validate_player_coor(t_map *map)
{
	t_coor	coor;
	int		i;
	int		j;

	i = 0;
	while (i < map->height / 64)
	{
		j = 0;
		while (j < map->width / 64)
		{
			if (map->map[i][j] == 'P')
			{
				coor.x = i;
				coor.y = j;
			}
			j++;
		}
		i++;
	}
	return (coor);
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
				data->p_coor.x = j * data->player.wid;
				data->p_coor.y = i * data->player.hei;
			}
			if (data->map.map[i][j] == 'C')
				data->collected++;
			if (data->map.map[i][j] == 'R')
				data->map.n_enemies++;
			j++;
		}
		i++;
	}
}

void	exit_coordenates(t_game *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < (data->map.height / 64))
	{
		j = 0;
		while (j <= (data->map.width / 64))
		{
			if (data->map.map[i][j] == 'E')
			{
				data->exit_coor.x = j * data->exit.wid;
				data->exit_coor.y = i * data->exit.hei;
			}
			j++;
		}
		i++;
	}
}

void	collect_collectable(t_game *data)
{
	if (data->map.map[data->p_coor.y / 64][data->p_coor.x / 64] == 'C')
	{
		data->map.map[data->p_coor.y / 64][data->p_coor.x / 64] = '0';
		data->map.n_coll++;
		ft_printf("Collect: %d / %d\n", data->map.n_coll, data->collected);
	}
	if (data->collected == data->map.n_coll)
		data->map.map[data->exit_coor.y / 64][data->exit_coor.x / 64] = 'E';
	if (data->map.map[data->p_coor.y / 64][data->p_coor.x / 64] == 'E'
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
