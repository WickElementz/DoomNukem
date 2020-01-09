/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wolf3d.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/01 11:03:15 by videloff     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/10 15:02:02 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

/*
**  *****************
**  ** wolf3d libs **
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
