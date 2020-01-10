# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/12/10 15:05:58 by jominodi     #+#   ##    ##    #+#        #
#    Updated: 2020/01/10 14:17:36 by jominodi    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME		= wolf3d
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
INC_N		= wolf3d.h \
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


all : $(NAME)
$(NAME): $(OBJS) $(MNLBX_A) $(LIBFT_A)
	@$(GCC) -I $(MNLBX) -L $(MNLBX) $^ -o $@ -I $(LIBFT) $(FRKS)
	@echo "Compilation: \033[36m\033[1m[DONE]\033[0m"
$(OBJ_P)/%.o: $(SRC_P)/%.c $(INCS)
	@mkdir $(OBJ_P) 2> /dev/null || true
	@$(GCC) -I $(MNLBX) -I $(LIBFT) -I $(INC_P) $(CFLAGS) -c $< -o $@
$(MNLBX_A) :
	@make -C $(MNLBX)
$(LIBFT_A) :
	@echo "Compilation: \033[36m\033[1m[START]\033[0m"
	@make -C $(LIBFT)

clean :
	@rm -f $(OBJS)
	@rm -rf $(MNLBX)*.o
	@make -C $(LIBFT) clean
	@rm -rf $(OBJ_P) 2>/dev/null || true
	@echo "Clean: \033[36m\033[1m[DONE]\033[0m"

fclean :
	@make -C $(LIBFT) fclean
	@make -C $(MNLBX) clean
	@rm -f $(NAME)
	@rm -rf $(OBJ_P)
	@echo "Extra maked files got successfully \033[33m\033[1mdeleted\033[0m"

re : fclean all