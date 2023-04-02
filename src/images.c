/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:29:28 by sde-mull          #+#    #+#             */
/*   Updated: 2023/04/02 19:14:08 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	init_images(t_win *win)
{
	win->img[0].mlx_img = mlx_xpm_file_to_image(win->mlx, \
	"images/xpm/map/map_wall.xpm", &win->img[0].imgx, &win->img[0].imgy);
	win->img[1].mlx_img = mlx_xpm_file_to_image(win->mlx, \
	"images/xpm/map/map_floor.xpm", &win->img[1].imgx, &win->img[1].imgy);
	win->img[2].mlx_img = mlx_xpm_file_to_image(win->mlx, \
	"images/xpm/map/player.xpm", &win->img[1].imgx, &win->img[1].imgy);
    win->map.mlx_img = mlx_new_image(win->mlx, data()->map.dx * ICON_X, \
        data()->map.dy * ICON_Y);
}

void    init_address(t_win *win)
{
    win->map.addr = mlx_get_data_addr(win->map.mlx_img, &win->map.bpp, &win->map.line_len, &win->map.endian);
	win->img[0].addr = mlx_get_data_addr(win->img[0].mlx_img, &win->img[0].bpp, &win->img[0].line_len, &win->img[0].endian);
	win->img[1].addr = mlx_get_data_addr(win->img[1].mlx_img, &win->img[1].bpp, &win->img[1].line_len, &win->img[1].endian);
	win->img[2].addr = mlx_get_data_addr(win->img[2].mlx_img, &win->img[2].bpp, &win->img[2].line_len, &win->img[2].endian);
}
