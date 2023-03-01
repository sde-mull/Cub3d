/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 19:14:21 by sde-mull          #+#    #+#             */
/*   Updated: 2021/10/29 19:14:21 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Ft_striteri is a function that applies the function ’f’ on each character of
the string passed as argument, passing its index as first argument.
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	index;

	index = 0;
	if (s == 0)
		return ;
	while (s[index] != '\0')
	{
		f(index, &s[index]);
		index++;
	}
}
