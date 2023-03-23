/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:19:54 by sde-mull          #+#    #+#             */
/*   Updated: 2023/03/23 20:10:49 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	paint_map(t_win *win)
{
	int x;
	int y;

	y = 0;
	while (y < data()->map.dy)
	{
		x = 0;
		while (x < data()->map.dx)
		{
			if (data()->map.arr[y][x] == '1')
				mlx_put_image_to_window(win->mlx, win->mlx_win, \
				win->img[0].mlx_img, x * ICON_X, ICON_Y * y);
			if (data()->map.arr[y][x] == 'N')
				mlx_put_image_to_window(win->mlx, win->mlx_win, \
				win->img[1].mlx_img, x * ICON_X, ICON_Y * y);
			x++;
		}
		y++;
	}
}

int		render(t_win *win)
{
	if (win->mlx_win == NULL)
		return (1);
	paint_map(win);
	return (0);
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