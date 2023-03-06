/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:06:38 by sde-mull          #+#    #+#             */
/*   Updated: 2023/03/06 20:59:17 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>

typedef struct s_line
{
    char *y;
    struct s_line *next;
} t_line;

typedef struct s_data
{
    char **textures;
    char *floor;
    char *roof;
}   t_data;

typedef struct s_map
{
    char    **array;
    int     dx;
    int     dy;
}   t_map;

int         check_input(int n, char *file);
int	        check_file(char *file);
int	        check_extension(char *file);
int	        ft_str_cmp(char *file, char *str);
t_data	    *data(void);
void	    init_data_val(void);
void        free_array(char **arr);
void	    save_info(int fd);
int	        create_map(char *file, t_map *map);
void        save_map(int fd, t_map *map);
void        ft_deallocate(t_line **root);
void	    free_all(void);
void	    insert_node(char *str, t_line **line);

#endif