/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:17:33 by sde-mull          #+#    #+#             */
/*   Updated: 2023/06/11 19:28:44 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
