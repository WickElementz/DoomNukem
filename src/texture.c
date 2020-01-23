/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   texture.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/16 11:15:28 by videloff     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/23 14:27:31 by jominodi    ###    #+. /#+    ###.fr     */
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
** sprite[0] = Sprite
** sprite[1] = Gun
** sprite[2] à sprite[7] = HUD
** sprite[8] = Bullet
*/

static void	load_texture4(t_env *env, int a, int b)
{
	a = 280;
	b = 12;
	env->sprite[6].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"sprites/bot_helmet.xpm", &a, &b);
	env->sprite[6].data = mlx_get_data_addr(env->sprite[6].img,
		&env->sprite[6].bpp, &env->sprite[6].size_line, &env->sprite[6].endian);
	a = 251;
	b = 338;
	env->sprite[7].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"sprites/right_hud.xpm", &a, &b);
	env->sprite[7].data = mlx_get_data_addr(env->sprite[7].img,
		&env->sprite[7].bpp, &env->sprite[7].size_line, &env->sprite[7].endian);
	a = 6;
	b = 20;
	env->sprite[8].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"sprites/bullet.xpm", &a, &b);
	env->sprite[8].data = mlx_get_data_addr(env->sprite[8].img,
		&env->sprite[8].bpp, &env->sprite[8].size_line, &env->sprite[8].endian);
	a = 960;
	b = 600;
	env->sprite[9].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"sprites/win.xpm", &a, &b);
	env->sprite[9].data = mlx_get_data_addr(env->sprite[9].img,
		&env->sprite[8].bpp, &env->sprite[9].size_line, &env->sprite[9].endian);
	env->sprite[10].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"sprites/lose.xpm", &a, &b);
	env->sprite[10].data = mlx_get_data_addr(env->sprite[10].img,
		&env->sprite[10].bpp, &env->sprite[10].size_line, &env->sprite[10].endian);
}

static void	load_texture3(t_env *env, int a, int b)
{
	env->sprite[2].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"sprites/glass.xpm", &a, &b);
	env->sprite[2].data = mlx_get_data_addr(env->sprite[2].img,
		&env->sprite[2].bpp, &env->sprite[2].size_line, &env->sprite[2].endian);
	a = 331;
	b = 37;
	env->sprite[3].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"sprites/top_helmet.xpm", &a, &b);
	env->sprite[3].data = mlx_get_data_addr(env->sprite[3].img,
		&env->sprite[3].bpp, &env->sprite[3].size_line, &env->sprite[3].endian);
	a = 176;
	b = 80;
	env->sprite[4].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"sprites/life_ammo.xpm", &a, &b);
	env->sprite[4].data = mlx_get_data_addr(env->sprite[4].img,
		&env->sprite[4].bpp, &env->sprite[4].size_line, &env->sprite[4].endian);
	a = 251;
	b = 235;
	env->sprite[5].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"sprites/left_hud.xpm", &a, &b);
	env->sprite[5].data = mlx_get_data_addr(env->sprite[5].img,
		&env->sprite[5].bpp, &env->sprite[5].size_line, &env->sprite[5].endian);
	load_texture4(env, a, b);
}

static void	load_texture2(t_env *env, int a, int b)
{
	env->text[4].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"textures/wood.xpm", &a, &b);
	env->text[4].data = mlx_get_data_addr(env->text[4].img,
		&env->text[4].bpp, &env->text[4].size_line, &env->text[4].endian);
	env->text[5].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"textures/sky.xpm", &a, &b);
	env->text[5].data = mlx_get_data_addr(env->text[5].img,
		&env->text[5].bpp, &env->text[5].size_line, &env->text[5].endian);
	env->text[6].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"textures/glass_o_pipi.xpm", &a, &b);
	env->text[6].data = mlx_get_data_addr(env->text[6].img,
		&env->text[6].bpp, &env->text[6].size_line, &env->text[6].endian);
	env->sprite[0].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"sprites/sprite.xpm", &a, &b);
	env->sprite[0].data = mlx_get_data_addr(env->sprite[0].img,
		&env->sprite[0].bpp, &env->sprite[0].size_line, &env->sprite[0].endian);
	a = 86;
	b = 86;
	env->sprite[1].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"sprites/gun.xpm", &a, &b);
	env->sprite[1].data = mlx_get_data_addr(env->sprite[1].img,
		&env->sprite[1].bpp, &env->sprite[1].size_line, &env->sprite[1].endian);
	a = 126;
	b = 98;
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
		&env->text[0].bpp, &env->text[0].size_line, &env->text[0].endian);
	env->text[1].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"textures/brick.xpm", &a, &b);
	env->text[1].data = mlx_get_data_addr(env->text[1].img,
		&env->text[1].bpp, &env->text[1].size_line, &env->text[1].endian);
	env->text[2].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"textures/rbrick.xpm", &a, &b);
	env->text[2].data = mlx_get_data_addr(env->text[2].img,
		&env->text[2].bpp, &env->text[2].size_line, &env->text[2].endian);
	env->text[3].img = mlx_xpm_file_to_image(env->mlx_ptr,
		"textures/gstone.xpm", &a, &b);
	env->text[3].data = mlx_get_data_addr(env->text[3].img,
		&env->text[3].bpp, &env->text[3].size_line, &env->text[3].endian);
	load_texture2(env, a, b);
}
