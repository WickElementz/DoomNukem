/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom_nukem.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videloff <videloff@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 14:23:32 by videloff          #+#    #+#             */
/*   Updated: 2020/06/22 14:29:22 by videloff         ###   ########lyon.fr   */
/*                                                                            */
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
