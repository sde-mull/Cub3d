# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 16:25:02 by pcoimbra          #+#    #+#              #
#    Updated: 2023/03/21 19:49:46 by sde-mull         ###   ########.fr        #
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

SOURCE_DIR	=	src/
SOURCE_F	=	check_file.c create_array.c cub3D.c free.c list.c save_information.c utils.c
SRCS		=	$(addprefix $(SOURCE_DIR), $(SOURCE_F))
GET_DIR 	=	gnl
LIBFT		=	libft
DEPS		=	./minilibx-linux/libmlx_Linux.a

_MLX		=	./minilibx-linux
_MLX_FLAGS  =	-Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

MAP 		= 	game.cub

VALGRIND	= 	valgrind
VFLAGS		= 	--leak-check=full --show-leak-kinds=all

OBJDIR		= 	obj
OBJS		=	$(SRCS:.c=.o)

all:	$(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJS): %.o:%.c
	@$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@


$(NAME): $(DEPS) $(OBJDIR) $(OBJS) 
	@echo	"\033[102m\033[1mExecutable created\033[0m"
	@$(MAKE) -C $(LIBFT)
	@$(CC) $(CFLAGS) $(_MLX_FLAGS) $(OBJS) $(GET_DIR)/*.c $(FT_INCLUDE) -o $(NAME) $(INCLUDE) -L $(_MLX)

$(DEPS):
	@cd minilibx-linux;./configure

init: all
	./$(NAME) $(MAP)	

val: re
	$(VALGRIND) $(VFLAGS) ./$(NAME) $(MAP)

clean:
	@echo	"\033[101m\033[1mObjects cleaned\033[0m"
	@$(CD) $(LIBFT) && make clean
	@$(RM) -r $(OBJDIR)/$(OBJS)
	@$(RM) -rf $(OBJDIR)
	@$(CD) $(_MLX); make clean

fclean:	clean
	@echo	"\033[101m\033[1mExecutable removed\033[0m"
	@$(CD) $(LIBFT) && make fclean
	@$(RM) -r $(NAME)
	@$(RM) -r $(_MLX)libmlx_Linux.a

re:	fclean all

.PHONY: all clean init val fclean re