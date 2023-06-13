/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:02:49 by pcoimbra          #+#    #+#             */
/*   Updated: 2023/06/13 19:13:50 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	mix(char *no_nl, char *line, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (line[i] == '\n')
			no_nl[i] = 0;
		else
			no_nl[i] = line[i];
		i++;
	}
}

int	specific_prompt_error(void)
{
	printf("Error\nMap wasnt set up properly\n");
	if (data()->map.arr)
		free_array(data()->map.arr);
	return (1);
}

int	map_parser_error(int y, int x)
{
	printf("Error\nMap is not set up properly.\nStopped at:");
	printf("\n%c,%d, %d\n", data()->map.arr[y][x], y, x);
	free_array(data()->map.arr);
	return (1);
}

int	zeros(int x, int y)
{
	if ((ft_strlen(data()->map.arr[y - 1]) < x) || \
		(ft_strlen(data()->map.arr[y + 1]) < x))
		return (1);
	if (!(data()->map.arr[y - 1] || data()->map.arr[y + 1] || \
		data()->map.arr[y][x - 1] || data()->map.arr[y][x + 1]) || \
		!(data()->map.arr[y - 1][x] == '1' || data()->map.arr[y - 1][x] == \
		'0' || data()->map.arr[y - 1][x] == 'E' || data()->map.arr[y - 1][x] == \
		'W' || data()->map.arr[y - 1][x] == 'N' || data()->map.arr[y - 1][x] \
		== 'S') || \
		!(data()->map.arr[y + 1][x] == '1' || data()->map.arr[y + 1][x] == \
		'0' || data()->map.arr[y + 1][x] == 'E' || data()->map.arr[y + 1][x] == \
		'W' || data()->map.arr[y + 1][x] == 'N' || data()->map.arr[y + 1][x] \
		== 'S') || \
		!(data()->map.arr[y][x - 1] == '1' || data()->map.arr[y][x - 1] == \
		'0' || data()->map.arr[y][x - 1] == 'E' || data()->map.arr[y][x - 1] == \
		'W' || data()->map.arr[y][x - 1] == 'N' || data()->map.arr[y][x - 1] \
		== 'S') || \
		!(data()->map.arr[y][x + 1] == '1' || data()->map.arr[y][x + 1] == \
		'0' || data()->map.arr[y][x + 1] == 'E' || data()->map.arr[y][x + 1] == \
		'W' || data()->map.arr[y][x + 1] == 'N' || data()->map.arr[y][x + 1] \
		== 'S'))
		return (1);
	return (0);
}
