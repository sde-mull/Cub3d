/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:00:35 by sde-mull          #+#    #+#             */
/*   Updated: 2022/09/26 02:48:46 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Ft_strchr is a function locates the first occurrence of c in the string 
pointed to by s.  The terminating null character is considered to be part 
of the string. Therefore if c is ‘\0’, the functions locate the terminating ‘\0’.
*/

char	*ft_strchr(const char *s, int c)
{
	size_t	index;

	index = 0;
	while (s[index] != '\0')
	{
		if (s[index] == (unsigned char)c)
			return (&((char *)s)[index]);
		index++;
	}
	if (s[index] == ((unsigned char)c))
		return (&((char *)s)[index]);
	return (NULL);
}
