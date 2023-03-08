/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:59:21 by sde-mull          #+#    #+#             */
/*   Updated: 2023/03/08 00:20:06 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	exit_error(t_win *window)
{
	if (window)
	{
		mlx_destroy_window(window->mlx, window->mlx_win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

void	init_game(t_map *map)
{
	data()->mlx.mlx = mlx_init();
	data()->mlx.mlx_win = mlx_new_window(data()->mlx.mlx, \
		WIN_X, WIN_Y, "CUB3D");
	// if (!data()->mlx)
	// 	exit(EXIT_FAILURE);
	mlx_hook(data()->mlx.mlx_win, 17, 0, exit_error, &data()->mlx);
	mlx_loop(data()->mlx.mlx);
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
	init_game(&map);
	free_all(&map);
	return (0);
}
