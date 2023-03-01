/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 19:59:47 by sde-mull          #+#    #+#             */
/*   Updated: 2021/10/28 19:59:47 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Ft_strjoin is a function that allocates and returns a new string,
which is the result of the concatenation of ’s1’ and ’s2’.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	index;
	size_t	index_2;
	char	*str;

	index = 0;
	index_2 = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (str == 0)
		return (NULL);
	while (s1[index] != '\0')
	{
		str[index] = s1[index];
		index++;
	}
	while (s2[index_2] != '\0')
	{
		str[index] = s2[index_2];
		index++;
		index_2++;
	}
	str[index] = '\0';
	return (str);
}
