/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:26:16 by sde-mull          #+#    #+#             */
/*   Updated: 2023/06/11 18:36:58 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	draw_front(t_win *win, double angle)
{
	t_engine	eng;
	int			i;

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
		my_mlx_pixel_put(&canvas()->p_map, eng.gx * ICON_X + 3, \
			eng.gy * ICON_Y + 3, 0xFFFFFF);
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

void	print_texture(int screen, int i, double paint, int x_scale)
{
	unsigned int	dst;

	dst = my_mlx_get_pixel(&canvas()->walls[obj()->w_flags], x_scale, paint);
	my_mlx_pixel_put(&canvas()->game, screen, i, dst);
}

void	draw_screen(t_engine *eng, int *screen, int ray, int index)
{
	t_extra	ex;

	eng->size = WIN_Y / (eng->dist);
	eng->roof = (WIN_Y - eng->size) / 2;
	eng->floor = eng->roof + eng->size;
	ex.i = 0;
	ex.r_row = WIN_X / ray;
	ex.wall = eng->floor - eng->roof;
	ex.rate = (double)canvas()->walls[obj()->w_flags].imgy / (double)ex.wall;
	ex.paint_y = 0;
	ex.x_scale = (double)canvas()->walls[obj()->w_flags].imgx * \
		obj()->w_xtexture;
	draw_screen2(eng, &ex, screen);
	*screen += ex.r_row;
}

void	draw_screen2(t_engine *eng, t_extra *ex, int *screen)
{
	while (ex->i < WIN_Y)
	{
		while (eng->roof < 0 && ++eng->roof)
			ex->paint_y += ex->rate;
		if (ex->i <= eng->roof)
			my_mlx_pixel_put(&canvas()->game, *screen, ex->i, data()->roof);
		else if (ex->i > eng->roof && ex->i < eng->floor)
		{
			print_texture(*screen, ex->i, ex->paint_y, ex->x_scale);
			ex->paint_y += ex->rate;
		}
		else
			my_mlx_pixel_put(&canvas()->game, *screen, ex->i, data()->floor);
		ex->i++;
	}
}
