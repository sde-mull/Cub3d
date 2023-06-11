/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   another_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:37:52 by pcoimbra          #+#    #+#             */
/*   Updated: 2023/06/11 18:11:34 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

//dar sort as informacoes
//path
//se ta la tudo
//vai haver espacos
//checar mapa. 1

//para checar vals; checa linha a linha, quando encontrares
//letras, mandar para um val check q precisa de dar check a 6
//tem de haver 6 linhas de shit antes do mapa, mete countdown

//por introduzir

int	check_object(char **map, char c)
{
	int	i;
	int	i2;

	i = 0;
	while (map[i])
	{
		i2 = 0;
		while (map[i][i2] != '\n' && map[i][i2] != c)
			i2++;
		if (map[i][i2] == c)
			return (1);
		i++;
	}
	return (0);
}

int	check_objects(char **map)
{
	if (!check_object(map, 'P'))
		return (0);
	if (!check_object(map, 'C'))
		return (0);
	if (!check_object(map, 'E'))
		return (0);
	return (1);
}
