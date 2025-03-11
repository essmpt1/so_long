/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 22:12:43 by malourei          #+#    #+#             */
/*   Updated: 2024/09/10 18:25:20 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>

# define KEY_ESQ 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

typedef struct s_texture
{
	void	*img;
	char	*data;
	char	path[21];
	int		wid;
	int		hei;
	int		x;
	int		y;
	int		bpp;
	int		size_line;
	int		endian;
}	t_texture;

typedef struct s_window
{
	void	*window;
	int		width;
	int		height;
}	t_window;

typedef struct s_map
{
	char	**map;
	char	*path;
	int		width;
	int		height;
	int		n_players;
	int		n_coll;
	int		n_exits;
}	t_map;

typedef struct s_coor
{
	int	x;
	int	y;
}	t_coor;

typedef struct s_game
{
	void			*mlx;
	t_window		window;
	long			moves;
	long			collected;
	t_texture		player;
	t_texture		wall;
	t_texture		floor;
	t_texture		coll;
	t_texture		exit;
	t_map			map;
	t_coor			camara;
	t_coor			ecra;
}	t_game;

void		ft_putnbr_mlx(t_game *data, long moves, int *x, int y);
void		put_img_to_img(t_texture dst, t_texture src);
void		put_pixel_img(t_texture img, int x, int y, int color);
int			validate_map(t_map *map);
void		draw_game(t_game *data);
int			handle_close(t_game *data);
void		free_map(t_map *map);
void		close_call(t_game *data);
void		textures_coordenates(t_game *data);
int			handle_key(int key, t_game *data);
void		read_map(t_map *map);
void		ft_init_wall(t_game *data);
void		ft_init_floor(t_game *data);
void		ft_init_exit(t_game *data);
void		ft_init_collectable(t_game *data);
void		ft_init_player(t_game *data);
int			validate_reachability(t_map *map_data, int player_x, int player_y);
void		windows_size(t_game *data);
void		ft_init_camara(t_game *data);
void		collect_collectable(t_game *data);
t_texture	ft_validate_player_coor(t_map *map);
int			textures_width_height(t_texture tex, void *mlx);

#endif
