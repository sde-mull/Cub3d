/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:19:54 by sde-mull          #+#    #+#             */
/*   Updated: 2023/04/05 17:53:01 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void get_velocity(void)
{
	obj()->vwx = 0.01 * cos(obj()->player.angle);
	obj()->vwy = 0.01 * sin(obj()->player.angle);
	obj()->vdx = 0.01 * cos(obj()->player.angle - (PI / 2));
	obj()->vdy = 0.01 * sin(obj()->player.angle - (PI / 2));
}

void check_keys(t_win *win)
{
	get_velocity();
	if (win->key.w == 1)
		move(obj()->vwx, -obj()->vwy);
	if (win->key.s == 1)
		move(-obj()->vwx, obj()->vwy);
	if (win->key.a == 1)
		move(-obj()->vdx, -obj()->vdy);
	if (win->key.d == 1)
		move(obj()->vdx, obj()->vdy);	
	if (win->key.left == 1)
		obj()->player.angle += 0.005;
	if (win->key.right == 1)
		obj()->player.angle -= 0.005;
	if (obj()->player.angle > (obj()->player.save_angle + (2 * PI)))
		obj()->player.angle = obj()->player.save_angle;
	if (obj()->player.angle < 0)
		obj()->player.angle = 2 * PI;
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