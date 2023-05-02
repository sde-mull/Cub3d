/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:19:54 by sde-mull          #+#    #+#             */
/*   Updated: 2023/04/19 19:22:23 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

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