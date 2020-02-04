/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   doom_nukem.h                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/01 11:03:15 by videloff     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/28 13:42:48 by jominodi    ###    #+. /#+    ###.fr     */
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
#  include "../mlx_include_new/mlx.h"
# endif

/*
**  ******************
**  ** public libs  **
**  ******************
*/

# include <time.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <pthread.h>
#endif
