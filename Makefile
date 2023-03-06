# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 16:25:02 by pcoimbra          #+#    #+#              #
#    Updated: 2023/03/06 16:35:13 by sde-mull         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc
CFLAGS		=	-g #-fsanitize=address
RM			=	rm -f

NAME		=	cub3D

SRCS		=	cub3d.c check_file.c utils.c 
GET_DIR =	gnl

OBJS		=	$(patsubst %.c, %.o, $(SRCS))
all:	$(NAME)

$(_OBJ)%.o: $(_SRC)%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(DEPS) $(OBJS)
	@echo	"\033[102m\033[1mExecutable created\033[0m"
	@$(CC) $(CFLAGS) $(OBJS) $(GET_DIR)/*.c -o $(NAME)

clean:
	@echo	"\033[101m\033[1mObjects cleaned\033[0m"
	@$(RM) -r $(OBJS)

fclean:	clean
	@echo	"\033[101m\033[1mExecutable removed\033[0m"
	@$(RM) -r $(NAME)

re:	fclean all