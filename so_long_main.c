/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 01:08:49 by malourei          #+#    #+#             */
/*   Updated: 2024/09/04 19:13:48 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_validate_map_ber(char *path)
{
	char	*ber;
	int		n;

	ber = ft_strchr2(path, 46);
	if (ft_strlen(ber) != 4)
		return (0);
	n = ft_strncmp(ber, ".ber", 4);
	if (n == 0)
		return (1);
	return (0);
}

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
	data->player.x = 0;
	data->player.y = 0;
	ft_strcpy(data->player.path, "textures/mew.xpm");
	ft_strcpy(data->coll.path, "textures/pokeball.xpm");
	ft_strcpy(data->exit.path, "textures/exit.xpm");
	ft_strcpy(data->wall.path, "textures/tree.xpm");
	ft_strcpy(data->floor.path, "textures/floor.xpm");
	data->moves = 0;
	data->collected = 0;
	data->map.n_coll = 0;
	data->camara.x = 0;
	data->camara.y = 0;
	data->ecra.x = 0;
	data->ecra.y = 0;
}

static void	ft_init_all(t_game *data)
{
	ft_init_values(data);
	ft_init_player(data);
	ft_init_collectable(data);
	ft_init_wall(data);
	ft_init_floor(data);
	ft_init_exit(data);
	textures_coordenates(data);
	ft_init_camara(data);
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
	data.map.path = argv[1];
	ft_validate(&data);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	windows_size(&data);
	ft_init_all(&data);
	draw_game(&data);
	mlx_key_hook(data.window.window, handle_key, &data);
	mlx_hook(data.window.window, 17, 0, handle_close, &data);
	mlx_loop(data.mlx);
	return (0);
}
