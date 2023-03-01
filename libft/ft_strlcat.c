/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:17:33 by sde-mull          #+#    #+#             */
/*   Updated: 2022/09/26 03:14:26 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Ft_strlcat is a function that copy and concatenate strings.
Ft_strlcat() appends string src to the end of dst.
Ft_strlcat() take the full size of the destination buffer and guarantee
NUL-termination if there is room.
*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	index;
	size_t	index2;

	index = 0;
	index2 = 0;
	while (dst[index] != '\0')
		index++;
	if (index >= size)
	{
		while (src[index2] != '\0')
			index2++;
		return (size + index2);
	}
	while (index < (size - 1) && src[index2] != '\0')
	{
		dst[index] = src[index2];
		index++;
		index2++;
	}
	dst[index] = '\0';
	while (src[index2++] != '\0')
		index++;
	return (index);
}
