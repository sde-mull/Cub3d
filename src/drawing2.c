/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:26:16 by sde-mull          #+#    #+#             */
/*   Updated: 2023/04/10 18:46:18 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void draw_front(t_win *win, double angle)
{
	int count;
	double rx;
	double ry;
	double x;
	double y;
	double gx;
	double gy;
	double		size;

	x = obj()->player.x1;
	y = obj()->player.y1;
	rx = 1 * cos(angle);
	ry = 1 * sin(angle);
	gx = x + rx;
	gy = y - ry;
	size = 0;
	while (gx > 0 && gy > 0 && data()->map.arr[(int)gy][(int)gx] != '1')
	{
		my_mlx_pixel_put(&canvas()->p_map, gx * ICON_X, gy * ICON_Y, 0xFFFFFF);
		gx += rx;
		gy -= ry;
		size = size + rx + ry;
	}
}

void draw_image(t_win *win)
{
	paint_map(win);
	draw_player(win, &canvas()->map[2], obj()->player.x1 * ICON_X, obj()->player.y1 * ICON_Y);
	draw_front(win, obj()->player.angle);
	mlx_put_image_to_window(win->mlx, win->mlx_win, \
	canvas()->p_map.mlx_img, 0, 0);
}