/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_camara_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 23:34:59 by malourei          #+#    #+#             */
/*   Updated: 2024/08/10 19:00:18 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_init_camara(t_game *data)
{
	if (data->win.height % 64 != 0)
		data->win.height = 64 * (int)(data->win.height / 64);
	if (data->win.width % 64 != 0)
		data->win.width = 64 * (int)(data->win.width / 64);
	data->camara.x = data->p_coor.x - (data->win.width / 2);
	data->camara.y = data->p_coor.y - (data->win.height / 2);
	if (data->camara.x < 0)
		data->camara.x = 0;
	if (data->camara.y < 0)
		data->camara.y = 0;
	if (data->camara.x + data->win.width > data->map.width)
		data->camara.x = data->map.width - data->win.width;
	if (data->camara.y + data->win.height > data->map.height)
		data->camara.y = data->map.height - data->win.height;
}
