/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:43:55 by sde-mull          #+#    #+#             */
/*   Updated: 2023/06/13 20:10:39 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

//caso existam destroi a janela e o display e da free do void pointer

void	free_win(t_win *win)
{
	int	index;

	index = 0;
	while (index < 3)
	{
		if (canvas()->map[index].mlx_img)
			mlx_destroy_image(win->mlx, canvas()->map[index].mlx_img);
		if (canvas()->walls[index].mlx_img)
			mlx_destroy_image(win->mlx, canvas()->walls[index].mlx_img);
		index++;
	}
	if (canvas()->walls[index].mlx_img)
		mlx_destroy_image(win->mlx, canvas()->walls[index].mlx_img);
	if (canvas()->p_map.mlx_img)
		mlx_destroy_image(win->mlx, canvas()->p_map.mlx_img);
	if (canvas()->game.mlx_img)
		mlx_destroy_image(win->mlx, canvas()->game.mlx_img);
	if (win->mlx)
	{
		mlx_destroy_display(win->mlx);
		free(win->mlx);
	}
}

//acaba o loop e destroi a janela no momento que se clica no x ou esc

int	exit_game(t_win *win)
{
	if (win->mlx_win)
	{
		mlx_destroy_window(win->mlx, win->mlx_win);
		win->mlx_win = NULL;
		mlx_loop_end(win->mlx);
	}
	return (0);
}

void	free_array_map(char **arr)
{
	int	ind;

	ind = 0;
	while (arr[ind])
		free(arr[ind++]);
	free (arr);
}
//free do double array

void	free_array(char **arr)
{
	int	index;

	index = -1;
	while (arr[++index])
		free (arr[index]);
	free (arr);
}

//da free de tudo o que foi allocado antes da criacao da janela

void	free_all(t_map *map)
{
	free_array(data()->textures);
	free_array_map(map->arr);
}
