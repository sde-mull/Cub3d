/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:28:23 by sde-mull          #+#    #+#             */
/*   Updated: 2023/04/05 17:11:02 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	init_struct(t_win *win)
{
	win->key.w 	= 0;
	win->key.a 	= 0;
	win->key.d 	= 0;
	win->key.s 	= 0;
	win->key.right 	= 0;
	win->key.left	= 0;
}

//enquanto primido vai ser igual a 1 

int	scan_key(int keycode, t_win *win)
{
	if (keycode == UP)
		win->key.w = 1;
	if (keycode == LEFT)
		win->key.a = 1;
	if (keycode == RIGHT)
		win->key.d = 1;
	if (keycode == DOWN)
		win->key.s = 1;
	if (keycode == ARROW_L)
		win->key.left = 1;
	if (keycode == ARROW_R)
		win->key.right = 1;
	return (0);
}

//quando se soltar vai voltar a meter para 0

int	scan_key_release(int keycode, t_win *win)
{
	if (keycode == UP)
		win->key.w = 0;
	if (keycode == LEFT)
		win->key.a = 0;
	if (keycode == RIGHT)
		win->key.d = 0;
	if (keycode == DOWN)
		win->key.s = 0;
	if (keycode == ARROW_L)
		win->key.left = 0;
	if (keycode == ARROW_R)
		win->key.right = 0;
	if (keycode == CLOSE)
		exit_game(win);
	return (0);
}
