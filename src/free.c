/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:43:55 by sde-mull          #+#    #+#             */
/*   Updated: 2023/03/21 19:50:52 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//para dar free as merdas

void	free_array(char **arr)
{
	int index;

	index = 0;
	while (arr[index])
		free (arr[index++]);
	free (arr);
}

void	free_all(t_map *map)
{
	free_array(data()->textures);
	free_array(map->arr);
	free(data()->floor);
	free(data()->roof);
}

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