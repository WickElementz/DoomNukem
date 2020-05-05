/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalabidi <yalabidi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:31:43 by yalabidi          #+#    #+#             */
/*   Updated: 2020/05/05 14:58:00 by yalabidi         ###   ########lyon.fr   */
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
# define SENSI      3
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

# define ERR_VALID_DOOR "La porte doit etre entoure de 2 murs seulement"
# define ERR_NUM_DK "Le nombre de clefs doit etre egal au nombre de porte"
# define ERR_LINK_DK "Les portes et / ou clefs ne sont pas link correctement"
# define ERR_START "Il doit y'avoir un point de depart"
# define ERR_END "Il doit y'avoir un point d'arrivee"
# define ERR_WALL "La map doit etre entouree de murs"
# define ERR_WALL2 " et ou avoir une taille de 50x50"
# define ERR_SUP_DK "Il ne doit y'avoir que 10 portes / clefs maximum"

# if defined __linux__
#  define NONE      0
# elif __APPLE__
#  define NONE      -16777216
# endif

#endif
