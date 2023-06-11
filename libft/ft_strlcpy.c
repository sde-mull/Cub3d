/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:51:57 by sde-mull          #+#    #+#             */
/*   Updated: 2023/06/11 19:28:47 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
