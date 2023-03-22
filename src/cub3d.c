/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:19:54 by sde-mull          #+#    #+#             */
/*   Updated: 2023/03/22 21:08:01 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


void free_win(t_win *win)
{
	if (win)
	{
		mlx_destroy_window(win->mlx, win->mlx_win);
		mlx_destroy_display(win->mlx);
		free(win->mlx);
	}
	if (data()->map.arr)
		free_all(&data()->map);
	exit(0);
}

int	exit_game(t_win *win)
{
	if (win)
		free_win(win);
	return (0);
}

void	init_struct(t_win *win)
{
	win->key.w = 0;
	win->key.a = 0;
	win->key.d = 0;
	win->key.s = 0;
}

int	scan_key(int keycode, t_win *win)
{
	init_struct(win);
	if (keycode == UP)
		win->key.w = 1;
	if (keycode == LEFT)
		win->key.a = 1;
	if (keycode == RIGHT)
		win->key.d = 1;
	if (keycode == DOWN)
		win->key.s = 1;
	return (0);
}

int	scan_key_release(int keycode, t_win *win)
{
	if (keycode == UP)
		win->key.w = 0;
	if (keycode == LEFT)
		win->key.a = 0;
	if (keycode == RIGHT)
		win->key.d = 0;
	if (keycode == DOWN)
		win->key.s = 0;
	if (keycode == CLOSE)
		exit_game(win);
	return (0);
}

bool	init_window(t_win *win)
{
	win->mlx = mlx_init();
	if (win->mlx == NULL)
		return (WIN_ERROR);
	win->mlx_win = mlx_new_window(win->mlx_win, WIN_X, WIN_Y, "Cub3d");
	if (win->mlx == NULL)
	{
		free(win->mlx);
		return (WIN_ERROR);
	}
	return (true);
}

int		render(t_win *win)
{
	return (0);
}

bool	init_game(void)
{
	t_win	win;
	
	if (!init_window(&win))
		return (false);
	mlx_hook(win.mlx_win , 17, 0, exit_game, &win);
	mlx_hook(win.mlx_win, 2, 1L << 0, scan_key, &win);
	mlx_hook(win.mlx_win, 3, 1L << 1, scan_key_release, &win);
	mlx_loop_hook(win.mlx, &render, &win);
	mlx_loop(win.mlx);
	free_win(&win);
	return (true);
}

int main(int argc, char *argv[])
{
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