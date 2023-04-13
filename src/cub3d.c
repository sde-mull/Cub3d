/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:19:54 by sde-mull          #+#    #+#             */
/*   Updated: 2023/04/12 22:49:52 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void get_velocity(void)
{
	obj()->vwx = 0.05 * cos(obj()->player.angle);
	obj()->vwy = 0.05 * sin(obj()->player.angle);
	obj()->vdx = 0.05 * cos(obj()->player.angle - (PI / 2));
	obj()->vdy = 0.05 * sin(obj()->player.angle - (PI / 2));
}

void check_keys(t_win *win)
{
	get_velocity();
	if (win->key.w == 1)
		move(obj()->vwx, -obj()->vwy);
	if (win->key.s == 1)
		move(-obj()->vwx, obj()->vwy);
	if (win->key.a == 1)
		move(-obj()->vdx, obj()->vdy);
	if (win->key.d == 1)
		move(obj()->vdx, -obj()->vdy);	
	if (win->key.left == 1)
		obj()->player.angle += 0.02;
	if (win->key.right == 1)
		obj()->player.angle -= 0.02;
	if (obj()->player.angle > (obj()->player.save_angle + (2 * PI)))
		obj()->player.angle = obj()->player.save_angle;
	if (obj()->player.angle < 0)
		obj()->player.angle = 2 * PI;
}

void draw_screen(t_engine *eng, int *screen, int ray)
{
    eng->size = WIN_Y / (eng->dist);
    eng->roof = (WIN_Y - eng->size) / 2;
    eng->floor = eng->roof + eng->size;

    int i = 0;
    int r_row = WIN_X / ray;
    while (i < WIN_Y)
    {
        if (i < eng->roof)
            my_mlx_pixel_put(&canvas()->game, *screen, i, 0x00FFFF);
        else if (i > eng->roof && i < eng->floor)
            my_mlx_pixel_put(&canvas()->game, *screen, i, 0xDD22FF);
        else
            my_mlx_pixel_put(&canvas()->game, *screen, i, 0x00aa14);
        i++;
    }
    *screen += r_row;
}

void rays_size(t_win *win, double angle, int ray, int *screen)
{
	t_engine eng;

    eng.rx = 0.01 * cos(angle);
    eng.ry = 0.01 * sin(angle);
    eng.x = obj()->player.x1;
    eng.y = obj()->player.y1;
    eng.gx = eng.x + eng.rx;
    eng.gy = eng.y - eng.ry;
    while (eng.gx > 0 && eng.gy > 0 && data()->map.arr[(int)eng.gy][(int)eng.gx] != '1')
    {
        eng.gx += eng.rx;
        eng.gy -= eng.ry;
    }
    eng.dx = eng.gx - eng.x;
    eng.dy = eng.gy - eng.y;
    eng.dist = sqrt(eng.dx * eng.dx + eng.dy * eng.dy);
    eng.angle_diff = fabs(angle - obj()->player.angle);
    eng.dist *= cos(eng.angle_diff);
	draw_screen(&eng, screen, ray);
}


void rays(t_win *win)
{
	double angle_diff;
	double max_angle;
	double sum;
	int		i;
	int		screen;
	
	i = 0;
	screen = 0;
	angle_diff = obj()->player.angle + (PI / 6);
	sum = PI / 3800;
	while (i < 1281)
	{
		rays_size(win, angle_diff, 720, &screen);
		angle_diff -= sum;
		i++;
	}
}

void get_fps()
{
	struct timeval time;
	static int frames;
	static int second;

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

void	draw_full_map(t_win *win)
{
	int y;
	int x;
	int mx;
	int my;
	unsigned int dst;

	y = 0;
	my = data()->map.dy * ICON_Y;
	mx = data()->map.dx * ICON_X;
	while (y < my)
	{
		x = 0;
		while (x < mx)
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
			if (x < data()->map.dx * 32 && y < data()->map.dy * 32)
			{
				dst = my_mlx_get_pixel(&canvas()->p_map, x, y);			
				my_mlx_pixel_put(&canvas()->game, x - sx, y - sy, (int)dst);
			}
			x++;
		}
		y++;
	}
}

int		render(t_win *win)
{
	get_fps();
	if (win->mlx_win == NULL)
		return (1);
	check_keys(win);
	rays(win);
	draw_image(win);
	if (win->key.m == 1)
		draw_full_map(win);
	else if (win->key.m == 0)
		draw_mini_map(win);
	mlx_put_image_to_window(win->mlx, win->mlx_win, canvas()->game.mlx_img, 0, 0);
	return (0);
}

int main(int argc, char *argv[])
{
	init_obj_val();
	if (check_input(argc - 1, argv[1]))
		return (1);
	if (!init_data_val())
		return (2);
	if (read_info(argv[1], &data()->map))
		return (3);
	if (!init_game())
		return (4);
	if (data()->map.arr)
		free_all(&data()->map);
	return (0);
}