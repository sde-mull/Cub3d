/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:52:06 by sde-mull          #+#    #+#             */
/*   Updated: 2022/09/26 04:11:47 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Ft_strrchr is a function that locates the last occurrence of c in the string
pointed to by s.  The terminating null character is considered to be part of
the string; therefore if c is ‘\0’, the functions locate the terminating ‘\0’.
*/

char	*ft_strrchr(const char *s, int c)
{
	int	index;

	index = ft_strlen(s);
	while (index >= 0)
	{
		if (s[index] == (unsigned char)c)
			return (&((char *)s)[index]);
		index--;
	}
	return (NULL);
}
