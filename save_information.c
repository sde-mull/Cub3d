/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_information.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:21:12 by sde-mull          #+#    #+#             */
/*   Updated: 2023/03/07 18:28:14 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int	read_info(char *file, t_map *map)
{
	int fd;
	
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (printf("\033[0;31mError:\033[0m %s\n", strerror(errno)));
	save_info(fd);
	if (!save_map(fd, map))
		return (printf("\033[0;31mError:\033[0m %s\n", strerror(errno)));
	close(fd);
	return (0);
}