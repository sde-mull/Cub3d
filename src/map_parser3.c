/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:03:32 by pcoimbra          #+#    #+#             */
/*   Updated: 2023/05/29 18:45:24 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

t_player	get_player(t_map *map)
{
	int			x;
	int			y;
	t_player	objs;

	y = 0;
	while (y < map->dy && map->arr[y])
	{
		x = 0;
		while (x < map->dx && map->arr[y][x])
		{
			if (map->arr[y][x] == 'N' || map->arr[y][x] == 'W' ||
				map->arr[y][x] == 'E' || map->arr[y][x] == 'S')
				{
					get_direction(&objs, x, y, map);
					get_angle(&objs);
					break;
				}
			x++;
		}
		y++;
	}
	objs.player_x += 0.5;
	objs.player_y += 0.5;
	return (objs);
}

int	read_info(int fd, t_map *map)
{
	if (fd < 0)
		return (printf("\033[0;31mError:\033[0m %s\n", strerror(errno)));
	get_dimensions(map);
	obj()->player = get_player(&data()->map);
	return (0);
}

int	check_coords(int x, int y)
{
	if (y == 0 || x == 0 || (int)ft_strlen(data()->map.arr[y - 1]) <= x + 1
		|| !data()->map.arr[y - 1][x] || data()->map.arr[y - 1][x] == ' ' ||
	!data()->map.arr[y - 1][x + 1] || data()->map.arr[y - 1][x + 1] == ' ' ||
	(int)ft_strlen(data()->map.arr[y + 1]) <= x + 1 ||
	!data()->map.arr[y][x + 1] || data()->map.arr[y][x + 1] == ' ' ||
	!data()->map.arr[y + 1][x + 1] || data()->map.arr[y + 1][x + 1] == ' ' ||
	!data()->map.arr[y + 1][x] || data()->map.arr[y + 1][x] == ' ' ||
	!data()->map.arr[y + 1][x - 1] || data()->map.arr[y + 1][x - 1] == ' ' ||
	!data()->map.arr[y][x - 1] || data()->map.arr[y][x - 1] == ' ' ||
	!data()->map.arr[y - 1][x - 1] || data()->map.arr[y - 1][x - 1] == ' ')
	{
		printf ("le esta a entrar nesse 1\n");
		return (1);
	}
	return (0);
}

int	check_map(void)
{
	int	y;
	int	x;

	y = 0;
	while (data()->map.arr[y])
	{
		x = 0;
		while (data()->map.arr[y][x])
		{
			if ((data()->map.arr[y][x] == '0' && \
				data()->map.arr[y][x] == 'N' && \
				data()->map.arr[y][x] == 'S' && \
				data()->map.arr[y][x] == 'E' && \
				data()->map.arr[y][x] == 'W') && (check_coords(x,y)))
			{
				printf("Error\nMap is not set up properly.\nStopped at:");
				printf("\n%c,\n", data()->map.arr[y][x]);
				printf(" [%d][%d]\n", y, x);
				free_array(data()->map.arr);
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}