/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:02:49 by pcoimbra          #+#    #+#             */
/*   Updated: 2023/05/30 17:08:06 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	map_parser_error(int y, int x)
{
	printf("Error\nMap is not set up properly.\nStopped at:");
	printf("\n%c,%d, %d\n", data()->map.arr[y][x], y, x);
	free_array(data()->map.arr);
	return (1);
}

int	zeros(int x, int y)
{
	if (!(data()->map.arr[y - 1] || data()->map.arr[y + 1] || \
		data()->map.arr[y][x - 1] || data()->map.arr[y][x + 1]) || \
		!(data()->map.arr[y - 1][x] == '1' || data()->map.arr[y - 1][x] == \
		'0'|| data()->map.arr[y - 1][x] == 'E' ||data()->map.arr[y - 1][x] == \
		'W' || data()->map.arr[y - 1][x] == 'N' || data()->map.arr[y - 1][x] \
		== 'S') || \
		!(data()->map.arr[y + 1][x] == '1' || data()->map.arr[y + 1][x] == \
		'0'|| data()->map.arr[y + 1][x] == 'E' ||data()->map.arr[y + 1][x] == \
		'W' || data()->map.arr[y + 1][x] == 'N' || data()->map.arr[y + 1][x] \
		== 'S') ||\
		!(data()->map.arr[y][x - 1] == '1' || data()->map.arr[y][x - 1] == \
		'0'|| data()->map.arr[y][x - 1] == 'E' ||data()->map.arr[y][x - 1] == \
		'W' || data()->map.arr[y][x - 1] == 'N' || data()->map.arr[y][x - 1] \
		== 'S') ||\
		!(data()->map.arr[y][x + 1] == '1' || data()->map.arr[y][x + 1] == \
		'0'|| data()->map.arr[y][x + 1] == 'E' ||data()->map.arr[y][x + 1] == \
		'W' || data()->map.arr[y][x + 1] == 'N' || data()->map.arr[y][x + 1] \
		== 'S'))
			return (1);
	return (0);
}
