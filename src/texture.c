/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   texture.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/16 11:15:28 by videloff     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/30 12:52:13 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "doom_nukem.h"

/*
** text[0] = Mossy
** text[1] = Bricks
** text[2] = Red Bricks
** text[3] = GreyStone
** text[4] = Wood
** text[5] = Sky
** text[6] = Vitre
** sprite[0] = Sprite
** sprite[1] = Gun
** sprite[2] = Balles
** sprite[3] = Ecran de Win
** sprite[4] = Ecran de Lose
** sprite[5] = HUD
** sprite[6] à sprite[12] = Gun animation
*/

static void load_texture5(t_env *env, int a, int b)
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

static void	load_texture4(t_env *env, int a, int b)
{
	env->gun.spr[1].data = mlx_get_data_addr(env->gun.spr[1].img,
	&env->gun.spr[1].bpp, &env->gun.spr[1].sl, &env->gun.spr[1].end);
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
	load_texture5(env, a, b);
}

static void	load_texture3(t_env *env, int a, int b)
{
	a = 960;
	b = 600;
	env->sprite[2].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"sprites/win.xpm", &a, &b);
	env->sprite[2].data = mlx_get_data_addr(env->sprite[2].img,
		&env->sprite[2].bpp, &env->sprite[2].sl, &env->sprite[2].end);
	env->sprite[3].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"sprites/lose.xpm", &a, &b);
	env->sprite[3].data = mlx_get_data_addr(env->sprite[3].img,
		&env->sprite[3].bpp, &env->sprite[3].sl, &env->sprite[3].end);
	env->sprite[4].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"sprites/full_hud.xpm", &a, &b);
	env->sprite[4].data = mlx_get_data_addr(env->sprite[4].img,
		&env->sprite[4].bpp, &env->sprite[4].sl, &env->sprite[4].end);
	a = 171;
	b = 183;
	env->gun.spr[0].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"sprites/gun_1.xpm", &a, &b);
	env->gun.spr[0].data = mlx_get_data_addr(env->gun.spr[0].img,
		&env->gun.spr[0].bpp, &env->gun.spr[0].sl, &env->gun.spr[0].end);
	env->gun.spr[1].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"sprites/gun_2.xpm", &a, &b);
	load_texture4(env, a, b);
}

static void	load_texture2(t_env *env, int a, int b)
{
	env->text[5].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"textures/sky.xpm", &a, &b);
	env->text[5].data = mlx_get_data_addr(env->text[5].img,
		&env->text[5].bpp, &env->text[5].sl, &env->text[5].end);
	env->text[6].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"textures/glass_o_pipi.xpm", &a, &b);
	env->text[6].data = mlx_get_data_addr(env->text[6].img,
		&env->text[6].bpp, &env->text[6].sl, &env->text[6].end);
	env->sprite[0].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"sprites/sprite.xpm", &a, &b);
	env->sprite[0].data = mlx_get_data_addr(env->sprite[0].img,
		&env->sprite[0].bpp, &env->sprite[0].sl, &env->sprite[0].end);
	a = 6;
	b = 20;
	env->sprite[1].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"sprites/bullet.xpm", &a, &b);
	env->sprite[1].data = mlx_get_data_addr(env->sprite[1].img,
		&env->sprite[1].bpp, &env->sprite[1].sl, &env->sprite[1].end);
	load_texture3(env, a, b);
}

void		load_texture(t_env *env)
{
	int a;
	int b;

	a = 64;
	b = 64;
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
