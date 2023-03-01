/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:51:50 by sde-mull          #+#    #+#             */
/*   Updated: 2022/09/26 02:49:18 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Ft_memset is a function that writes len bytes of value c to the string b.
*/

void	*ft_memset(void *str, int c, size_t len)
{
	size_t			index;
	unsigned char	*var;

	var = str;
	index = 0;
	while (index < len)
	{
		var[index] = (unsigned char)c;
		index++;
	}
	return (var);
}
