/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 20:27:39 by sde-mull          #+#    #+#             */
/*   Updated: 2021/10/28 20:27:39 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		index;
	size_t		len;
	char		*str;

	index = 0;
	len = ft_strlen(s1);
	if (s1 == 0 || set == 0)
		return (NULL);
	while (s1[index] != '\0' && ft_strchr(set, s1[index]))
		index++;
	if (s1[index] == '\0')
		return (ft_strdup(s1 + index));
	while (ft_strrchr(set, s1[len]))
		len--;
	str = ft_substr(s1, index, len - index + 1);
	return (str);
}
