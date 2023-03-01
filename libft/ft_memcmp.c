/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:51:44 by sde-mull          #+#    #+#             */
/*   Updated: 2022/09/26 02:49:38 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Ft_memcmp is a function that returns zero if the two strings are identical, 
otherwise returns the difference between the first two differing bytes. 
Zero-length strings are always identical. This behavior is not required by C 
and portable code should only depend on the sign of the returned value.
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	index;
	int		rst;

	index = 0;
	if (n == 0)
		return (0);
	while (index < n)
	{
		if (((unsigned char *)s1)[index] != ((unsigned char *)s2)[index])
		{
			rst = ((unsigned char *)s1)[index] - ((unsigned char *)s2)[index];
			return (rst);
		}
		index++;
	}
	return (0);
}
