/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 00:08:35 by sde-mull          #+#    #+#             */
/*   Updated: 2023/06/13 18:36:52 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	move(double x, double y)
{
	double	x2;
	double	y2;
	double	x1;
	double	y1;

	x1 = 0;
	y1 = 0;
	x += (obj()->player.x1);
	y += (obj()->player.y1);
	x2 = x1 + x;
	y2 = y1 + y;
	if (data()->map.arr[(unsigned int)y2][(unsigned int)x2] == '1' ||
		data()->map.arr[(unsigned int)(y2 + 0.1)][(unsigned int)x2] == '1' ||
		data()->map.arr[(unsigned int)y2][(unsigned int)(x2 + 0.1)] == '1')
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
	data()->map.mx = (data()->map.dx + 1) * ICON_X;
	data()->map.my = (data()->map.dy + 1) * ICON_Y;
	init_images(&win);
	mlx_hook(win.mlx_win, 17, 0, exit_game, &win);
	mlx_hook(win.mlx_win, 2, 1L << 0, scan_key, &win);
	mlx_hook(win.mlx_win, 3, 1L << 1, scan_key_release, &win);
	mlx_loop_hook(win.mlx, &render, &win);
	mlx_loop(win.mlx);
	free_win(&win);
	return (true);
}

void	print_map(char **arr)
{
	int	index;

	index = -1;
	while (arr[++index])
		printf("ind:%d %s\n", index, arr[index]);
	printf("\n");
	printf("North:%s\nSouth:%s\nEast:%s\nWest:%s\n", \
	data()->textures[0], data()->textures[1], \
	data()->textures[2], data()->textures[3]);
	printf("F:%d;\n", data()->floor);
	printf("C:%d;\n", data()->roof);
}
