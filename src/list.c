/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:47:13 by sde-mull          #+#    #+#             */
/*   Updated: 2023/06/11 19:11:49 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

//para adicionar elementos a lista

bool	insert_node(char *str, t_line **line)
{
	t_line	*new_node;
	t_line	*curr;

	new_node = malloc(sizeof(t_line));
	if (new_node == NULL)
		return (false);
	new_node->next = NULL;
	new_node->y = str;
	if (*line == NULL)
	{
		*line = new_node;
		return (true);
	}
	curr = *line;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new_node;
	return (true);
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
