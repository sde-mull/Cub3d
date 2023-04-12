/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:29:28 by sde-mull          #+#    #+#             */
/*   Updated: 2023/04/12 21:13:49 by sde-mull         ###   ########.fr       */
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
	img.addr = mlx_get_data_addr(img.mlx_img, &img.bpp, &img.line_len,\
	&img.endian);
	return (img);
}

void	init_images(t_win *win)
{
	canvas()->map[0] = load_images(win, "images/xpm/map/map_wall.xpm");
	canvas()->map[1] = load_images(win, "images/xpm/map/map_floor.xpm");
	canvas()->map[2] = load_images(win, "images/xpm/map/player.xpm");
	canvas()->p_map = new_image(win, data()->map.dx * ICON_X, data()->map.dy * ICON_Y);
	canvas()->game = new_image(win, WIN_X, WIN_Y);
}
