/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_read_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 21:03:35 by malourei          #+#    #+#             */
/*   Updated: 2024/08/29 22:37:28 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	empty_file(int fd)
{
	ft_printf("Error\nMapa vazio. :)\n");
	close(fd);
	exit(1);
}

static int	map_height(char *c)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(c, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nAo abrir o mapa.\n");
		exit(1);
	}
	while (1)
	{
		line = get_next_line(fd);
		i++;
		if (line == NULL && i == 1)
			empty_file(fd);
		else if (line == NULL)
			break ;
		free(line);
	}
	close(fd);
	return (i);
}

void	read_map(t_map *map)
{
	int		i;
	int		fd;

	fd = open(map->path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nAo ler o mapa.\n");
		exit(1);
	}
	map->map = malloc(sizeof(char *) * (map_height(map->path) + 1));
	if (!map->map)
	{
		ft_printf("Error\nAo alocar memoria para o mapa.\n");
		exit(1);
	}
	i = -1;
	while (1)
	{
		map->map[++i] = get_next_line(fd);
		if (map->map[i] == NULL)
			break ;
	}
	close(fd);
	map->height = i * 64;
	map->width = ((int)ft_strlen(map->map[0]) - 1) * 64;
}
