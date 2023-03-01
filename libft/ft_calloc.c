/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:51:29 by sde-mull          #+#    #+#             */
/*   Updated: 2022/09/28 14:49:13 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Ft_calloc is a function that allocates the requested memory and returns a pointer to it.
The difference between malloc and calloc is that malloc does not set the memory to zero.
*/

void	*ft_calloc(size_t count, size_t size)
{
	void	*p1;

	p1 = (void *)malloc(count * size);
	if (size == __SIZE_MAX__)
		return (NULL);
	if (p1 == 0)
		return (NULL);
	ft_bzero(p1, count * size);
	return (p1);
}
