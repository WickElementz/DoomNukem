/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jominodi <jominodi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 14:47:28 by yalabidi          #+#    #+#             */
/*   Updated: 2020/06/01 11:02:51 by jominodi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		load_texture6(t_env *env, int a, int b)
{
	env->reload.spr[0].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"sprites/gun_1.xpm", &a, &b);
	env->reload.spr[0].data = mlx_get_data_addr(env->reload.spr[0].img,
	&env->reload.spr[0].bpp, &env->reload.spr[0].sl, &env->reload.spr[0].end);
	env->reload.spr[1].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"sprites/gun_4.xpm", &a, &b);
	env->reload.spr[1].data = mlx_get_data_addr(env->reload.spr[1].img,
	&env->reload.spr[1].bpp, &env->reload.spr[1].sl, &env->reload.spr[1].end);
	env->reload.spr[2].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"sprites/reload_1.xpm", &a, &b);
	env->reload.spr[2].data = mlx_get_data_addr(env->reload.spr[2].img,
	&env->reload.spr[2].bpp, &env->reload.spr[2].sl, &env->reload.spr[2].end);
	env->reload.spr[3].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"sprites/reload_2.xpm", &a, &b);
	env->reload.spr[3].data = mlx_get_data_addr(env->reload.spr[3].img,
	&env->reload.spr[3].bpp, &env->reload.spr[3].sl, &env->reload.spr[3].end);
	env->reload.spr[4].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"sprites/reload_3.xpm", &a, &b);
	env->reload.spr[4].data = mlx_get_data_addr(env->reload.spr[4].img,
	&env->reload.spr[4].bpp, &env->reload.spr[4].sl, &env->reload.spr[4].end);
	env->reload.spr[5].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"sprites/gun_5.xpm", &a, &b);
	env->reload.spr[5].data = mlx_get_data_addr(env->reload.spr[5].img,
	&env->reload.spr[5].bpp, &env->reload.spr[5].sl, &env->reload.spr[5].end);
}
