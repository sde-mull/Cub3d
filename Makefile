# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 16:25:02 by pcoimbra          #+#    #+#              #
#    Updated: 2023/03/01 15:39:16 by sde-mull         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g #-fsanitize=address 
RM			=	rm -f

NAME		=	cub3D

INCLUDE		=	-I ./ mlx-linux/libmlx_Linux.a

SRCS_		=

SRCS		=	$(addprefix $(_SRC), $(SRCS_))

DEPS		=	./mlx-linux/libmlx_Linux.a

_SRC		=	./src/
_MLX		=	./mlx-linux

OBJS		=	$(patsubst %.c, %.o, $(SRCS))
all:	$(NAME)

$(_OBJ)%.o: $(_SRC)%.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz $(OBJS) -o $(NAME) $(INCLUDE) -L $(_MLX)

./mlx-linux/libmlx_Linux.a:
	cd mlx-linux;./configure

$(_OBJ):
	mkdir $@

clean:
	$(RM) -r $(OBJS)
	cd mlx-linux; make clean

fclean:	clean
	$(RM) -r $(NAME)
	$(RM) -r $(_MLX)libmlx_Linux.a

re:	fclean all