/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_information.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:21:12 by sde-mull          #+#    #+#             */
/*   Updated: 2023/06/13 15:29:24 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

//saber a posicao do player

void	get_angle(t_player	*objs)
{
	if (objs->dirx == 1 && objs->diry == 0)
		objs->angle = 0;
	else if (objs->dirx == 0 && objs->diry == 1)
		objs->angle = PI / 2;
	else if (objs->dirx == -1 && objs->diry == 0)
		objs->angle = PI;
	else if (objs->dirx == 0 && objs->diry == -1)
		objs->angle = (3 * PI) / 2;
	objs->save_angle = objs->angle;
}

void	get_direction(t_player *objs, int x, int y, t_map *map)
{
	objs->player_x = x;
	objs->player_y = y;
	if (map->arr[y][x] == 'N' || map->arr[y][x] == 'S')
		objs->dirx = 0;
	if (map->arr[y][x] == 'E' || map->arr[y][x] == 'W')
		objs->diry = 0;
	if (map->arr[y][x] == 'N')
		objs->diry = 1;
	if (map->arr[y][x] == 'S')
		objs->diry = -1;
	if (map->arr[y][x] == 'W')
		objs->dirx = -1;
	if (map->arr[y][x] == 'E')
		objs->dirx = 1;
}
