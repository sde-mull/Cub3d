# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 16:25:02 by pcoimbra          #+#    #+#              #
#    Updated: 2023/03/08 16:25:28 by sde-mull         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --silent

CC			=	cc
CFLAGS		=	-g #-fsanitize=address
RM			=	rm -f
CD			=	cd

NAME		=	cub3D
INCLUDE		=	-I ./ minilibx-linux/libmlx_Linux.a
FT_INCLUDE 	= 	-Ilibft -Llibft -lft

SRCS		=	$(shell find -maxdepth 1 -type f -name "*.c")
GET_DIR 	=	gnl
LIBFT		=	libft
DEPS		=	./minilibx-linux/libmlx_Linux.a

_MLX		=	./minilibx-linux
_MLX_FLAGS  =	-Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

OBJS		=	$(patsubst %.c, %.o, $(SRCS))


all:	$(NAME)

$(_OBJ)%.o: $(_SRC)%.c
	@$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(DEPS) $(OBJS) 
	@echo	"\033[102m\033[1mExecutable created\033[0m"
	@$(MAKE) -C $(LIBFT)
	@$(CC) $(CFLAGS) $(_MLX_FLAGS)  $(OBJS) $(GET_DIR)/*.c $(FT_INCLUDE) -o $(NAME) $(INCLUDE) -L $(_MLX)

$(DEPS):
	@cd minilibx-linux;./configure

clean:
	@echo	"\033[101m\033[1mObjects cleaned\033[0m"
	@$(CD) $(LIBFT) && make clean
	@$(RM) -r $(OBJS)
	@$(CD) $(_MLX); make clean

fclean:	clean
	@echo	"\033[101m\033[1mExecutable removed\033[0m"
	@$(CD) $(LIBFT) && make fclean
	@$(RM) -r $(NAME)
	@$(RM) -r $(_MLX)libmlx_Linux.a

re:	fclean all