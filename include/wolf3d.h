/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raiko <raiko@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 11:03:15 by videloff          #+#    #+#             */
/*   Updated: 2020/06/11 15:44:46 by raiko            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

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
#  include "../libmlx/mlx.h"
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
# include <math.h>
# include <pthread.h>
# include <errno.h>
#endif
