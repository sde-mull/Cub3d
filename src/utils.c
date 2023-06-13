/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:34:45 by sde-mull          #+#    #+#             */
/*   Updated: 2023/06/13 15:52:04 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

t_data	*data(void)
{
	static t_data	data;

	return (&data);
}

t_objects	*obj(void)
{
	static t_objects	objs;

	return (&objs);
}

t_canvas	*canvas(void)
{
	static t_canvas	canv;

	return (&canv);
}

bool	init_data_val(void)
{
	(data())->textures = ft_calloc(sizeof(char *), 5);
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
	obj()->w_flags = 0;
}
