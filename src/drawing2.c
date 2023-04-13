/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:26:16 by sde-mull          #+#    #+#             */
/*   Updated: 2023/04/12 22:46:35 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	draw_front(t_win *win, double angle)
{
	t_engine	eng;
	int 		i;

	eng.x = obj()->player.x1;
	eng.y = obj()->player.y1;
	eng.rx = 0.01 * cos(angle);
	eng.ry = 0.01 * sin(angle);
	eng.gx = eng.x + eng.rx;
	eng.gy = eng.y - eng.ry;
	i = 0;
	while (eng.gx > 0 && eng.gy > 0 && \
	data()->map.arr[(int)eng.gy][(int)eng.gx] != '1' && i < 100)
	{
		my_mlx_pixel_put(&canvas()->p_map, eng.gx * ICON_X + 3, eng.gy * ICON_Y + 3,
			0xFFFFFF);
		eng.gx += eng.rx;
		eng.gy -= eng.ry;
		i++;
	}
}

void	draw_image(t_win *win)
{
	paint_map(win);
	draw_player(win, &canvas()->map[2], obj()->player.x1 * ICON_X,
		obj()->player.y1 * ICON_Y);
	draw_front(win, obj()->player.angle - PI / 8);
	draw_front(win, obj()->player.angle + PI / 8);
}
