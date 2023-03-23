/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:06:38 by sde-mull          #+#    #+#             */
/*   Updated: 2023/03/23 00:24:49 by sde-mull         ###   ########.fr       */
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
 

 //struct da construcao das imagens
typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

//lista utilizada para a concretizacao do array do mapa
typedef struct s_line
{
    char *y;
    struct s_line *next;
} t_line;

//struct das keys
typedef struct s_key
{
	int	w;
	int	s;
	int	a;
	int	d;
	int	esc;
}   t_key;
 
//struct da janela que e aberta
typedef struct s_win
{
    void	*mlx;
	void	*mlx_win;
    int     w;
    int     h;
    t_key   key;
    t_img	img;
} t_win;

//struct do mapa(dx tamanho do mapa no eixo x, dy tamanho do mapa no eixo y, arr array do mapa)
typedef struct s_map
{
    char    **arr;
    int     dx;
    int     dy;
}   t_map;

//struct com informacoes gerais(mapa, texturas, etc)
typedef struct s_data
{
    char    **textures;
    char    *floor;
    char    *roof;
    t_map   map;
}   t_data;


//check_file.c
int         check_input(int n, char *file);
int	        check_file(char *file);
int	        check_extension(char *file);
int	        ft_str_cmp(char *file, char *str);

//create_array.c
void	    map_start(int fd, t_line *line);
void	    get_dimensions(t_map *map, t_line *line);
bool	    create_array(t_map *map, t_line *line);
bool	    save_map(int fd, t_map *map);

//free.c
void        free_array(char **arr);
void	    free_all(t_map *map);
int         exit_game(t_win *win);
void        ft_deallocate(t_line **root);
void        free_win(t_win *win);

//list.c
bool	    insert_node(char *str, t_line **line);

//save_information.c
void	    save_info(int fd);
int	        read_info(char *file, t_map *map);

//start.c
bool	    init_window(t_win *win);
bool        init_game(void);
void	    init_struct(t_win win);
int         scan_key(int keycode, t_win *win);
int         scan_key_release(int keycode, t_win *win);

//utils.c
t_data	    *data(void);
bool	    init_data_val(void);
void	    print_map(char **arr);

//
int		    render(t_win *win);

#endif