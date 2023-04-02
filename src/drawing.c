/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:24:11 by sde-mull          #+#    #+#             */
/*   Updated: 2023/04/02 18:42:21 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

unsigned int	my_mlx_get_pixel(t_img *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	return(*(unsigned int*)dst);
}

void	draw_map(t_win *win, t_img *img, int countx, int county)
{
	int x;
	int y;
	unsigned int dst;

	y = 0;
	while (y < ICON_Y)
	{
		x = 0;
		while (x < ICON_X)
		{
			dst = my_mlx_get_pixel(img, x, y);
			my_mlx_pixel_put(&win->map, x + countx, y + county, (int)dst);
			x++;
		}
		y++;
	}
}

void	paint_map(t_win *win)
{
	int x;
	int y;

	y = 0;
	while (y < data()->map.dy && data()->map.arr[y])
	{
		x = 0;
		while (x < data()->map.dx && data()->map.arr[y][x])
		{
			if (data()->map.arr[y][x] == '1')
				draw_map(win, &win->img[0], x * ICON_X, y * ICON_Y);
			if (data()->map.arr[y][x] == 'N' || data()->map.arr[y][x] == '0')
				draw_map(win, &win->img[1], x * ICON_X, y * ICON_Y);
			x++;
		}
		y++;
	}
}

void	draw_player(t_win *win, t_img *img, int countx, int county)
{
	int 			x;
	int 			y;
	unsigned int 	dst;
	unsigned int 	cmp;
	
	y = 0;
	cmp = my_mlx_get_pixel(&win->img[2], 5, 5);
	while (y < ICON_Y)
	{
		x = 0;
		while (x < ICON_X / 4)
		{
			dst = my_mlx_get_pixel(img, x, y);
			if (cmp == dst)
			{
				my_mlx_pixel_put(&win->map, x + countx, y + county, (int)dst);
			}
			x++;
		}
		y++;
	}
}
