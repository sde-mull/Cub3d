/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:51:39 by sde-mull          #+#    #+#             */
/*   Updated: 2022/09/26 02:51:27 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Ft_isprint is a function that checks if the argument passed is an printable character.
Return 1 in case is true. Return 0 in case is false.
*/

int	ft_isprint(int c)
{
	if (c < 127 && c >= 32)
		return (1);
	return (0);
}
