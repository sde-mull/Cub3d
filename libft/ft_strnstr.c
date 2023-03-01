/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:52:04 by sde-mull          #+#    #+#             */
/*   Updated: 2022/09/26 04:09:23 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Ft_strnstr is a function that locates the first occurrence of the null-terminated
string needle in the string haystack, where not more than len characters are 
searched.  Characters that appear after a ‘\0’ character are not searched.
*/

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
