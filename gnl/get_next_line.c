/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 11:45:02 by pcoimbra          #+#    #+#             */
/*   Updated: 2021/11/03 13:15:04 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static bool	check_params(int fd)
{
	if (fd < 0)
		return (true);
	if (BUFFER_SIZE <= 0)
		return (true);
	if (read(fd, 0, 0) == -1)
		return (true);
	return (false);
}

static char	*read_file(int fd, char backup[fd], char *buffer)
{
	int		rd;
	char	*temp;

	rd = 1;
	while (rd != 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
		{
			free(buffer);
			return (NULL);
		}
		if (!backup)
			backup = ft_strdup("");
		temp = backup;
		buffer[rd] = '\0';
		backup = ft_strjoin(temp, buffer);
		free (temp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (backup);
}

static char	*format_line(char *unf_lin)
{
	int		count;
	char	*form_lin;

	count = 0;
	while (unf_lin[count] && unf_lin[count] != '\n')
		count++;
	form_lin = (char *)malloc(count + 2);
	if (!form_lin)
		return (NULL);
	ft_strlcpy(form_lin, unf_lin, count + 2);
	if (form_lin[0] == '\0')
	{
		free(form_lin);
		return (NULL);
	}
	return (form_lin);
}

static char	*format_backup(char *backup)
{
	int		nl_ind;
	char	*lin_rem;

	nl_ind = 0;
	while (backup[nl_ind] != '\n' && backup[nl_ind])
		nl_ind++;
	if (backup[nl_ind] == '\0')
	{
		free(backup);
		return (NULL);
	}
	lin_rem = malloc((ft_strlen(backup) - nl_ind) + 1);
	if (!lin_rem)
		return (NULL);
	ft_strlcpy(lin_rem, backup + nl_ind + 1, ft_strlen(backup) - nl_ind + 1);
	free(backup);
	return (lin_rem);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*backup[BUFFER_SIZE];

	if (check_params(fd))
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	backup[fd] = read_file(fd, backup[fd], buffer);
	if (!backup[fd])
		return (NULL);
	line = format_line(backup[fd]);
	backup[fd] = format_backup(backup[fd]);
	return (line);
}
