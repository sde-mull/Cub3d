/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:51:57 by sde-mull          #+#    #+#             */
/*   Updated: 2022/09/26 03:15:39 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Ft_strlcpy is a function that copy and concatenate strings.
Ft_strlcpy copies up to dstsize - 1 characters from the string src to dst, 
NULL-terminating the result if dstsize is not 0.
Ft_strlcpy() take the full size of the destination buffer and guarantee
NUL-termination if there is room.
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	index;
	size_t	index2;

	index = 0;
	while (src[index] != '\0')
		index++;
	if (size > 0)
	{
		index2 = 0;
		while (index2 < (size - 1) && src[index2] != '\0')
		{
			dst[index2] = src[index2];
			index2++;
		}
		dst[index2] = '\0';
	}
	return (index);
}
