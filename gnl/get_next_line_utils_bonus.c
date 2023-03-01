/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:16:15 by pcoimbra          #+#    #+#             */
/*   Updated: 2021/11/03 15:31:19 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	len;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	len = ft_strlen((char *) s1) + ft_strlen((char *) s2);
	dest = (char *)malloc(len + 1);
	if (s1 == 0 || s2 == 0 || dest == 0)
		return (NULL);
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		dest[i++] = s2[j++];
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	int		ind;
	char	*dest;

	ind = 0;
	dest = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (dest == NULL)
		return (0);
	while (s1[ind] != '\0')
	{
		dest[ind] = s1[ind];
		ind++;
	}
	dest[ind] = '\0';
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	char	l;

	l = (char)c;
	while (*s)
	{
		if (*s == l)
			return ((char *)s);
		s++;
	}
	if (l == '\0')
		return ((char *)s);
	return (0);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	unsigned int	ind;
	unsigned int	count;

	ind = 0;
	count = 0;
	while (src[count] != '\0')
		count++;
	if (dstsize != 0)
	{
		while (src[ind] != '\0' && ind < (dstsize - 1))
		{
			dest[ind] = src[ind];
			ind++;
		}
		dest[ind] = '\0';
	}
	return (count);
}

size_t	ft_strlen(const char *s1)
{
	int	ind;

	ind = 0;
	while (s1[ind] != '\0')
		ind++;
	return (ind);
}
