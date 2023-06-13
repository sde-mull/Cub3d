/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 18:14:35 by sde-mull          #+#    #+#             */
/*   Updated: 2023/06/13 17:33:09 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	draw_player(t_win *win, t_img *img, int countx, int county)
{
	int				x;
	int				y;
	unsigned int	dst;
	unsigned int	cmp;

	y = 0;
	cmp = my_mlx_get_pixel(&canvas()->map[2], 5, 5);
	while (y < ICON_Y)
	{
		x = 0;
		while (x < ICON_X / 4)
		{
			dst = my_mlx_get_pixel(img, x, y);
			if (cmp == dst)
				my_mlx_pixel_put(&canvas()->p_map, x + countx, y + county, \
					(int)dst);
			x++;
		}
		y++;
	}
}

void	draw_mini_map(t_win *win)
{
	t_extra	ex;

	ex.sx = (obj()->player.x1 - 4) * 32;
	ex.y = (obj()->player.y1 - 4) * 32;
	ex.sy = ex.y;
	ex.mx = (obj()->player.x1 + 4) * 32;
	ex.my = (obj()->player.y1 + 4) * 32;
	while (ex.y < ex.my + 1)
	{
		ex.x = (obj()->player.x1 - 4) * 32;
		while (ex.x < ex.mx + 1)
		{
			if (ex.x < data()->map.mx && ex.y < data()->map.my && ex.x > 0 && \
				ex.y > 0)
			{
				ex.dst = my_mlx_get_pixel(&canvas()->p_map, ex.x, ex.y);
				my_mlx_pixel_put(&canvas()->game, ex.x - ex.sx, ex.y - ex.sy, \
					(int)ex.dst);
			}
			ex.x++;
		}
		ex.y++;
	}
}

void	draw_full_map(t_win *win)
{
	int				y;
	int				x;
	unsigned int	dst;

	y = 0;
	while (y < data()->map.my)
	{
		x = 0;
		while (x < data()->map.mx)
		{
			dst = my_mlx_get_pixel(&canvas()->p_map, x, y);
			if (dst != 0)
				my_mlx_pixel_put(&canvas()->game, x, y, (int)dst);
			x++;
		}
		y++;
	}
}
