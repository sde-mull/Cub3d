/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:27:53 by sde-mull          #+#    #+#             */
/*   Updated: 2023/03/01 20:01:52 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_input(int n, char *file)
{
	if (n != 1)
		return (printf("\033[0;33mRequested input:\033[0m./cub3d file.cub\n"));
	return (0);
}