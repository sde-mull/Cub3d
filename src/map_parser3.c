/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:03:32 by pcoimbra          #+#    #+#             */
/*   Updated: 2023/06/13 15:31:19 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	check_alphanumber(char **rgb)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 3)
	{
		j = 0;
		while (rgb[i][j])
		{
			if ((rgb[i][j] > 57 || rgb[i][j] < 48) && rgb[i][j] != ' ')
				return (1);
			j++;
		}
	}
	return (0);
}

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
				break ;
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
			if ((data()->map.arr[y][x] != '0' && data()->map.arr[y][x] != 'N' \
				&& data()->map.arr[y][x] != 'S' && data()->map.arr[y][x] != 'E'\
				&& data()->map.arr[y][x] != 'W' && data()->map.arr[y][x] != '1' \
				&& data()->map.arr[y][x] != ' '))
			{
				free_array(data()->map.arr);
				return (1);
			}
			else if (data()->map.arr[y][x] == '0')
				if (zeros(x, y))
					return (1);
			x++;
		}
		y++;
	}
	return (0);
}
