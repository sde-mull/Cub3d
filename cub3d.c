/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:59:21 by sde-mull          #+#    #+#             */
/*   Updated: 2023/03/06 16:54:15 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_array(char **arr)
{
	int index;

	index = 0;
	while (arr[index])
		free (arr[index++]);
	free (arr);
}

void	save_info(int fd, t_map *map)
{
	char	*str;
	int		index;

	index = -1;
	while (index++ < 3)
		data()->textures[index] = get_next_line(fd);
	data()->textures[index] = NULL;
}

int	create_map(char *file, t_map *map)
{
	int fd;
	
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (printf("\033[0;31mError:\033[0m %s\n", strerror(errno)));
	save_info(fd, map);
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
	free_array(data()->textures);
	return (0);
}