NAME = libft.a

SRCS = ft_memset.c   ft_strlcat.c     \
           ft_bzero.c    ft_strnstr.c     \
           ft_memcpy.c   ft_atoi.c        \
           ft_memmove.c  ft_calloc.c      \
           ft_memchr.c   ft_strdup.c      \
           ft_memcmp.c   ft_substr.c      \
           ft_strlen.c   ft_strjoin.c     \
           ft_isalpha.c  ft_strtrim.c     \
           ft_isdigit.c  ft_split.c       \
           ft_isalnum.c  ft_itoa.c        \
           ft_isascii.c  ft_strmapi.c     \
           ft_isprint.c  ft_putchar_fd.c  \
           ft_toupper.c  ft_putstr_fd.c   \
           ft_tolower.c  ft_putendl_fd.c  \
           ft_strchr.c   ft_putnbr_fd.c   \
           ft_strrchr.c  ft_strncmp.c     \
           ft_striteri.c ft_strlcpy.c     \
           
INCLUDE = libft.h

OBJ = $(SRCS:.c=.o)

BONUS_S	= ft_lstsize.c ft_lstlast.c ft_lstadd_front.c ft_lstadd_back.c \
			ft_lstnew.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c 
BONUS_O	= $(BONUS_S:.c=.o)

CC = gcc

CFLAGS = -Wall    \
         -Wextra  \
         -Werror  \

GREEN = 	\033[0;32m
YELLOW = 	\033[0;33m
RED = 		\033[0;31m
RESET = 	\033[0m

all: $(NAME)

$(NAME): $(OBJ) $(BONUS_O) $(INCLUDE)
		@echo "$(YELLOW)[Compiling Libft...] $(RESET)"
		@ar -rcs $(NAME) $(OBJ)
		@ar -rcs $(NAME) $(BONUS_O)
		@echo "$(GREEN)[Libft Compiled!] $(RESET)"

mandatory: $(OBJ) $(INCLUDE)
			@echo "$(YELLOW)[Compiling_Mandatory Libft...] $(RESET)"
			@ar -rcs $(NAME) $(OBJ)
			@echo "$(GREEN)[Libft_Mandatory Compiled!] $(RESET)"

bonus:		$(BONUS_O) $(INCLUDE)
			@echo "$(YELLOW)[Compiling Libft_Bonus...] $(RESET)"
			@ar -rcs $(NAME) $(BONUS_O)
			@echo "$(GREEN)[Libft_Bonus Compiled!] $(RESET)"

%.o: %.c $(INCLUDE)
		@$(CC) $(CFLAGS) -c $< -o $@

clean: 
		@rm -rf $(OBJ) $(BONUS_O)
		@echo "$(GREEN)[Libft Cleaned] $(RESET)"

fclean:	
		@rm -rf $(OBJ) $(BONUS_O) $(NAME)
		@echo "$(GREEN)[Libft Full Cleaned] $(RESET)"

re: fclean all

remandatory: fclean mandatory

rebonus:	fclean bonus

.PHONY: all mandatory bonus clean fclean re remandatory rebonus 