/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 20:09:11 by sde-mull          #+#    #+#             */
/*   Updated: 2021/10/29 20:09:11 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_number_len(int n)
{
	int	int_len;

	int_len = 0;
	while (n > 9)
	{
		n = n / 10;
		int_len++;
	}
	return (int_len + 1);
}

static int	ft_check_negative(int negative, int n)
{
	if (n < 0)
		negative = 1;
	else
		negative = 0;
	return (negative);
}

char	*ft_itoa(int n)
{
	char	*converted_int;
	int		nega_number;
	int		index;

	nega_number = 0;
	nega_number = ft_check_negative(nega_number, n);
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	if (nega_number == 1)
		n = n * (-1);
	index = ft_number_len(n);
	converted_int = (char *)malloc(sizeof(char) * (index + nega_number) + 1);
	if (converted_int == 0)
		return (NULL);
	converted_int[index + nega_number] = '\0';
	while (index > 0)
	{
		converted_int[index + nega_number - 1] = (n % 10) + 48;
		index--;
		n = n / 10;
	}
	if (nega_number == 1)
		converted_int[0] = '-';
	return (converted_int);
}
