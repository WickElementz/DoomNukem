/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   doom_nukem.h                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: videloff <videloff@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/01 11:03:15 by videloff     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/10 14:16:11 by videloff    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef DOOM_NUKEM_H
# define DOOM_NUKEM_H

/*
**  *****************
**  ** doom   libs **
**  *****************
*/

# include "./struct.h"
# include "./define.h"
# include "./proto.h"
# include "./define.h"
# include "../libft/libft.h"

# if defined __linux__
#  include "keys_linux.h"
#  include "../minilibx/mlx.h"
# elif __APPLE__
#  include "keys.h"
#  include "../mlx_include/mlx.h"
# endif

/*
**  ******************
**  ** public libs  **
**  ******************
*/

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <pthread.h>
#endif
