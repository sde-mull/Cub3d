# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 16:25:02 by pcoimbra          #+#    #+#              #
#    Updated: 2023/03/07 17:10:17 by sde-mull         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc
CFLAGS		=	-g #-fsanitize=address
RM			=	rm -f
CD			=	cd

NAME		=	cub3D

SRCS		=	cub3d.c check_file.c utils.c list.c free.c
GET_DIR 	=	gnl
LIBFT		=	libft

OBJS		=	$(patsubst %.c, %.o, $(SRCS))
all:	$(NAME)

$(_OBJ)%.o: $(_SRC)%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(DEPS) $(OBJS)
	@echo	"\033[102m\033[1mExecutable created\033[0m"
	@$(MAKE) -C $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(GET_DIR)/*.c $(LIBFT)/libft.a -o $(NAME)

clean:
	@echo	"\033[101m\033[1mObjects cleaned\033[0m"
	@$(CD) $(LIBFT) && make clean
	@$(RM) -r $(OBJS)

fclean:	clean
	@echo	"\033[101m\033[1mExecutable removed\033[0m"
	@$(CD) $(LIBFT) && make fclean
	@$(RM) -r $(NAME)

re:	fclean all