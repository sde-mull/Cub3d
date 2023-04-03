/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:19:54 by sde-mull          #+#    #+#             */
/*   Updated: 2023/04/03 21:19:07 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

// void check_keys(t_win *win)
// {
// 	if (win->key.w == 1)
// 		move(obj()->player.dirx * 0.01f, obj()->player.diry * 0.01f);
// 	if (win->key.s == 1)
// 		move(obj()->player.dirx * 0.01f, obj()->player.diry * 0.01f);
// 	if (win->key.a == 1)
// 		move(obj()->player.dirx * 0.01f, obj()->player.diry * 0.01f);
// 	if (win->key.d == 1)
// 		move(obj()->player.dirx * 0.01f, obj()->player.diry * 0.01f);	
// }

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
	draw_image(win);
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