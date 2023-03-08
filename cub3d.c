/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:59:21 by sde-mull          #+#    #+#             */
/*   Updated: 2023/03/08 18:50:44 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	exit_x(t_win *window);

void	init_struct(t_key *screen)
{
	screen->w = 0;
	screen->a = 0;
	screen->d = 0;
	screen->s = 0;
}

int	scan_key(int keycode, t_key *screen)
{
	if (keycode == UP)
		screen->w = 1;
	if (keycode == LEFT)
		screen->a = 1;
	if (keycode == RIGHT)
		screen->d = 1;
	if (keycode == DOWN)
		screen->s = 1;
	return (0);
}

int	scan_key_release(int keycode, t_key *screen)
{
	if (keycode == UP)
		screen->w = 0;
	if (keycode == LEFT)
		screen->a = 0;
	if (keycode == RIGHT)
		screen->d = 0;
	if (keycode == DOWN)
		screen->s = 0;
	if (keycode == CLOSE)
		exit_x(&data()->mlx);
	return (0);
}

int	exit_x(t_win *window)
{
	if (window)
	{
		mlx_destroy_window(window->mlx, window->mlx_win);
		mlx_destroy_display(window->mlx);
		free(window->mlx);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

bool	init_game(t_map *map)
{
	data()->mlx.mlx = mlx_init();
	if (!data()->mlx.mlx)
		return (false);
	data()->mlx.mlx_win = mlx_new_window(data()->mlx.mlx, \
		WIN_X, WIN_Y, "CUB3D");
	if (!data()->mlx.mlx_win)
	{
		free(data()->mlx.mlx_win);
		return (false);
	}
	init_struct(&data()->key);
	mlx_hook(data()->mlx.mlx_win, 17, 0, exit_x, &data()->mlx);
	mlx_hook(data()->mlx.mlx_win, 2, 1L << 0, scan_key, &data()->key);
	mlx_hook(data()->mlx.mlx_win, 3, 1L << 1, scan_key_release, &data()->key);
	mlx_loop(data()->mlx.mlx);
	return (true);
}

int main(int argc, char *argv[])
{
	t_map map;

	if (check_input(argc - 1, argv[1]))
		return (1);
	if (!init_data_val())
		return (2);
	if (read_info(argv[1], &map))
		return (3);
	if (init_game(&map))
		return (4);
	free_all(&map);
	return (0);
}
