/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:28:23 by sde-mull          #+#    #+#             */
/*   Updated: 2023/04/07 14:37:28 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

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
	if (keycode == MAP)
	{
		if (win->key.m == 0)
			win->key.m = 1;
		else
			win->key.m = 0;
	}
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
