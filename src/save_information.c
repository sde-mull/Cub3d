/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_information.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:21:12 by sde-mull          #+#    #+#             */
/*   Updated: 2023/04/01 19:20:25 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

//saber a posicao do player

t_player	get_player(t_map *map)
{
	int x;
	int y;
	t_player objs;

	y = 0;
	while (y < map->dy && map->arr[y])
	{
		x = 0;
		while (x < map->dx && map->arr[y][x])
		{
			if (map->arr[y][x] == 'N' || map->arr[y][x] == 'W' ||
				map->arr[y][x] == 'E' || map->arr[y][x] == 'S')
				{
					objs.player_y = y;
					objs.player_x = x;
					break;
				}
			x++;
		}
		y++;
	}
	return (objs);
}

// para salvar a informacao que vem antes do mapa

void	save_info(int fd)
{
	char	*str;
	int		index;

	index = -1;
	while (index++ < 3)
		data()->textures[index] = get_next_line(fd);
	data()->textures[index] = NULL;
	free(get_next_line(fd));
	data()->floor = get_next_line(fd);
	data()->roof = get_next_line(fd); // so meti isto aqui para chegar ao mapa
}

int	read_info(char *file, t_map *map)
{
	int fd;
	
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (printf("\033[0;31mError:\033[0m %s\n", strerror(errno)));
	save_info(fd);
	if (!save_map(fd, map))
		return (printf("\033[0;31mError:\033[0m %s\n", strerror(errno)));
	close(fd);
	obj()->player = get_player(&data()->map);
	return (0);
}
