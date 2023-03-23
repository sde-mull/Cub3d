/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:43:55 by sde-mull          #+#    #+#             */
/*   Updated: 2023/03/23 20:13:55 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

//caso existam destroi a janela e o display e da free do void pointer

void free_win(t_win *win)
{
	mlx_destroy_image(win->mlx, win->img[0].mlx_img);
	mlx_destroy_image(win->mlx, win->img[1].mlx_img);
	if (win->mlx_win)
	{
		mlx_destroy_window(win->mlx, win->mlx_win);
		win->mlx_win = NULL;
	}
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

//free do double array

void	free_array(char **arr)
{
	int index;

	index = 0;
	while (arr[index])
		free (arr[index++]);
	free (arr);
}

//da free de tudo o que foi allocado antes da criacao da janela

void	free_all(t_map *map)
{
	free_array(data()->textures);
	free_array(map->arr);
	free(data()->floor);
	free(data()->roof);
}

//da free da lista criada

void	ft_deallocate(t_line **root)
{
	t_line	*curr;
	t_line	*aux;

	curr = *root;
	while (curr != NULL)
	{
		aux = curr;
		curr = curr->next;
		free(aux->y);
		free(aux);
	}
	*root = NULL;
}