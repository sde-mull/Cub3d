/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 00:08:35 by sde-mull          #+#    #+#             */
/*   Updated: 2023/04/15 23:46:51 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	move(double x, double y)
{
	double x2;
	double y2;
	double x1;
	double y1;

	x1 = 0;
	y1 = 0;
	x += (obj()->player.x1);
	y += (obj()->player.y1);
	x2 = x1 + x;
	y2 = y1 + y;
	if (data()->map.arr[(unsigned int)y2][(unsigned int)x2] == '1')
		return ;
	obj()->player.x1 = x;
	obj()->player.y1 = y;
}

bool	init_window(t_win *win)
{
	win->mlx = mlx_init();
	if (win->mlx == NULL)
		return (WIN_ERROR);
	win->mlx_win = mlx_new_window(win->mlx, WIN_X, WIN_Y, "Cub3d");
	if (win->mlx == NULL)
	{
		return (WIN_ERROR);
	}
	return (true);
}

bool	init_game(void)
{
	static t_win	win;

	if (!init_window(&win))
		return (false);
	obj()->player.x1 = obj()->player.player_x;
	obj()->player.y1 = obj()->player.player_y;
	data()->map.mx = data()->map.dx * ICON_X;
	data()->map.my = data()->map.dy * ICON_Y;
	init_images(&win);
	mlx_hook(win.mlx_win , 17, 0, exit_game, &win);
	mlx_hook(win.mlx_win, 2, 1L << 0, scan_key, &win);
	mlx_hook(win.mlx_win, 3, 1L << 1, scan_key_release, &win);
	mlx_loop_hook(win.mlx, &render, &win);
	mlx_loop(win.mlx);
	return (true);
}