/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:51:29 by sde-mull          #+#    #+#             */
/*   Updated: 2023/06/11 19:26:53 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p1;

	p1 = (void *)malloc(count * size);
	if (size == __SIZE_MAX__)
		return (NULL);
	if (p1 == 0)
		return (NULL);
	ft_bzero(p1, count * size);
	return (p1);
}
