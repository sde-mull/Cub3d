/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:35:44 by pcoimbra          #+#    #+#             */
/*   Updated: 2023/06/13 17:33:38 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	vars_error(char *line, char *msg)
{
	int	i;

	if (line)
		free(line);
	i = -1;
	if (data()->textures)
		free_array(data()->textures);
	if (msg)
		printf("%s", msg);
	return (1);
}
