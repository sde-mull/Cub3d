/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:26:16 by sde-mull          #+#    #+#             */
/*   Updated: 2023/04/02 18:42:15 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void draw_front(t_win *win)
{
	int count;
	double x;
	double y;

	x = obj()->player.x1;
	y = obj()->player.y1;
	while (x > 0 && y > 0 && x < data()->map.dx && data()->map.dy)
	{
		// count = 0;
		// while (count < ICON_X)
		// {
			my_mlx_pixel_put(&win->map, x * ICON_X - count, y * ICON_Y + 4, 0xFFFFFF);
		// 	count++;
		// }
		x--;
	}
}

void draw_image(t_win *win)
{
	paint_map(win);
	draw_player(win, &win->img[2], obj()->player.x1 * ICON_X, obj()->player.y1 * ICON_Y);
	draw_front(win);
	mlx_put_image_to_window(win->mlx, win->mlx_win, \
				win->map.mlx_img, 0, 0);
}