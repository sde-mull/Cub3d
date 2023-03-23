/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:27:53 by sde-mull          #+#    #+#             */
/*   Updated: 2023/03/23 16:37:16 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

//compara estritamente caracter a caracter

int	ft_str_cmp(char *file, char *str)
{
	int index;

	index = 0;
	if (!file || !str)
		return (1);
	while (file[index] || str[index])
	{
		if (file[index] != str[index])
			return (1);
		index++;
	}
	return (0);
}

//da check na extensao final

int	check_extension(char *file)
{
	int index;

	index = -1;
	while (*file != '.' && file)
		file++;
	if (!file[index])
		return (1);
	if (ft_str_cmp(file, ".cub"))
		return (1);
	return (0);
}

//check no file que mandamos

int	check_file(char *file)
{
	char *ext;

	ext = file;
	if (check_extension(ext))
		return (
		printf("\033[0;31mError:\033[0m File must have .cub extension\n"));
	return (0);
}

//check no input se sao mais ficheiros de que devia etc

int check_input(int n, char *file)
{
	if (n != 1)
		return (
		printf("\033[0;33mRequested input:\033[0m./cub3d file.cub\n"));
	if (check_file(file))
		return (1);
	return (0);
}