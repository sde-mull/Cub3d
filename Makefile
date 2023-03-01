# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 16:25:02 by pcoimbra          #+#    #+#              #
#    Updated: 2023/03/01 16:46:03 by sde-mull         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g #-fsanitize=address 
RM			=	rm -f

NAME		=	cub3D

SRCS		=	cub3d.c check_file.c

OBJS		=	$(patsubst %.c, %.o, $(SRCS))
all:	$(NAME)

$(_OBJ)%.o: $(_SRC)%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(DEPS) $(OBJS)
	@echo	"\033[102m\033[1mExecutable created\033[0m"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@echo	"\033[101m\033[1mObjects cleaned\033[0m"
	@$(RM) -r $(OBJS)

fclean:	clean
	@echo	"\033[101m\033[1mExecutable removed\033[0m"
	@$(RM) -r $(NAME)

re:	fclean all