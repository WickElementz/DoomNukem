/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   texture.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/16 11:15:28 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/07 13:45:19 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** text[0] = brick
** text[1] = wood
** text[2] = brick2
** text[3] = concrete
*/

void	load_texture(t_env *env)
{
	int a;
	int b;

	a = 64;
	b = 64;
	env->text[0].img = mlx_xpm_file_to_image(env->mlx_ptr, "texture/mossy.xpm",
							&a, &b);
	env->text[0].data = mlx_get_data_addr(env->text[0].img, &env->text[0].bpp,
							&env->text[0].size_line, &env->text[0].endian);
	env->text[1].img = mlx_xpm_file_to_image(env->mlx_ptr, "texture/brick.xpm",
							&a, &b);
	env->text[1].data = mlx_get_data_addr(env->text[1].img, &env->text[1].bpp,
							&env->text[1].size_line, &env->text[1].endian);
	env->text[2].img = mlx_xpm_file_to_image(env->mlx_ptr, "texture/rbrick.xpm",
							&a, &b);
	env->text[2].data = mlx_get_data_addr(env->text[2].img, &env->text[2].bpp,
							&env->text[2].size_line, &env->text[2].endian);
	env->text[3].img = mlx_xpm_file_to_image(env->mlx_ptr, "texture/gstone.xpm",
							&a, &b);
	env->text[3].data = mlx_get_data_addr(env->text[3].img, &env->text[3].bpp,
							&env->text[3].size_line, &env->text[3].endian);
}
