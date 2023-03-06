/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:59:21 by sde-mull          #+#    #+#             */
/*   Updated: 2023/03/06 23:45:20 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	get_dimensions(t_map *map, t_line *line)
{
	t_line *curr;
	int		x;
	int 	y;

	curr = line;
	y = 0;
	map->dx = 0;
	while (curr->next)
	{
		x = 0;
		while (curr->y[x++] != '\0');
		if (map->dx < x)
			map->dx = x - 1;
		y++;
		curr = curr->next;
	}
	map->dy = y;
}

//funcao principal para a criacao do mapa

void	save_map(int fd, t_map *map)
{
	t_line	*line;
	t_line  *curr;
	
	line  = malloc(sizeof(t_line));
	curr = line;
	map_start(fd, line);
	while (curr->y)
	{
		insert_node(get_next_line(fd), &line);
		curr = curr->next;
	}
	get_dimensions(map, line);
	//create_array(map, line);
	printf("%d\n%d\n", map->dx, map->dy);
	ft_deallocate(&line);
}

// para salvar a informacao que vem antes do mapa

void	save_info(int fd)
{
	char	*str;
	int		index;

	index = -1;
	while (index++ < 3)
		data()->textures[index] = get_next_line(fd);
	data()->textures[index] = NULL;
	free(get_next_line(fd));
	data()->floor = get_next_line(fd);
	data()->roof = get_next_line(fd); // so meti isto aqui para chegar ao mapa
}

//tenho de mudar o nome desta funcao que nao faz o que o nome diz :P

int	create_map(char *file, t_map *map)
{
	int fd;
	
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (printf("\033[0;31mError:\033[0m %s\n", strerror(errno)));
	save_info(fd);
	save_map(fd, map);
	close(fd);
	return (0);
}

int main(int argc, char *argv[])
{
	t_map map;

	if (check_input(argc - 1, argv[1]))
		return (1);
	init_data_val();
	if (create_map(argv[1], &map))
		return (2);
	free_all();
	return (0);
}