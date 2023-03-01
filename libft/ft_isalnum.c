/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:51:31 by sde-mull          #+#    #+#             */
/*   Updated: 2022/09/26 02:51:48 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Ft_isalnum is a function that checks if the character passed as an argument is an alphanumeric.
Return 1 if the character is alphanumeric. Return 0 if the character is not alphanumeric.
*/

int	ft_isalnum(int c)
{
	if (((c >= 'A') && (c <= 'Z'))
		|| ((c <= '9') && (c >= '0'))
		|| ((c >= 'a') && (c <= 'z')))
		return (1);
	return (0);
}
