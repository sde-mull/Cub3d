/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:19:54 by sde-mull          #+#    #+#             */
/*   Updated: 2023/06/13 19:59:30 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	render(t_win *win)
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
	mlx_put_image_to_window(win->mlx, win->mlx_win, \
		canvas()->game.mlx_img, 0, 0);
	return (0);
}

int	main(int argc, char *argv[])
{
	init_obj_val();
	if (init_data_val() == false)
		return (1);
	if (parse_file(argc, argv))
		return (1);
	if (!init_game())
		return (2);
	if (data()->map.arr)
		free_all(&(data()->map));
	return (0);
}
