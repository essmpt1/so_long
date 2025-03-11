/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_camara.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 23:34:59 by malourei          #+#    #+#             */
/*   Updated: 2024/08/31 21:56:17 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_camara(t_game *data)
{
	if (data->window.height % 64 != 0)
		data->window.height = 64 * (int)(data->window.height / 64);
	if (data->window.width % 64 != 0)
		data->window.width = 64 * (int)(data->window.width / 64);
	data->camara.x = data->player.x - (data->window.width / 2);
	data->camara.y = data->player.y - (data->window.height / 2);
	if (data->camara.x < 0)
		data->camara.x = 0;
	if (data->camara.y < 0)
		data->camara.y = 0;
	if (data->camara.x + data->window.width > data->map.width)
		data->camara.x = data->map.width - data->window.width;
	if (data->camara.y + data->window.height > data->map.height)
		data->camara.y = data->map.height - data->window.height;
}
