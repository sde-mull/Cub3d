/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:47:13 by sde-mull          #+#    #+#             */
/*   Updated: 2023/03/06 23:44:55 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//para adicionar elementos a lista

void	insert_node(char *str, t_line **line)
{
	t_line	*new_node;
	t_line	*curr;

	new_node = malloc(sizeof(t_line));
	if (new_node == NULL)
		exit(2);
	new_node->next = NULL;
	new_node->y = str;
	if (*line == NULL)
	{
		*line = new_node;
		return ;
	}
	curr = *line;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new_node;
}