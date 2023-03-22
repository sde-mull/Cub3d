/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:19:54 by sde-mull          #+#    #+#             */
/*   Updated: 2023/03/22 16:28:06 by sde-mull         ###   ########.fr       */
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

int	exit_error(t_win *win)
{
	if (win)
		free_win(win);
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


bool	init_game(void)
{
	t_win	win;
	
	if (!init_window(&win))
		return (false);
	mlx_hook(win.mlx_win , 17, 0, exit_error, &win);
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