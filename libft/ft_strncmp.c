/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:52:01 by sde-mull          #+#    #+#             */
/*   Updated: 2022/09/26 04:07:50 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Ft_strncmp is a function that lexicographically compare the null-terminated
strings s1 and s2, not more than n characters.
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;
	int		rst;

	index = 0;
	if (n == 0)
		return (0);
	while (index < n && (s1[index] != '\0' || s2[index] != '\0'))
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
