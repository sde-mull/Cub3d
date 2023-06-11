/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:51:50 by sde-mull          #+#    #+#             */
/*   Updated: 2023/06/11 19:28:05 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
