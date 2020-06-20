/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanne <kanne@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:31:43 by yalabidi          #+#    #+#             */
/*   Updated: 2020/06/20 11:33:34 by kanne            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define BLOCK      64
# define FOV        60
# define WIN_WIDTH  960
# define WIN_HEIGHT 1200.0
# define HORIZON    100
# define SCREEN     831.0
# define SENSIM     1
# define SENSI      5
# define SIZE_MAP   50
# define THREADS    8
# define RAD        0.01745329251

/*
** Color - Editeur
*/

# define FLOOR		0xD39523
# define WALL 		0x727272
# define PANE		0xCECECE
# define DOOR		0x7A511C
# define BEGINNING	0x71C34F
# define ENDING		0x580D0D
# define LIFE		0xC33030
# define AMMO		0xAC9E52
# define GUNNER		0x5F165D
# define PILLAR		0x126B99
# define KEY		0xAF7819
# define CORONA		0xA3C463

/*
** Erreur - Editeur
*/

# define ERR_VALID_DOOR "A door must be surrounded by 2 opposite walls."
# define ERR_NUM_DK "There must be as much keys as doors."
# define ERR_LINK_DK "At least one door or one key needs to be linked."
# define ERR_START "There must be a beginning point."
# define ERR_END "There must be a ending point."
# define ERR_WALL "The map must be surrounded by walls, at every cardinal "
# define ERR_WALL2 "points and must be a 50x50 square."
# define ERR_SUP_DK "There must be a maximum of 10 doors and keys."

# if defined __linux__
#  define NONE      0
# elif __APPLE__
#  define NONE      -16777216
# endif

#endif
