/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:51:26 by sde-mull          #+#    #+#             */
/*   Updated: 2022/09/26 02:52:22 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Ft_bzero is a function that erases the data in the n bytes of the memory starting at
the location pointed to by s, by writting zeros (bytes containing '\0') to that area.
*/ 

void	ft_bzero(void *str, size_t n)
{
	size_t			index;

	index = 0;
	while (index < n)
	{
		((unsigned char *)str)[index] = 0;
		index++;
	}
}
