/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:51:59 by sde-mull          #+#    #+#             */
/*   Updated: 2022/09/26 03:55:09 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Ft_strlen is a function that computes the length of the string s.
*/
size_t	ft_strlen(const char *s)
{
	size_t	var2;

	var2 = 0;
	while ((s[var2] != '\0'))
		var2++;
	return (var2);
}
