/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:52:04 by sde-mull          #+#    #+#             */
/*   Updated: 2023/06/11 19:28:59 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	index;
	size_t	count;

	index = 0;
	count = 0;
	if (needle[index] == '\0')
		return ((char *)haystack);
	while (index < len && haystack[index] != '\0')
	{
		count = 0;
		while (haystack[index + count] == needle[count]
			&& (index + count) < len)
		{
			if (needle[count + 1] == '\0')
				return ((char *)(haystack + index));
			count++;
		}
		index++;
	}
	return (NULL);
}
