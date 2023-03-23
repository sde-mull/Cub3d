/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 00:08:35 by sde-mull          #+#    #+#             */
/*   Updated: 2023/03/23 20:18:35 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

//inicia a struct das keys para zero

void	init_struct(t_win win)
{
	win.key.w = 0;
	win.key.a = 0;
	win.key.d = 0;
	win.key.s = 0;
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
	if (keycode == CLOSE)
		exit_game(win);
	return (0);
}

//inicia a window com as protecoes mais importantes

bool	init_window(t_win *win)
{
	win->mlx = mlx_init();
	if (win->mlx == NULL)
		return (WIN_ERROR);
	win->mlx_win = mlx_new_window(win->mlx_win, WIN_X, WIN_Y, "Cub3d");
	if (win->mlx == NULL)
	{
		free(win->mlx);
		return (WIN_ERROR);
	}
	return (true);
}

//instrucoes gerais para a iniciacao da janela

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char    *pixel;
	int		i;

	i = img->bpp - 8;
    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		/* big endian, MSB is the leftmost bit */
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		/* little endian, LSB is the leftmost bit */
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

void	create_image(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < ICON_Y)
	{
		j = 0;
		while (j < ICON_X)
		{
			img_pix_put(img, j++, i, color);
		}
		++i;
	}
}

void	create_player_image(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < PLAY_Y)
	{
		j = 0;
		while (j < PLAY_X)
		{
			img_pix_put(img, j++, i, color);
			if (i > PLAY_Y / 3 && i < PLAY_Y - PLAY_Y / 3 )
				while (j < PLAY_X + 10)
					img_pix_put(img, j++, i, color);
		}
		++i;
	}
}

bool	init_game(void)
{
	t_win	win;
	
    init_struct(win);
	if (!init_window(&win))
		return (false);
	win.img[0].mlx_img = mlx_new_image(win.mlx, ICON_X, ICON_Y);
	win.img[1].mlx_img = mlx_new_image(win.mlx, PLAY_X + 10, PLAY_Y + 10);
	win.img[0].addr = mlx_get_data_addr(win.img[0].mlx_img, &win.img[0].bpp,
			&win.img[0].line_len, &win.img[0].endian);
	win.img[1].addr = mlx_get_data_addr(win.img[1].mlx_img, &win.img[1].bpp,
			&win.img[1].line_len, &win.img[1].endian);
	create_image(&win.img[0], 0xFF0000);
	create_player_image(&win.img[1], 0xEEE112);
	mlx_hook(win.mlx_win , 17, 0, exit_game, &win);
	mlx_hook(win.mlx_win, 2, 1L << 0, scan_key, &win);
	mlx_hook(win.mlx_win, 3, 1L << 1, scan_key_release, &win);
	mlx_loop_hook(win.mlx, &render, &win);
	mlx_loop(win.mlx);
	free_win(&win);
	return (true);
}