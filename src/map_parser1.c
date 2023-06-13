/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:33:18 by pcoimbra          #+#    #+#             */
/*   Updated: 2023/06/13 19:42:37 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

//E PRECISO MUDAR O T_DATA PARA UNSIGNED INT PARA FUNFAR

int	get_colour(char **rgb, int *var, int type)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	free_array(rgb);
	if (r > 255 || r < 0 || g > 255 || g < 0 || b > 255 || b < 0)
	{
		printf("Error\nRBG color values need to be >= 0 && <= 255\n");
		return (1);
	}
	if (type == FLOOR)
		data()->floor = (r << 16) + (g << 8) + b;
	if (type == SKY)
		data()->roof = (r << 16) + (g << 8) + b;
	*var -= 1;
	return (0);
}

int	add_fc(char *line, int *var, int type)
{
	char	**rgb;
	int		i;

	i = 0;
	if (floorhuh(type))
		return (1);
	rgb = ft_split(line + 2, ',');
	while (rgb[i])
		i++;
	if (i != 3 || check_alphanumber(rgb))
	{
		free_array(rgb);
		printf("Error\nInvalid colour format\n");
		return (1);
	}
	if (!get_colour(rgb, var, type))
	{
		free(line);
		return (0);
	}
	return (1);
}

int	check_name(char *file)
{
	int	index;

	index = ft_strlen(file);
	while (file[index] != '.' && file[index])
		index--;
	if (!file[index])
		return (1);
	while (*file != file[index] && file)
		file++;
	if (ft_str_cmp(file, ".cub"))
		return (1);
	return (0);
}

int	parse_vars(int vars, int fd)
{
	char	*line;
	int		line_count;

	line_count = 0;
	while (vars)
	{
		line = get_map(fd);
		line_count++;
		if (!line)
		{
			close(fd);
			printf ("The program read %d lines.", line_count);
			vars_error(line, "Error\nMap not correctly configured\n");
			return (1);
		}
		if (check_val(line, &vars))
		{
			vars_error(line, NULL);
			close (fd);
			printf("The program read %d lines.", line_count);
			return (1);
		}
	}
	return (0);
}

int	parse_file(int ac, char **av)
{
	int	fd;

	if (ac != 2)
	{
		printf("Invaled input, too many arguments\n");
		return (1);
	}
	if (!check_name(av[1]))
		return (1);
	fd = open(av[1], O_RDONLY);
	if (parse_vars(6, fd))
		return (1);
	if (parse_map(fd) || check_map())
		return (specific_prompt_error());
	if (read_info(fd, &data()->map))
	{
		if (data()->map.arr)
			free_array(data()->map.arr);
		return (1);
	}
	close(fd);
	return (0);
}
