# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: videloff <videloff@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/12/10 15:05:58 by jominodi     #+#   ##    ##    #+#        #
#    Updated: 2020/01/10 15:18:01 by videloff    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME		= doom-nukem
USER		= $(shell whoami)
UNAME		:= $(shell uname)

ifeq ($(UNAME), Darwin)
MNLBX		= ./mlx_include
MNLBX_A		= $(MNLBX)/libmlx.a
FRKS		= -lmlx -framework OpenGL -framework AppKit
endif

ifeq ($(UNAME), Linux)
MNLBX		= ./minilibx
MNLBX_A		= $(MNLBX)/libmlx.a
FRKS 		=  minilibx/libmlx.a `gnustep-config --objc-flags` -lgnustep-base -lGL -lXext -lX11 -lm
endif

SRC_P		= src
SRC_N		= main.c \
				parsing.c \
				save_map.c \
				event.c \
				manage_key.c \
				raycasting.c \
				texture.c \
				error.c \
				draw.c
INC_P		= include/
INC_N		= doom_nukem.h \
				struct.h \
				proto.h \
				define.h
OBJ_P		= ./objs
OBJ_N		= $(SRC_N:.c=.o)
SRCS		= $(addprefix $(SRC_P)/,$(SRC_N))
INCS		= $(addprefix $(INC_P)/,$(INC_N))
OBJS		= $(addprefix $(OBJ_P)/,$(OBJ_N))

GCC			= gcc
CFLAGS		= -Wall -Werror -Wextra
LIB			= librairies
LIBFT		= libft/
LIBFT_A		= $(LIBFT)/libft.a

CLEAR		= \033[0m
GREEN		= \033[33m
COLOR		= \033
BOLD		= \033[1m
START		= $(BOLD)\033[43m[START]$(CLEAR)\c
DONE		= $(BOLD)\033[43m[DONE]$(CLEAR)

all : $(NAME)
$(NAME): $(OBJS) $(MNLBX_A) $(LIBFT_A)
	@$(GCC) -I $(MNLBX) -L $(MNLBX) $^ -o $@ -I $(LIBFT) $(FRKS)
	@echo "$(DONE)"
$(OBJ_P)/%.o: $(SRC_P)/%.c $(INCS)
	@mkdir $(OBJ_P) 2> /dev/null || true
	@$(GCC) -I $(MNLBX) -I $(LIBFT) -I $(INC_P) $(CFLAGS) -c $< -o $@
$(MNLBX_A) :
	@echo "Compilation: $(START)"
	@make -C $(MNLBX)
$(LIBFT_A) :
	@make -C $(LIBFT)

clean :
	@rm -f $(OBJS)
	@rm -rf $(MNLBX)*.o
	@make -C $(LIBFT) clean
	@rm -rf $(OBJ_P) 2>/dev/null || true
	@echo "Clean: $(BOLD)$(GREEN)[DONE]$(CLEAR)"

fclean :
	@make -C $(LIBFT) fclean
	@make -C $(MNLBX) clean
	@rm -f $(NAME)
	@rm -rf $(OBJ_P)
	@echo "Extra maked files got successfully $(BOLD)$(GREEN)deleted$(CLEAR)"

re : fclean all