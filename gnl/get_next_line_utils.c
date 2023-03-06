/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 11:19:34 by pcoimbra          #+#    #+#             */
/*   Updated: 2023/03/06 16:52:46 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_checknl(char *buff)
{
	int	i;
	int	j;
	int	is_new_line;

	i = -1;
	is_new_line = 0;
	j = 0;
	while (buff[++i])
	{
		if (is_new_line)
			buff[j++] = buff[i];
		if (buff[i] == '\n')
			is_new_line = 1;
		buff[i] = 0;
	}
	return (is_new_line);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] != '\n' && str[len])
		len++;
	return (len + (str[len] == '\n'));
}

char	*ft_get_line(char *buff, char *line)
{
	int		i;
	int		j;
	int		buff_size;
	char	*new_line;

	buff_size = ft_strlen(buff);
	new_line = malloc((buff_size + ft_strlen(line) + 1) * sizeof(char));
	if (!new_line)
		return (NULL);
	i = -1 * (line != NULL);
	while (line && line[++i])
		new_line[i] = line[i];
	j = 0;
	while (j < buff_size)
		new_line[i++] = buff[j++];
	new_line[i] = '\0';
	if (line)
		free(line);
	return (new_line);
}
