/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:29:28 by sde-mull          #+#    #+#             */
/*   Updated: 2023/06/11 18:05:38 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

t_img	new_image(t_win *win, int x, int y)
{
	t_img	img;

	img.mlx_img = mlx_new_image(win->mlx, x, y);
	img.addr = mlx_get_data_addr(img.mlx_img, &img.bpp, &img.line_len,\
	&img.endian);
	return (img);
}

t_img	load_images(t_win *win,char *str)
{
	t_img img;

	img.mlx_img = mlx_xpm_file_to_image(win->mlx, str, &img.imgx, &img.imgy);
	if (!img.mlx_img)
	{
		exit_game(win);
		free_win(win);
		if (data()->map.arr)
			free_all(&(data()->map));
		exit(10);
	}
	img.addr = mlx_get_data_addr(img.mlx_img, &img.bpp, &img.line_len,\
	&img.endian);
	return (img);
}

void	init_images(t_win *win)
{
	canvas()->map[0] = load_images(win, "images/xpm/map/map_wall.xpm");
	canvas()->map[1] = load_images(win, "images/xpm/map/map_floor.xpm");
	canvas()->map[2] = load_images(win, "images/xpm/map/player.xpm");
	canvas()->walls[0] = load_images(win, data()->textures[2]); //east
	canvas()->walls[1] = load_images(win, data()->textures[3]); //west
	canvas()->walls[2] = load_images(win, data()->textures[0]); //north
	canvas()->walls[3] = load_images(win, data()->textures[1]); //south
	canvas()->p_map = new_image(win, data()->map.mx, data()->map.my);
	canvas()->game = new_image(win, WIN_X, WIN_Y);
}
