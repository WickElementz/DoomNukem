/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   define.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 15:31:43 by yalabidi     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 14:18:56 by jominodi    ###    #+. /#+    ###.fr     */
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

# if defined __linux__
#  define NONE      0
# elif __APPLE__
#  define NONE      -16777216
# endif

#endif
