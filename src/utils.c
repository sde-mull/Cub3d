/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:34:45 by sde-mull          #+#    #+#             */
/*   Updated: 2023/05/29 18:29:43 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

t_data	*data(void)
{
	static t_data	data;

	return (&data);
}

t_objects *obj(void)
{
	static t_objects objs;

	return (&objs);
}

t_canvas *canvas(void)
{
	static t_canvas canv;

	return (&canv);
}

bool	init_data_val(void)
{
	data()->textures = malloc(sizeof(char *) * 5);
	if (!data()->textures)
		return (false);
	data()->floor = 0;
	data()->roof = 0;
	return (true);
}

void	init_obj_val(void)
{
	obj()->player.player_x = 0;
	obj()->player.player_y = 0;
	obj()->player.x1 = 0;
	obj()->player.y1 = 0;
	obj()->W_flags = 0;
}

void	print_map(char **arr)
{
	int index;

	index = 0;
	while (arr[index])
	{
		printf("%s\n", arr[index]);
		index++;
	}
	printf("\n");
}
