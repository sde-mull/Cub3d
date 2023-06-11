/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_information.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:21:12 by sde-mull          #+#    #+#             */
/*   Updated: 2023/06/11 19:19:10 by sde-mull         ###   ########.fr       */
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

// t_player	get_player(t_map *map)
// {
// 	int x;
// 	int y;
// 	t_player objs;

// 	y = 0;
// 	while (y < map->dy && map->arr[y])
// 	{
// 		x = 0;
// 		while (x < map->dx && map->arr[y][x])
// 		{
// 			if (map->arr[y][x] == 'N' || map->arr[y][x] == 'W' ||
// 				map->arr[y][x] == 'E' || map->arr[y][x] == 'S')
// 				{
// 					get_direction(&objs, x, y, map);
// 					get_angle(&objs);
// 					break;
// 				}
// 			x++;
// 		}
// 		y++;
// 	}
// 	objs.player_x += 0.5;
// 	objs.player_y += 0.5;
// 	return (objs);
// }

// para salvar a informacao que vem antes do mapa

// void	save_info(int fd)
// {
// 	char	*str;
// 	int		index;

// 	index = -1;
// 	while (index++ < 3)
// 		data()->textures[index] = get_next_line(fd);
// 	data()->textures[index] = NULL;
// 	free(get_next_line(fd));
// 	data()->floor = get_next_line(fd);
// 	data()->roof = get_next_line(fd); // so meti isto aqui para chegar ao mapa
// 	printf("Textures:%s\n%s\n%s\n%s\nFloor:%s\nRoof:%s\n", data()->textures[0],data()->textures[1],data()->textures[2],data()->textures[3],data()->floor, data()->roof);
// }

// int	read_info(char *file, t_map *map)
// {
// 	int fd;

// 	// if (another_checker())
// 	// 	return (1);
// 	fd = open(file, O_RDONLY);
// 	if (fd < 0)
// 		return (printf("\033[0;31mError:\033[0m %s\n", strerror(errno)));
// 	// if (!save_info(fd, 6))
// 	// 	return (printf("\033[0;31mError:\033[0m %s\n", strerror(errno)));
// 	if (!save_map(fd, map))
// 		return (printf("\033[0;31mError:\033[0m %s\n", strerror(errno)));
// 	close(fd);
// 	obj()->player = get_player(&data()->map);
// 	return (0);
// }
