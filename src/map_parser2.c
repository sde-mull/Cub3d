/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:52:48 by pcoimbra          #+#    #+#             */
/*   Updated: 2023/05/29 18:28:52 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	add_map(char *line)
{
	char	**map;
	int		i;

	i = 0;
	while (data()->map.arr && data()->map.arr[i])
		i++;
	map = malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (data()->map.arr && data()->map.arr[i])
	{
		map[i] = data()->map.arr[i];
		i++;
	}
	map[i] = line;
	map[i + 1] = 0;
	if (data()->map.arr)
		free(data()->map.arr);
	data()->map.arr = map;
	// free_array (map);
	return (0);
}

int	check_line(char *line, int *player)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'E' && \
		line[i] != 'W' && line[i] != 'S' && line[i] != 'N' && \
		line[i] != ' ' )
		{
			printf ("Error\nMap contains forbidden char in line:\n%s", line);
			printf ("\n%c\n", line[i]);
			free(line);
			return (1);
		}
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E' \
		|| line[i] == 'W')
			*player += 1;
		if (*player > 1)
		{
			free(line);
			printf("Error\nToo many players\n");
			return (1);
		}
	}
	return (0);
}

int	parse_map(int fd)
{
	char		*line;
	static int	player;

	player = 0;
	line = get_map(fd);
	while (line)
	{
		if (check_line(line, &player))
		{
			if (data()->map.arr)
				free_array(data()->map.arr);
			return (1);
		}
		else
			add_map(line);
		line = get_map(fd);
	}
	if (!player)
	{
		printf("Error\nMap needs to have a player position\n");
		if (data()->map.arr)
			free_array(data()->map.arr);
		return (1);
	}
	return (0);
}
