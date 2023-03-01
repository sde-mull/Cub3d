/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:51:53 by sde-mull          #+#    #+#             */
/*   Updated: 2022/09/26 02:48:40 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Ft_strdup is a function that allocates sufficient memory for a copy of the 
string s1, does the copy, and returns a pointer to it.  The pointer may 
subsequently be used as an argument to the function free.
*/

char	*ft_strdup(const char *s1)
{
	char	*str;

	str = (char *)malloc(ft_strlen(s1) * sizeof(char) + 1);
	if (str == 0)
		return (0);
	ft_strlcpy(str, s1, (ft_strlen(s1) + 1));
	return (str);
}
