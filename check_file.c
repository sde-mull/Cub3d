/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:27:53 by sde-mull          #+#    #+#             */
/*   Updated: 2023/03/01 20:32:07 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int	check_file(char *file)
{
	char *ext;

	ext = file;
	if (check_extension(ext))
		return (
		printf("\033[0;31mError:\033[0m File must have .cub extension\n"));
	if (open(file, O_RDONLY) < 0)
		return (printf("\033[0;31mError:\033[0m %s\n", strerror(errno)));
	return (0);
}

int check_input(int n, char *file)
{
	if (n != 1)
		return (
		printf("\033[0;33mRequested input:\033[0m./cub3d file.cub\n"));
	if (check_file(file))
		return (1);
	return (0);
}