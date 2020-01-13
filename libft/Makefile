# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: videloff <videloff@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/05 15:42:02 by videloff     #+#   ##    ##    #+#        #
#    Updated: 2020/01/13 12:00:53 by videloff    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = libft.a
		
CC = gcc

INC			= ./includes/
INC_N		= $(INC)fractol.h

CFLAGS = -Wextra -Werror -Wall

SRC	= ft_memset.c\
	ft_bzero.c\
	ft_memcpy.c\
	ft_memccpy.c\
	ft_memmove.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_strncpy.c\
	ft_strcat.c\
	ft_strncat.c\
	ft_strlcat.c\
	ft_strchr.c\
	ft_strrchr.c\
	ft_strstr.c\
	ft_strnstr.c\
	ft_strcmp.c\
	ft_strcpy.c\
	ft_strdup.c\
	ft_strlen.c\
	ft_strncmp.c\
	ft_atoi.c\
	ft_isalpha.c\
	ft_isdigit.c\
	ft_isalnum.c\
	ft_isascii.c\
	ft_isprint.c\
	ft_toupper.c\
	ft_tolower.c\
	ft_memalloc.c\
	ft_memdel.c\
	ft_strnew.c\
	ft_strdel.c\
	ft_strclr.c\
	ft_striter.c\
	ft_striteri.c\
	ft_strmap.c\
	ft_strmapi.c\
	ft_strequ.c\
	ft_strnequ.c\
	ft_strsub.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_strsplit.c\
	ft_itoa.c\
	ft_putchar.c\
	ft_putstr.c\
	ft_putendl.c\
	ft_putnbr.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	ft_lstnew.c\
	ft_lstdelone.c\
	ft_lstdel.c\
	ft_lstadd.c\
	ft_lstiter.c\
	ft_lstmap.c\
	ft_countword.c\
	ft_isspace.c\
	ft_swap.c\
	ft_strcapitalize.c\
	ft_sqrt.c\
	ft_strlen_chr.c\
	get_next_line.c
OBJ	= $(SRC:.c=.o)

WHITE		= \033[0m
GREEN		= \033[32m
COLOR		= \033
BOLD		= \033[1m
BACK_GR		= \033[7;49;32m
SQUARE		= $(BOLD)$(BACK_GR)\033[43m $(WHITE)

all: $(NAME)

$(NAME): $(OBJ)

%.o:%.c
	@echo "$(SQUARE)\c"
	@$(CC) $(CFLAGS) -c $^ -o $@
	@ar rc $(NAME) $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

