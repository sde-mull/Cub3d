/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:47:13 by sde-mull          #+#    #+#             */
/*   Updated: 2023/04/07 16:36:05 by sde-mull         ###   ########.fr       */
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
