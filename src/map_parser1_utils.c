/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser1_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:25:17 by pcoimbra          #+#    #+#             */
/*   Updated: 2023/06/13 19:01:53 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	floorhuh(int type)
{
	if (type == SKY && data()->roof)
	{
		printf("Error\nDuplicated definition of colour\n");
		return (1);
	}
	if (type == FLOOR && data()->floor)
	{
		printf("Error\nDuplicated definition of colour\n");
		return (1);
	}
	return (0);
}

char	*get_map(int fd)
{
	char	*line;
	char	*no_nl;
	int		len;

	line = get_next_line(fd);
	if (!line || (!ft_strchr(line, '\n')))
		return (line);
	len = ft_strlen(line);
	no_nl = malloc(sizeof(char) * len);
	if (!no_nl)
	{
		free(line);
		return (NULL);
	}
	mix(no_nl, line, len);
	free(line);
	return (no_nl);
}

int	texturize(char *line, int *var, int position)
{
	if (data()->textures[position])
	{
		printf("Error\nThere are two or more of this Texture \
			textures:%s\n", line);
		return (1);
	}
	data()->textures[position] = ft_strdup(line + 3);
	*var -= 1;
	free(line);
	return (0);
}

int	check_line_var(char *line, char *comp)
{
	int	ind;
	int	dnd;
	int	jnd;

	ind = 0;
	dnd = 0;
	if (!line)
		return (1);
	while (line[ind] == ' ' && line[ind] != '\0')
		ind++;
	jnd = ft_strlen(comp) + ind;
	while (ind < jnd)
	{
		if (line[ind] == comp[dnd])
		{
			ind++;
			dnd++;
		}
		else
			return (1);
	}
	return (0);
}

int	check_val(char *line, int *var)
{
	if (!ft_strlen(line))
	{
		free (line);
		return (0);
	}
	if (!check_line_var(line, "NO "))
		return (texturize(line, var, 0));
	if (!check_line_var(line, "EA "))
		return (texturize(line, var, 2));
	if (!check_line_var(line, "SO "))
		return (texturize(line, var, 1));
	if (!check_line_var(line, "WE "))
		return (texturize(line, var, 3));
	if (!check_line_var(line, "F "))
		return (add_fc(line, var, FLOOR));
	if (!check_line_var(line, "C "))
		return (add_fc(line, var, SKY));
	printf ("Error\nLine does not match any variable\n");
	return (1);
}
