/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:35:44 by pcoimbra          #+#    #+#             */
/*   Updated: 2023/05/29 16:31:24 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	vars_error(char *line, char *msg)
{
	int	i;

	if (line)
		free(line);
	i = -1;
	while (++i < 4)
		if (data()->textures[i])
			free(data()->textures[i]);
	if (msg)
		printf("%s", msg);
	return (1);
}