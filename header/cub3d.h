/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:06:38 by sde-mull          #+#    #+#             */
/*   Updated: 2023/06/13 19:01:28 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "settings.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

//struct da construcao das imagens
typedef struct s_img
{
	void			*mlx_img;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;
	int				imgx;
	int				imgy;
}					t_img;

typedef struct s_extra
{
	int				x;
	int				y;
	int				mx;
	int				my;
	int				sy;
	int				sx;
	unsigned int	dst;
	int				i;
	int				r_row;
	int				wall;
	double			rate;
	double			paint_y;
	double			x_scale;	
}	t_extra;

typedef struct s_engine
{
	double			rx;
	double			ry;
	double			x;
	double			y;
	double			gx;
	double			gy;
	double			dx;
	double			dy;
	double			dist;
	double			angle_diff;
	double			size;
	double			angle;
	int				roof;
	int				floor;
	int				i;
	int				r_row;
	int				wall;
}					t_engine;

typedef struct s_line
{
	char			*y;
	struct s_line	*next;
}					t_line;

typedef struct s_key
{
	int				w;
	int				s;
	int				a;
	int				d;
	int				right;
	int				left;
	int				esc;
	int				m;
}					t_key;

typedef struct s_win
{
	void			*mlx;
	void			*mlx_win;
	int				w;
	int				h;
	t_key			key;
}					t_win;

typedef struct s_map
{
	char			**arr;
	int				dx;
	int				dy;
	int				mx;
	int				my;
}					t_map;

typedef struct s_param
{
	int			ray;
	int			flag;
	int			screen;
	double		angle_diff;
}	t_param;

typedef struct s_player
{
	int				player_x;
	int				player_y;
	double			x1;
	double			y1;
	int				dirx;
	int				diry;
	double			angle;
	double			save_angle;
}					t_player;

typedef struct s_data
{
	char			**textures;
	unsigned int	floor;
	unsigned int	roof;
	t_map			map;
}					t_data;

typedef struct s_objects
{
	double			vwx;
	double			vwy;
	double			vdx;
	double			vdy;
	t_player		player;
	int				w_flags;
	double			w_xtexture;
}					t_objects;

typedef struct s_canvas
{
	t_img			map[3];
	t_img			p_map;
	t_img			game;
	t_img			walls[4];
}					t_canvas;

//another_checker.c
int				check_object(char **map, char c);
int				check_objects(char **map);

//check_file.c
int				ft_str_cmp(char *file, char *str);
int				check_extension(char *file);
int				check_file(char *file);
int				check_input(int n, char *file);

//create_array.c
void			map_start(int fd, t_line *line);
void			get_dimensions(t_map *map);
bool			create_array(t_map *map, t_line *line);
//cub3d.c
int				render(t_win *win);

//drawing.c
void			my_mlx_pixel_put(t_img *data, int x, int y, int color);
unsigned int	my_mlx_get_pixel(t_img *data, int x, int y);
void			draw_map(t_img *map, t_img *img, int countx, int county);
int				check_dir(int x, int y);
void			paint_map(t_win *win);

//drawing2.c
void			draw_front(t_win *win, double angle);
void			draw_image(t_win *win);
void			print_texture(int screen, int i, double paint, int x_scale);
void			draw_screen(t_engine *eng, int *screen, int ray, int index);
void			draw_screen2(t_engine *eng, t_extra *ex, int *screen);

//drawing3.c
void			draw_player(t_win *win, t_img *img, int countx, int county);
void			draw_mini_map(t_win *win);
void			draw_full_map(t_win *win);

//engine.c
void			rays_size(t_win *win, double angle, int *screen, int index);
void			rays_size2(t_engine *eng, double *y, double *x);
void			rays(t_win *win);
void			get_fps(void);
void			get_velocity(void);

//free.c
void			free_win(t_win *win);
int				exit_game(t_win *win);
void			free_array_map(char **arr);
void			free_array(char **arr);
void			free_all(t_map *map);

//images.c
t_img			new_image(t_win *win, int x, int y);
t_img			load_images(t_win *win, char *str);
void			init_images(t_win *win);

//keys.c
int				scan_key(int keycode, t_win *win);
int				scan_key_release(int keycode, t_win *win);
void			check_keys(t_win *win);

//list.c
bool			insert_node(char *str, t_line **line);
void			ft_deallocate(t_line **root);

//map_parser_utils.c
int				map_parser_error(int y, int x);
int				zeros(int x, int y);
int				specific_prompt_error(void);
void			mix(char *no_nl, char *line, int len);

//map_parser1_utils.c
int				floorhuh(int type);
char			*get_map(int fd);
int				texturize(char *line, int *var, int position);
int				check_line_var(char *line, char *comp);
int				check_val(char *line, int *var);

//map_parser1.c
int				get_colour(char **rgb, int *var, int type);
int				add_fc(char *line, int *var, int type);
int				check_name(char *file);
int				parse_vars(int vars, int fd);
int				parse_file(int ac, char **av);

//map_parser2.c
int				add_map(char *line);
int				check_line(char *line, int *player);
int				parse_map(int fd);

//map_parser3.c
int				check_alphanumber(char **rgb);
t_player		get_player(t_map *map);
int				read_info(int fd, t_map *map);
int				check_map(void);

//parser_error.c
int				vars_error(char *line, char *msg);

//save_information.c
void			get_angle(t_player	*objs);
void			get_direction(t_player *objs, int x, int y, t_map *map);

//start.c
void			move(double x, double y);
bool			init_window(t_win *win);
bool			init_game(void);

//utils.c
t_data			*data(void);
t_objects		*obj(void);
t_canvas		*canvas(void);
bool			init_data_val(void);
void			init_obj_val(void);
void			print_map(char **arr);

#endif