/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:51:44 by sde-mull          #+#    #+#             */
/*   Updated: 2023/06/11 19:28:00 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
