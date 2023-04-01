/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 00:08:35 by sde-mull          #+#    #+#             */
/*   Updated: 2023/04/01 22:51:19 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

//inicia a struct das keys para zero

void	init_struct(t_win *win)
{
	win->key.w = 0;
	win->key.a = 0;
	win->key.d = 0;
	win->key.s = 0;
}

void	move(double x, double y)
{
	double x2;
	double y2;
	double x1;
	double y1;

	x1 = 0;
	y1 = 0;
	if (x > 0)
		x1 = 0.2f;
	if (y > 0)
		y1 = 0.2f;
	x += (obj()->player.x1);
	y += (obj()->player.y1);
	x2 = x1 + x;
	y2 = y1 + y;
	printf("%f ||| %f\n", y2, x2);
	if (data()->map.arr[(unsigned int)y2][(unsigned int)x2] == '1')
		return ;
	obj()->player.x1 = x;
	obj()->player.y1 = y;
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


bool	init_game(void)
{
	t_win	win;
	
    init_struct(&win);
	obj()->player.x1 = obj()->player.player_x;
	obj()->player.y1 = obj()->player.player_y;
	if (!init_window(&win))
		return (false);
	printf("%d\n", win.key.a);
	win.img[0].mlx_img = mlx_xpm_file_to_image(win.mlx, "images/xpm/map/map_wall.xpm", &win.img[0].imgx, &win.img[0].imgy);
	win.img[1].mlx_img = mlx_xpm_file_to_image(win.mlx, "images/xpm/map/map_floor.xpm", &win.img[1].imgx, &win.img[1].imgy);
	win.img[2].mlx_img = mlx_xpm_file_to_image(win.mlx, "images/xpm/map/player.xpm", &win.img[1].imgx, &win.img[1].imgy);
	mlx_hook(win.mlx_win , 17, 0, exit_game, &win);
	mlx_hook(win.mlx_win, 2, 1L << 0, scan_key, &win);
	mlx_hook(win.mlx_win, 3, 1L << 1, scan_key_release, &win);
	mlx_loop_hook(win.mlx, &render, &win);
	mlx_loop(win.mlx);
	free_win(&win);
	return (true);
}

// void	img_pix_put(t_img *img, int x, int y, int color)
// {
// 	char    *pixel;
// 	int		i;

// 	i = img->bpp - 8;
//     pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
// 	while (i >= 0)
// 	{
// 		/* big endian, MSB is the leftmost bit */
// 		if (img->endian != 0)
// 			*pixel++ = (color >> i) & 0xFF;
// 		/* little endian, LSB is the leftmost bit */
// 		else
// 			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
// 		i -= 8;
// 	}
// }
