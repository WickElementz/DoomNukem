/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   texture2.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: videloff <videloff@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/23 13:34:39 by videloff     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/23 14:33:18 by videloff    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "doom_nukem.h"

static void load_texture6(t_env *env, int a, int b)
{
    a = 94;
	b = 183;
	env->sprite[14].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"sprites/fire_4.xpm", &a, &b);
	env->sprite[14].data = mlx_get_data_addr(env->sprite[14].img,
	&env->sprite[14].bpp, &env->sprite[14].size_line, &env->sprite[14].endian);
    a = 127;
	b = 163;
	env->sprite[15].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"sprites/fire_5.xpm", &a, &b);
	env->sprite[15].data = mlx_get_data_addr(env->sprite[15].img,
	&env->sprite[15].bpp, &env->sprite[15].size_line, &env->sprite[15].endian);
}

void	    load_texture5(t_env *env, int a, int b)
{
    a = 100;
	b = 99;
	env->sprite[11].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"sprites/fire_1.xpm", &a, &b);
	env->sprite[11].data = mlx_get_data_addr(env->sprite[11].img,
	&env->sprite[11].bpp, &env->sprite[11].size_line, &env->sprite[11].endian);
    a = 100;
	b = 108;
	env->sprite[12].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"sprites/fire_2.xpm", &a, &b);
	env->sprite[12].data = mlx_get_data_addr(env->sprite[12].img,
	&env->sprite[12].bpp, &env->sprite[12].size_line, &env->sprite[12].endian);
    a = 150;
	b = 143;
	env->sprite[13].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"sprites/fire_3.xpm", &a, &b);
	env->sprite[13].data = mlx_get_data_addr(env->sprite[13].img,
	&env->sprite[13].bpp, &env->sprite[13].size_line, &env->sprite[13].endian);
	load_texture6(env, a, b);
}
