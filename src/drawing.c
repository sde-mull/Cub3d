/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:24:11 by sde-mull          #+#    #+#             */
/*   Updated: 2023/06/11 18:14:14 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

unsigned int	my_mlx_get_pixel(t_img *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	return (*(unsigned int *)dst);
}

void	draw_map(t_img *map, t_img *img, int countx, int county)
{
	int				x;
	int				y;
	unsigned int	dst;

	y = 0;
	while (y < ICON_Y)
	{
		x = 0;
		while (x < ICON_X)
		{
			dst = my_mlx_get_pixel(img, x, y);
			my_mlx_pixel_put(map, x + countx, y + county, (int)dst);
			x++;
		}
		y++;
	}
}

int	check_dir(int x, int y)
{
	if (data()->map.arr[y][x] == 'N' || data()->map.arr[y][x] == 'S' ||
		data()->map.arr[y][x] == 'E' || data()->map.arr[y][x] == 'W')
		return (1);
	return (0);
}

void	paint_map(t_win *win)
{
	int	x;
	int	y;

	y = 0;
	while (y < data()->map.dy && data()->map.arr[y])
	{
		x = 0;
		while (x < data()->map.dx && data()->map.arr[y][x])
		{
			if (data()->map.arr[y][x] == '1')
				draw_map(&canvas()->p_map, &canvas()->map[0], \
					(x * ICON_X), (y * ICON_Y));
			if (check_dir(x, y) || data()->map.arr[y][x] == '0')
				draw_map(&canvas()->p_map, &canvas()->map[1], (x * ICON_X), \
					(y * ICON_Y));
			x++;
		}
		y++;
	}
}
