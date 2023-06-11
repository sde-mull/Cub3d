/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 11:45:02 by pcoimbra          #+#    #+#             */
/*   Updated: 2023/06/11 19:26:32 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			byte_read;
	static char	buff[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || fd >= FOPEN_MAX)
		return (NULL);
	line = NULL;
	byte_read = 1;
	while (1)
	{
		if (!buff[0])
			byte_read = read(fd, buff, BUFFER_SIZE);
		if (byte_read > 0)
			line = ft_get_line(buff, line);
		if (ft_checknl(buff) || byte_read < 1)
			break ;
	}
	return (line);
}
