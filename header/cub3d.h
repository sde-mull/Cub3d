/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:06:38 by sde-mull          #+#    #+#             */
/*   Updated: 2023/04/03 20:42:16 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include "settings.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <stdbool.h>
# include <math.h>
 
 //struct da construcao das imagens
typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
    int     imgx;
    int     imgy;
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
} t_win;

//struct do mapa(dx tamanho do mapa no eixo x, dy tamanho do mapa no eixo y, arr array do mapa)
typedef struct s_map
{
    char    **arr;
    int     dx;
    int     dy;
}   t_map;

typedef struct s_player
{
    int     player_x;
    int     player_y;
    double  x1;
    double  y1;
    double   dirx;
    double   diry;
}   t_player;

//struct com informacoes gerais(mapa, texturas, etc)
typedef struct s_data
{
    char    **textures;
    char    *floor;
    char    *roof;
    t_map   map;
}   t_data;
typedef struct s_objects
{
    t_player player;
} t_objects;

typedef struct s_canvas
{
    t_img map[3];
    t_img p_map;
} t_canvas;


//start.c
bool	    init_window(t_win *win);
bool        init_game(void);

//keys.c
void	    init_struct(t_win *win);
int         scan_key(int keycode, t_win *win);
int         scan_key_release(int keycode, t_win *win);

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


//utils.c
t_data	    *data(void);
t_objects   *obj(void);
bool	    init_data_val(void);
void	    init_obj_val(void);
void	    print_map(char **arr);

//drawing.c
void	        my_mlx_pixel_put(t_img *data, int x, int y, int color);
unsigned int	my_mlx_get_pixel(t_img *data, int x, int y);
void	        draw_map(t_img *map, t_img *img, int countx, int county);
void	        paint_map(t_win *win);
void	        draw_player(t_win *win, t_img *img, int countx, int county);

//drawing2.c
void    draw_front(t_win *win);
void    draw_image(t_win *win);

//images.c
void	init_images(t_win *win);


//
int		    render(t_win *win);
void	    move(double x, double y);
void	    print_front(t_win *win);
void        init_address(t_win *win);
t_canvas    *canvas(void);
t_img	load_images(t_win *win,char *str);
t_img	new_image(t_win *win, int x, int y);
#endif