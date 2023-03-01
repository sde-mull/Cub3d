/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:23:37 by sde-mull          #+#    #+#             */
/*   Updated: 2022/09/26 02:51:09 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Ft_lstadd_front is a function that adds the "new" node at the beginning of the list.
*/

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if ((*lst) == NULL)
		*lst = new;
	else
	{
		new->next = *lst;
		*lst = new;
	}
}
