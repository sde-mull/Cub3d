/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:34:45 by sde-mull          #+#    #+#             */
/*   Updated: 2023/06/01 19:34:02 by pcoimbra         ###   ########.fr       */
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
	data()->textures = ft_calloc(sizeof(char *), 5);
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

	index = -1;
	while (arr[++index])
		printf("ind:%d %s\n", index, arr[index]);
	printf("\n");
	printf("North:%s\nSouth:%s\nEast:%s\nWest:%s\n", \
	data()->textures[0],data()->textures[1],\
	data()->textures[2],data()->textures[3]);
	printf("F:%d;\n", data()->floor);
	printf("C:%d;\n", data()->roof);
}
