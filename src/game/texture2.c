/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videloff <videloff@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 14:47:28 by yalabidi          #+#    #+#             */
/*   Updated: 2020/06/23 22:25:47 by videloff         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void		load_texture7(t_env *env, int a, int b)
{
	env->text[15].data = mlx_get_data_addr(env->text[15].img,
		&env->text[15].bpp, &env->text[15].sl, &env->text[15].end);
	env->text[16].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"sprites/sprite-back.xpm", &a, &b);
	env->text[16].data = mlx_get_data_addr(env->text[16].img,
		&env->text[16].bpp, &env->text[16].sl, &env->text[16].end);
	a = 6;
	b = 20;
	env->sprite[0].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"sprites/full_hud.xpm", &a, &b);
	env->sprite[0].data = mlx_get_data_addr(env->sprite[0].img,
		&env->sprite[0].bpp, &env->sprite[0].sl, &env->sprite[0].end);
	load_texture4(env, a, b);
}

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
