/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   define.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 15:31:43 by yalabidi     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 14:55:07 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define BLOCK      64
# define FOV        60
# define WIN_WIDTH  960
# define WIN_HEIGHT 1200
# define HORIZON    100
# define SCREEN     831
# define SENSI      3

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



# if defined __linux__
#  define NONE      0
# elif __APPLE__
#  define NONE      -16777216
# endif

#endif
