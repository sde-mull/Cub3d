/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:06:38 by sde-mull          #+#    #+#             */
/*   Updated: 2023/03/22 17:52:24 by sde-mull         ###   ########.fr       */
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
# include <stdbool.h>
# include "minilibx-linux/mlx.h"

#define WIN_ERROR false

#define WIN_X 1920/1.5
#define WIN_Y 1080/1.5

# define UP 119
# define LEFT 97
# define RIGHT 100
# define DOWN 115
# define CLOSE 65307
# define EQUAL 61
# define MINUS 45
# define SHIFT 65506
 
typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_line
{
    char *y;
    struct s_line *next;
} t_line;

typedef struct s_key
{
	int	w;
	int	s;
	int	a;
	int	d;
	int	esc;
}   t_key;
 
typedef struct s_win
{
    void	*mlx;
	void	*mlx_win;
    int     w;
    int     h;
    t_key   key;
    t_img	img;
} t_win;


typedef struct s_map
{
    char    **arr;
    int     dx;
    int     dy;
}   t_map;

typedef struct s_data
{
    char    **textures;
    char    *floor;
    char    *roof;
    t_map   map;
}   t_data;



int         check_input(int n, char *file);
int	        check_file(char *file);
int	        check_extension(char *file);
int	        ft_str_cmp(char *file, char *str);
t_data	    *data(void);
bool	    init_data_val(void);
void        free_array(char **arr);
void	    save_info(int fd);
int	        read_info(char *file, t_map *map);
bool        save_map(int fd, t_map *map);
void        ft_deallocate(t_line **root);
void	    free_all(t_map *map);
bool	    insert_node(char *str, t_line **line);
void	    print_map(char **arr);

#endif