/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:34:45 by sde-mull          #+#    #+#             */
/*   Updated: 2023/03/07 18:19:59 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_data	*data(void)
{
	static t_data	data;

	return (&data);
}

bool	init_data_val(void)
{
	data()->textures = malloc(sizeof(char *) * 5);
	if (!data()->textures)
		return (false);
	data()->floor = NULL;
	data()->roof = NULL;
	return (true);
}

void	print_map(char **arr)
{
	int index;

	index = 0;
	while (arr[index])
	{
		printf("%s", arr[index]);
		index++;
	}
	printf("\n");
}
