/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 01:08:49 by malourei          #+#    #+#             */
/*   Updated: 2024/09/04 19:21:45 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_validate(t_game *data)
{
	read_map(&data->map);
	if (validate_map(&data->map) == 0)
	{
		ft_printf("Mapa invalido!\n");
		free_map(&data->map);
		exit(1);
	}
}

static void	ft_init_values(t_game *data)
{
	data->p_coor.x = 0;
	data->p_coor.y = 0;
	ft_strcpy(data->player.path, "textures/mew.xpm");
	ft_strcpy(data->coll.path, "textures/pokeball.xpm");
	ft_strcpy(data->exit.path, "textures/exit.xpm");
	ft_strcpy(data->wall.path, "textures/tree.xpm");
	ft_strcpy(data->floor.path, "textures/floor.xpm");
	ft_strcpy(data->player2.path, "textures/mew2.xpm");
	ft_strcpy(data->player3.path, "textures/mew_back.xpm");
	ft_strcpy(data->player4.path, "textures/mew_front.xpm");
	data->moves = 0;
	data->collected = 0;
	data->map.n_coll = 0;
	data->camara.x = 0;
	data->camara.y = 0;
	data->ecra.x = 0;
	data->ecra.y = 0;
	data->frame_counter = 0;
	data->enemy_move_delay = 100;
	data->map.n_enemies = 0;
	data->box.wid = 250;
	data->box.hei = 30;
}

static void	ft_init_all(t_game *data)
{
	ft_init_box(data);
	ft_init_values(data);
	ft_init_player(data);
	ft_init_collectable(data);
	ft_init_wall(data);
	ft_init_floor(data);
	ft_init_exit(data);
	ft_init_player2(data);
	ft_init_player_back(data);
	ft_init_player_front(data);
	textures_coordenates(data);
	exit_coordenates(data);
	start_enemy(data);
	data->curr_play = data->player;
	ft_init_camara(data);
}

static int	game_loop(t_game *data)
{
	data->frame_counter++;
	update_enemies(data);
	draw_game(data);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_game	data;

	if (argc != 2)
	{
		ft_printf("Error\nMuitos parametros!\nUsar: %s <map>\n", argv[0]);
		return (1);
	}
	if (!ft_validate_map_ber(argv[1]))
	{
		ft_printf("Error\nA extensão do mapa não é valido...\n");
		return (1);
	}
	srand(time(NULL));
	data.map.path = argv[1];
	ft_validate(&data);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	windows_size(&data);
	ft_init_all(&data);
	mlx_key_hook(data.win.win, handle_key, &data);
	mlx_loop_hook(data.mlx, game_loop, &data);
	mlx_hook(data.win.win, 17, 0, handle_close, &data);
	mlx_loop(data.mlx);
	return (0);
}
