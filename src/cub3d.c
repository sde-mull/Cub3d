/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:19:54 by sde-mull          #+#    #+#             */
/*   Updated: 2023/04/01 22:49:37 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	paint_map(t_win *win)
{
	int x;
	int y;

	y = 0;
	while (y < data()->map.dy && data()->map.arr[y])
	{
		x = 0;
		while (x < data()->map.dx && data()->map.arr[y][x])
		{
			if (data()->map.arr[y][x] == '1')
				mlx_put_image_to_window(win->mlx, win->mlx_win, \
				win->img[0].mlx_img, x * ICON_X, ICON_Y * y);
			if (data()->map.arr[y][x] == 'N' || data()->map.arr[y][x] == '0')
				mlx_put_image_to_window(win->mlx, win->mlx_win, \
				win->img[1].mlx_img, x * ICON_X, ICON_Y * y);
			x++;
		}
		y++;
	}
}
void draw_player(t_win *win)
{
	mlx_put_image_to_window(win->mlx, win->mlx_win, \
				win->img[2].mlx_img, obj()->player.x1 * 32, obj()->player.y1 * 32);
}

void check_keys(t_win *win)
{
	if (win->key.w == 1)
		move(0, -0.01f);
	if (win->key.s == 1)
		move(0, 0.01f);
	if (win->key.a == 1)
		move(-0.01f, 0);
	if (win->key.d == 1)
		move(0.01f, 0);	
}

int		render(t_win *win)
{
	if (win->mlx_win == NULL)
		return (1);
	check_keys(win);
	paint_map(win);
	draw_player(win);
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