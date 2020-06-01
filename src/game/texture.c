/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jominodi <jominodi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 11:15:28 by videloff          #+#    #+#             */
/*   Updated: 2020/06/01 12:03:25 by jominodi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	load_texture5(t_env *env, int a, int b)
{
	env->gun.spr[2].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"sprites/gun_3.xpm", &a, &b);
	env->gun.spr[2].data = mlx_get_data_addr(env->gun.spr[2].img,
	&env->gun.spr[2].bpp, &env->gun.spr[2].sl, &env->gun.spr[2].end);
	env->gun.spr[3].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"sprites/gun_4.xpm", &a, &b);
	env->gun.spr[3].data = mlx_get_data_addr(env->gun.spr[3].img,
	&env->gun.spr[3].bpp, &env->gun.spr[3].sl, &env->gun.spr[3].end);
	env->gun.spr[4].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"sprites/gun_5.xpm", &a, &b);
	env->gun.spr[4].data = mlx_get_data_addr(env->gun.spr[4].img,
	&env->gun.spr[4].bpp, &env->gun.spr[4].sl, &env->gun.spr[4].end);
	env->gun.spr[5].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"sprites/gun_6.xpm", &a, &b);
	env->gun.spr[5].data = mlx_get_data_addr(env->gun.spr[5].img,
	&env->gun.spr[5].bpp, &env->gun.spr[5].sl, &env->gun.spr[5].end);
	env->gun.spr[6].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"sprites/gun_7.xpm", &a, &b);
	env->gun.spr[6].data = mlx_get_data_addr(env->gun.spr[6].img,
	&env->gun.spr[6].bpp, &env->gun.spr[6].sl, &env->gun.spr[6].end);
	env->gun.spr[7].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"sprites/gun_8.xpm", &a, &b);
	env->gun.spr[7].data = mlx_get_data_addr(env->gun.spr[7].img,
	&env->gun.spr[7].bpp, &env->gun.spr[7].sl, &env->gun.spr[7].end);
	load_texture6(env, a, b);
}

static void	load_texture4(t_env *env, int a, int b)
{
	a = 960;
	b = 600;
	env->sprite[1].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"sprites/bullet.xpm", &a, &b);
	env->sprite[1].data = mlx_get_data_addr(env->sprite[1].img,
		&env->sprite[1].bpp, &env->sprite[1].sl, &env->sprite[1].end);
	env->sprite[2].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"sprites/win.xpm", &a, &b);
	env->sprite[2].data = mlx_get_data_addr(env->sprite[2].img,
		&env->sprite[2].bpp, &env->sprite[2].sl, &env->sprite[2].end);
	env->sprite[3].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"sprites/lose.xpm", &a, &b);
	env->sprite[3].data = mlx_get_data_addr(env->sprite[3].img,
		&env->sprite[3].bpp, &env->sprite[3].sl, &env->sprite[3].end);
	a = 171;
	b = 183;
	env->gun.spr[0].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"sprites/gun_1.xpm", &a, &b);
	env->gun.spr[0].data = mlx_get_data_addr(env->gun.spr[0].img,
		&env->gun.spr[0].bpp, &env->gun.spr[0].sl, &env->gun.spr[0].end);
	env->gun.spr[1].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"sprites/gun_2.xpm", &a, &b);
	env->gun.spr[1].data = mlx_get_data_addr(env->gun.spr[1].img,
	&env->gun.spr[1].bpp, &env->gun.spr[1].sl, &env->gun.spr[1].end);
	load_texture5(env, a, b);
}

static void	load_texture3(t_env *env, int a, int b)
{
	env->text[10].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"sprites/key.xpm", &a, &b);
	env->text[10].data = mlx_get_data_addr(env->text[10].img,
		&env->text[10].bpp, &env->text[10].sl, &env->text[10].end);
	env->text[11].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"sprites/corona.xpm", &a, &b);
	env->text[11].data = mlx_get_data_addr(env->text[11].img,
		&env->text[11].bpp, &env->text[11].sl, &env->text[11].end);
	env->text[12].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"sprites/gunner.xpm", &a, &b);
	env->text[12].data = mlx_get_data_addr(env->text[12].img,
		&env->text[12].bpp, &env->text[12].sl, &env->text[12].end);
	a = 6;
	b = 20;
	env->sprite[0].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"sprites/full_hud.xpm", &a, &b);
	env->sprite[0].data = mlx_get_data_addr(env->sprite[0].img,
		&env->sprite[0].bpp, &env->sprite[0].sl, &env->sprite[0].end);
	load_texture4(env, a, b);
}

static void	load_texture2(t_env *env, int a, int b)
{
	env->text[5].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"textures/sky.xpm", &a, &b);
	env->text[5].data = mlx_get_data_addr(env->text[5].img,
		&env->text[5].bpp, &env->text[5].sl, &env->text[5].end);
	env->text[6].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"textures/glass.xpm", &a, &b);
	env->text[6].data = mlx_get_data_addr(env->text[6].img,
		&env->text[6].bpp, &env->text[6].sl, &env->text[6].end);
	env->text[7].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"sprites/sprite.xpm", &a, &b);
	env->text[7].data = mlx_get_data_addr(env->text[7].img,
		&env->text[7].bpp, &env->text[7].sl, &env->text[7].end);
	env->text[8].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"sprites/ammo.xpm", &a, &b);
	env->text[8].data = mlx_get_data_addr(env->text[8].img,
		&env->text[8].bpp, &env->text[8].sl, &env->text[8].end);
	env->text[9].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"sprites/door.xpm", &a, &b);
	env->text[9].data = mlx_get_data_addr(env->text[9].img,
		&env->text[9].bpp, &env->text[9].sl, &env->text[9].end);
	load_texture3(env, a, b);
}

void		load_texture(t_env *env, int a, int b)
{
	env->text[0].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"textures/mossy.xpm", &a, &b);
	env->text[0].data = mlx_get_data_addr(env->text[0].img,
		&env->text[0].bpp, &env->text[0].sl, &env->text[0].end);
	env->text[1].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"textures/brick.xpm", &a, &b);
	env->text[1].data = mlx_get_data_addr(env->text[1].img,
		&env->text[1].bpp, &env->text[1].sl, &env->text[1].end);
	env->text[2].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"textures/rbrick.xpm", &a, &b);
	env->text[2].data = mlx_get_data_addr(env->text[2].img,
		&env->text[2].bpp, &env->text[2].sl, &env->text[2].end);
	env->text[3].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"textures/gstone.xpm", &a, &b);
	env->text[3].data = mlx_get_data_addr(env->text[3].img,
		&env->text[3].bpp, &env->text[3].sl, &env->text[3].end);
	env->text[4].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"textures/wood.xpm", &a, &b);
	env->text[4].data = mlx_get_data_addr(env->text[4].img,
		&env->text[4].bpp, &env->text[4].sl, &env->text[4].end);
	load_texture2(env, a, b);
}
