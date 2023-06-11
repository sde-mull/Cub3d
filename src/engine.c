/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:43:31 by sde-mull          #+#    #+#             */
/*   Updated: 2023/06/11 19:09:57 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	rays_size(t_win *win, double angle, int *screen, int index)
{
	t_engine	eng;
	double		x;
	double		y;

	x = 0;
	y = 0;
	eng.rx = 0.005 * cos(angle);
	eng.ry = 0.005 * sin(angle);
	eng.x = obj()->player.x1;
	eng.y = obj()->player.y1;
	eng.gx = eng.x + eng.rx;
	eng.gy = eng.y - eng.ry;
	rays_size2(&eng, &y, &x);
	eng.dx = eng.gx - eng.x;
	eng.dy = eng.gy - eng.y;
	eng.dist = sqrt(eng.dx * eng.dx + eng.dy * eng.dy);
	eng.angle_diff = fabs(angle - obj()->player.angle);
	eng.dist *= cos(eng.angle_diff);
	draw_screen(&eng, screen, 720, index);
}

void	rays_size2(t_engine *eng, double *y, double *x)
{
	while (eng->gx > 0 && eng->gy > 0 && \
		data()->map.arr[(int)eng->gy][(int)eng->gx] != '1')
	{
		eng->gx += eng->rx;
		if (data()->map.arr[(int)eng->gy][(int)eng->gx] == '1')
		{
			*y = eng->gy - (int)eng->gy;
			obj()->w_flags = 0;
			obj()->w_xtexture = *y;
			if (eng->rx < 0)
				obj()->w_flags = 1;
			break ;
		}
		eng->gy -= eng->ry;
		if (data()->map.arr[(int)eng->gy][(int)eng->gx] == '1')
		{
			*x = eng->gx - (int)eng->gx;
			obj()->w_flags = 2;
			obj()->w_xtexture = *x;
			if (eng->ry < 0)
				obj()->w_flags = 3;
			break ;
		}
	}
}

void	rays(t_win *win)
{
	double	angle_diff;
	double	max_angle;
	double	sum;
	int		i;
	int		screen;

	i = 0;
	screen = 0;
	angle_diff = obj()->player.angle + (PI / 6);
	sum = PI / 3800;
	while (i < 1281)
	{
		rays_size(win, angle_diff, &screen, i);
		angle_diff -= sum;
		i++;
	}
}

void	get_fps(void)
{
	struct timeval	time;
	static int		frames;
	static int		second;

	gettimeofday(&time, NULL);
	if (second != time.tv_sec)
	{
		second = time.tv_sec;
		printf("FPS: %d\n", frames);
		frames = 0;
	}
	else
		frames++;
}

void	get_velocity(void)
{
	obj()->vwx = 0.05 * cos(obj()->player.angle);
	obj()->vwy = 0.05 * sin(obj()->player.angle);
	obj()->vdx = 0.05 * cos(obj()->player.angle - (PI / 2));
	obj()->vdy = 0.05 * sin(obj()->player.angle - (PI / 2));
}
