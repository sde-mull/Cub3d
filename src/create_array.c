/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:18:46 by sde-mull          #+#    #+#             */
/*   Updated: 2023/05/29 18:50:32 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

//Vai dar skip nas quebras de linhas ou espacos pelo meio. Falta so fazer uma verificacao para caracteres especiais que ai acho que devia dar erro

void	map_start(int fd, t_line *line)
{
	int		index;
	int		flg;

	index = 0;
	flg = 0;
	line->y = get_next_line(fd);
	line->next = NULL;
	while (line->y)
	{
		while (line->y[index])
		{
			if (line->y[index] == '1' || line->y[index] == '0')
			{
				flg = 1;
				break ;
			}
			index++;
		}
		if (flg == 1)
			break ;
		free(line->y);
		line->y = get_next_line(fd);
	}
}

//obter as dimensoes do double array que nao quero fazer isto por listas a menos que tu prefiras

void	get_dimensions(t_map *map)
{
	int		x;
	int 	y;
	
	y = 0;
	map->dx = 0;
	while (map->arr[y])
	{
		x = -1;
		while (map->arr[y][++x] != '\0')
			if (map->dx < x)
				map->dx = x - 1;
		y++;
	}
	map->dy = y;
}

//converte a lista para um array de chars

bool	create_array(t_map *map, t_line *line)
{
	t_line *curr;
	int		index;

	curr = line;
	index = 0;
	map->arr = malloc(sizeof(char *) * (map->dy + 1));
	if (!map->arr)
		return (false);
	while (curr->next)
	{
		map->arr[index] = ft_strdup(curr->y);
		index++;
		curr = curr->next;
	}
	map->arr[index] = NULL;
	return (true);
}

//funcao principal para a criacao do mapa

// bool	save_map(int fd, t_map *map)
// {
// 	t_line	*line;
// 	t_line  *curr;
	
// 	line  = malloc(sizeof(t_line));
// 	if (!line)
// 		return (false);
// 	curr = line;
// 	map_start(fd, line);
// 	while (curr->y)
// 	{
// 		if (!insert_node(get_next_line(fd), &line))
// 			return (false);
// 		curr = curr->next;
// 	}
// 	get_dimensions(map, line);
// 	if (!create_array(map, line))
// 		return (false);
// 	ft_deallocate(&line);
// 	return (true);
// }