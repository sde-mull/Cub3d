/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:45:24 by sde-mull          #+#    #+#             */
/*   Updated: 2022/09/26 04:15:27 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Ft_substr is a function that allocates (with malloc(3)) and returns a substring
from the string ’s’. The substring begins at index ’start’ and is of maximum size ’len’.
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	index;
	size_t	count;
	char	*str;

	index = 0;
	count = 0;
	if (s == 0)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	while (s[count + start] != '\0' && count < len)
		count++;
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (str == 0)
		return (0);
	str[count] = '\0';
	while (s[start] != 0 && index < count)
	{
		str[index] = s[start];
		index++;
		start++;
	}
	return (str);
}
