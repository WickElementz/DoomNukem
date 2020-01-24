/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fire.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/22 15:29:10 by videloff     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/24 13:31:43 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "doom_nukem.h"

//void	reload_animation(t_env *env)
//{
//
//}

void	fire_animation(t_env *env)
{
	env->ammo--;
	env->r_ammo--;
	env->phase = 6;
	draw_hud(env);
	env->phase = 7;
	draw_hud(env);
/*	env->phase = 8;
	draw_hud(env);
	env->phase = 9;
	draw_hud(env);
	env->phase = 10;
	draw_hud(env);
	env->phase = 9;
	draw_hud(env);
	env->phase = 8;
	draw_hud(env);
	env->phase = 1;
	draw_hud(env);*/
}

int		mouse_hook(int key, int x, int y, t_env *env)
{
	x = y;
	if (key == 1 && env->ammo > 0)
		fire_animation(env);
//	else if (key == 1 && env->ammo == 0 && env->r_ammo > 0)
//		reload_animation(env);
//	if (key == KEY_R && env->r_ammo > 0 && env->r_ammo < 6)
//		reload_animation(env);
//	else
		return (0);
}
