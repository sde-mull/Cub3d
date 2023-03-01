/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:30:26 by sde-mull          #+#    #+#             */
/*   Updated: 2022/09/26 02:51:14 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Ft_lstadd_back is a function that adds the "new" node at the end of the list.
*/

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (*lst != NULL)
		ft_lstlast(*lst)->next = new;
	else
		*lst = new;
}
