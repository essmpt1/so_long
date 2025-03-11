/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_kill_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:35:08 by malourei          #+#    #+#             */
/*   Updated: 2024/07/25 16:35:08 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	change_enemy_img(t_game *game, t_coor coor, int flag)
{
	if (game->map.map[coor.y / 64][coor.x / 64] != 'E' && flag)
		game->map.map[coor.y / 64][coor.x / 64] = '0';
	else
	{
		game->map.map[coor.y / 64][coor.x / 64] = 'R';
	}
}

static int	valid_move(t_game *game, t_coor coor)
{
	if (coor.x >= 0 && coor.x < game->map.width && coor.y >= 0
		&& coor.y < game->map.height
		&& game->map.map[coor.y / 64][coor.x / 64] != '1'
		&& game->map.map[coor.y / 64][coor.x / 64] != 'C'
		&& game->map.map[coor.y / 64][coor.x / 64] != 'E')
		return (1);
	return (0);
}

static void	enemy_direction(t_game *game, int k)
{
	t_coor	coor;

	if (game->frame_counter % game->enemy_move_delay == 0)
	{
		change_enemy_img(game, game->enemy[k].coor, 1);
		game->enemy[k].direction = rand() % 4;
		coor.x = game->enemy[k].coor.x;
		coor.y = game->enemy[k].coor.y;
		if (game->enemy[k].direction == 0)
			coor.x += 64;
		else if (game->enemy[k].direction == 1)
			coor.x -= 64;
		else if (game->enemy[k].direction == 2)
			coor.y += 64;
		else if (game->enemy[k].direction == 3)
			coor.y -= 64;
		if (valid_move(game, coor))
		{
			game->enemy[k].coor.x = coor.x;
			game->enemy[k].coor.y = coor.y;
		}
		change_enemy_img(game, game->enemy[k].coor, 0);
	}
}

void	update_enemies(t_game *game)
{
	int	k;

	k = 0;
	while (k < game->map.n_enemies)
	{
		enemy_direction(game, k);
		if (game->enemy[k].coor.x == game->p_coor.x
			&& game->enemy[k].coor.y == game->p_coor.y)
			ft_player_dead(game);
		k++;
	}
}
