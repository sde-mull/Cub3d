/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:26:16 by sde-mull          #+#    #+#             */
/*   Updated: 2023/04/19 18:38:00 by sde-mull         ###   ########.fr       */
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

void print_texture(int screen, int i, double paint, int x_scale)
{
    unsigned int dst;

    dst = my_mlx_get_pixel(&canvas()->walls[obj()->W_flags], x_scale, paint);
    my_mlx_pixel_put(&canvas()->game, screen, i, dst);
}

void draw_screen(t_engine *eng, int *screen, int ray, int index)
{
	int i;
	int r_row;
	int wall;
	double rate;
	double paint_y;
	double x_scale;
    eng->size = WIN_Y / (eng->dist);
    eng->roof = (WIN_Y - eng->size) / 2;
    eng->floor = eng->roof + eng->size;

    i = 0;
    r_row = WIN_X / ray;
	wall = eng->floor - eng->roof;
	rate = (double)canvas()->walls[obj()->W_flags].imgy / (double)wall;
	paint_y = 0;
	x_scale = (double)canvas()->walls[obj()->W_flags].imgx * obj()->W_xtexture;
    while (i < WIN_Y)
    {
		while (eng->roof < 0 && ++eng->roof) {
			paint_y += rate;
		}
        if (i < eng->roof)
            my_mlx_pixel_put(&canvas()->game, *screen, i, 0x1c8da6);
        else if (i > eng->roof && i < eng->floor)
		{
           print_texture(*screen, i, paint_y, x_scale);
		   paint_y += rate;
		}
        else
            my_mlx_pixel_put(&canvas()->game, *screen, i, 0x292826);
        i++;
    }
    *screen += r_row;
}

void	draw_full_map(t_win *win)
{
	int y;
	int x;
	unsigned int dst;

	y = 0;
	while (y < data()->map.my)
	{
		x = 0;
		while (x < data()->map.mx)
		{
			dst = my_mlx_get_pixel(&canvas()->p_map, x, y);
			if (dst != 0)			
				my_mlx_pixel_put(&canvas()->game, x, y, (int)dst);
			x++;
		}
		y++;
	}
}

void	draw_mini_map(t_win *win)
{
	int x;
	int y;
	int mx;
	int my;
	int sy;
	int sx;
	unsigned int dst;

	sx = (obj()->player.x1 - 4) * 32;
	y = (obj()->player.y1 - 4) * 32;
	sy = y;
	mx = (obj()->player.x1 + 4) * 32;
	my = (obj()->player.y1 + 4) * 32;
	while (y < my)
	{
		x = (obj()->player.x1 - 4) * 32;
		while (x < mx)
		{
			if (x < data()->map.mx && y < data()->map.my && x > 0 && y > 0)
			{
				dst = my_mlx_get_pixel(&canvas()->p_map, x, y);			
				my_mlx_pixel_put(&canvas()->game, x - sx, y - sy, (int)dst);
			}
			x++;
		}
		y++;
	}
}