# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kanne <kanne@student.42lyon.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/11 10:04:45 by jominodi          #+#    #+#              #
#    Updated: 2020/06/23 11:22:24 by kanne            ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME		= doom-nukem
USER		= $(shell whoami)
UNAME		:= $(shell uname)
# MAC
ifeq ($(UNAME), Darwin)
MNLBX		= ./mlx_include_new
MNLBX_A		= $(MNLBX)/libmlx.dylib
FRKS		= -lmlx -framework OpenGL -framework AppKit
endif
# Linux
ifeq ($(UNAME), Linux)
MNLBX		= ./libmlx
MNLBX_A		= $(MNLBX)/libmlx_Linux.a
FRKS 		=  -Llibft -lft -Llibmlx -lmlx -lX11 -lbsd -lm -lpthread -lXext

endif
# fichiers sources du jeu
GAME_P		= src/game
GAME_N		= 	parsing.c \
				event.c \
				sprite.c \
				manage_key.c \
				raycasting.c \
				texture.c \
				texture2.c \
				fire.c \
				init.c \
				error.c \
				bullet_and_life.c \
				manage_mouse.c \
				gun.c \
				hud.c \
				print.c \
				verif_map.c \
				draw.c \
				draw2.c \
				manage_blocks.c \
				animation.c \
				door.c \
				door2.c \
				display.c \
				status.c \
				damage.c \
				tools.c \
				tools2.c \
				main.c \
				gunner.c
# fichiers sources de l'editeur de map
EDIT_P		= src/editor
EDIT_N		= editor.c \
				event_keyboard.c \
				event_mouse.c \
				init_editor.c \
				parser.c \
				print_editor.c \
				verif.c \
				save_key_door.c \
				tab.c \
				blocs.c \
				editor_to_game.c \
				tools_editor.c
# fichiers headers
INC_P		= include/
INC_N		= doom_nukem.h \
				struct.h \
				proto.h \
				define.h
# fichiers objets
OBJ_P_GAME	= objs
OBJ_GAME	= $(GAME_N:.c=.o)
OBJ_P_EDIT	= objs
OBJ_EDIT	= $(EDIT_N:.c=.o)
OBJS		= $(addprefix $(OBJ_P_GAME)/,$(OBJ_GAME))
OBJE		= $(addprefix $(OBJ_P_EDIT)/,$(OBJ_EDIT))
INCS		= $(addprefix $(INC_P)/,$(INC_N))
# sources globales
SRCS		= $(addprefix $(GAME_P)/,$(GAME_N))
SRCS		+= $(addprefix $(EDIT_P)/,$(EDIT_N))
# compilateur, bibliotheques et flags de compilation
GCC			= gcc 
CFLAGS		= -Wall -Wextra
LIB			= librairies
LIBFT		= libft/
LIBFT_A		= $(LIBFT)/libft.a
# couleur et mise en forme de sorties de texte.
WHITE		= \033[37m
GREEN		= \033[32m
COLOR		= \033
BOLD		= \033[1m
BACK_GR		= \033[7;49;32m
START		= $(BOLD)$(BACK_GR)$(WHITE)[START]\c
DONE		= $(BOLD)$(BACK_GR)$(WHITE)[DONE]
all : $(NAME)
$(NAME): $(OBJS) $(OBJE) $(MNLBX_A) $(LIBFT_A)
	@$(GCC) -o $(NAME) $(OBJE) $(OBJS) $(FRKS)
	@echo "$(DONE)"
$(OBJ_P_EDIT)/%.o: $(EDIT_P)/%.c $(INCS)
	@mkdir $(OBJ_P_EDIT) 2> /dev/null || true
	@$(GCC) -Ilibmlx -Ilibft -Iinclude $(CFLAGS) -c $< -o $@
$(OBJ_P_GAME)/%.o: $(GAME_P)/%.c $(INCS)
	@mkdir $(OBJ_P_GAME) 2> /dev/null || true
	@$(GCC) -Ilibmlx -Ilibft -Iinclude $(CFLAGS) -c $< -o $@
$(MNLBX_A) :
	@echo "Compilation: $(START)"
	@make -C $(MNLBX)
$(LIBFT_A) :
	@make -C $(LIBFT)
clean :
	@rm -f $(OBJS)
	@rm -rf $(MNLBX)*.o
	@make -C $(LIBFT) clean
	@rm -rf $(OBJ_P_GAME) 2>/dev/null || true
	@echo "Clean: $(DONE)"
fclean :
	@make -C $(LIBFT) fclean
	@make -C $(MNLBX) clean
	@rm -f $(NAME)
	@rm -rf $(OBJ_P_GAME)
	@rm -rf libmlx.dylib
	@echo "Extra maked files got successfully $(BOLD)$(GREEN)deleted$(WHITE)"
re : fclean all
