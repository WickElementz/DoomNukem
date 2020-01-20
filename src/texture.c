/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   textures.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/16 11:15:28 by videloff     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/17 13:32:49 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "doom_nukem.h"

/*
** text[0] = brick
** text[1] = wood
** text[2] = brick2
** text[3] = concrete
*/

void	load_texture2(t_env *env, int a, int b)
{
	env->text[4].img = mlx_xpm_file_to_image(env->mlx_ptr, "textures/wood.xpm",
							&a, &b);
	env->text[4].data = mlx_get_data_addr(env->text[4].img, &env->text[4].bpp,
							&env->text[4].size_line, &env->text[4].endian);
	env->text[5].img = mlx_xpm_file_to_image(env->mlx_ptr, "textures/sky.xpm",
							&a, &b);
	env->text[5].data = mlx_get_data_addr(env->text[5].img, &env->text[5].bpp,
							&env->text[5].size_line, &env->text[5].endian);
	a = 86;
	b = 86;
	env->sprite[0].img = mlx_xpm_file_to_image(env->mlx_ptr, "sprites/gun.xpm",
							&a, &b);
	env->sprite[0].data = mlx_get_data_addr(env->sprite[0].img, &env->sprite[0].bpp,
							&env->sprite[0].size_line, &env->sprite[0].endian);
	a = 960;
	b = 600;
	env->sprite[1].img = mlx_xpm_file_to_image(env->mlx_ptr, "sprites/helmet.xpm",
							&a, &b);
	env->sprite[1].data = mlx_get_data_addr(env->sprite[1].img, &env->sprite[1].bpp,
							&env->sprite[1].size_line, &env->sprite[1].endian);
}

void	load_texture(t_env *env)
{
	int a;
	int b;

	a = 64;
	b = 64;
	env->text[0].img = mlx_xpm_file_to_image(env->mlx_ptr, "textures/mossy.xpm",
							&a, &b);
	env->text[0].data = mlx_get_data_addr(env->text[0].img, &env->text[0].bpp,
							&env->text[0].size_line, &env->text[0].endian);
	env->text[1].img = mlx_xpm_file_to_image(env->mlx_ptr, "textures/brick.xpm",
							&a, &b);
	env->text[1].data = mlx_get_data_addr(env->text[1].img, &env->text[1].bpp,
							&env->text[1].size_line, &env->text[1].endian);
	env->text[2].img = mlx_xpm_file_to_image(env->mlx_ptr, "textures/rbrick.xpm",
							&a, &b);
	env->text[2].data = mlx_get_data_addr(env->text[2].img, &env->text[2].bpp,
							&env->text[2].size_line, &env->text[2].endian);
	env->text[3].img = mlx_xpm_file_to_image(env->mlx_ptr, "textures/gstone.xpm",
							&a, &b);
	env->text[3].data = mlx_get_data_addr(env->text[3].img, &env->text[3].bpp,
							&env->text[3].size_line, &env->text[3].endian);
	load_texture2(env, a, b);
}
