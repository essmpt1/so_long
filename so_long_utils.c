/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 22:52:07 by malourei          #+#    #+#             */
/*   Updated: 2024/08/10 00:49:59 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putnbr_mlx(t_game *data, long number, int *x, int y)
{
	char	str[2];

	if (number < 0)
	{
		*x += 7;
		number = -number;
		mlx_string_put(data->mlx, data->window.window, *x, y, 0xFF0000, "-");
	}
	if (number > 9)
		ft_putnbr_mlx(data, number / 10, x, y);
	*x += 7;
	str[0] = ((number % 10) + '0');
	str[1] = '\0';
	mlx_string_put(data->mlx, data->window.window, *x, y, 0xFF0000, str);
}

unsigned int	get_pixel_img(t_texture img, int x, int y)
{
	char	*dst;

	dst = img.data + (y * img.size_line + x * (img.bpp / 8));
	return (*(unsigned int *)dst);
}

void	put_pixel_img(t_texture img, int x, int y, int color)
{
	char	*dst;

	if (color == (int)0xFF000000)
		return ;
	if (x >= 0 && y >= 0 && x < img.wid && y < img.hei)
	{
		dst = img.data + (y * img.size_line + x * (img.bpp / 8));
		*(unsigned int *)dst = color;
	}
}

void	put_img_to_img(t_texture dst, t_texture src)
{
	int				i;
	int				j;
	unsigned int	color_src;
	unsigned int	color_dst;

	i = 0;
	while (i < src.hei)
	{
		j = 0;
		while (j < src.wid)
		{
			color_src = get_pixel_img(src, j, i);
			if (color_src != 0xFF000000)
			{
				color_dst = get_pixel_img(dst, j, i);
				if (color_dst != 0xFF000000)
					put_pixel_img(dst, j, i, color_dst);
				else
					put_pixel_img(dst, j, i, color_src);
			}
			j++;
		}
		i++;
	}
}

void	windows_size(t_game *data)
{
	mlx_get_screen_size(data->mlx, &data->ecra.x, &data->ecra.y);
	data->window.height = data->map.height;
	data->window.width = data->map.width;
	if (data->map.width > data->ecra.x && data->map.height > data->ecra.y)
	{
		data->window.width = data->ecra.x;
		data->window.height = data->ecra.y;
	}
	else if (data->map.width < data->ecra.x && data->map.height > data->ecra.y)
		data->window.height = data->ecra.y;
	else if (data->map.width > data->ecra.x && data->map.height < data->ecra.y)
		data->window.width = data->ecra.x;
	data->window.window = mlx_new_window(data->mlx, data->window.width,
			data->window.height, "Macho");
	if (!data->window.window)
	{
		free(data->mlx);
		exit(1);
	}
}
