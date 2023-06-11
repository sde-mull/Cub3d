/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:51:48 by sde-mull          #+#    #+#             */
/*   Updated: 2023/06/11 19:28:08 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	index;

	if (dst == 0)
		return (NULL);
	if (dst > src)
	{
		index = (int) len;
		while (index > 0)
		{
			index--;
			((unsigned char *)dst)[index] = ((unsigned char *)src)[index];
		}
	}
	else
	{
		index = 0;
		while (index < (int)len)
		{
			((unsigned char *)dst)[index] = ((unsigned char *)src)[index];
			index++;
		}	
	}	
	return (dst);
}
