/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fire.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/22 15:29:10 by videloff     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/24 16:18:43 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "doom_nukem.h"

void	reload_animation(t_env *env)
{
	env->ammo = (env->r_ammo > 6) ? 6 : env->r_ammo;
}

void	fire_animation(t_env *env)
{
	if (env->delay == 1)
	{
		print_gun_animation(env, 6);
		env->delay +=1;
	}
	else if (env->delay == 2)
	{
		print_gun_animation(env, 7);
		env->delay += 1;
	}
	else if (env->delay == 3)
	{
		print_gun_animation(env, 8);
		env->delay += 1;
	}
	else if (env->delay == 4)
	{
		print_gun_animation(env, 9);
		env->delay += 1;
	}
	else if (env->delay == 5)
	{
		print_gun_animation(env, 10);
		env->delay += 1;
	}
	else if (env->delay == 6)
	{
		print_gun_animation(env, 11);
		env->delay += 1;
	}
	else if (env->delay == 7)
	{
		print_gun_animation(env, 12);
		env->delay += 1;
	}
	else if (env->delay == 8)
	{
		print_gun_animation(env, 1);
		env->delay = 1;
	}
}

int		mouse_hook(int key, int x, int y, t_env *env)
{
//	x = y;
	dprintf(0, "%d%d", x, y);
	if (key == 1 && env->ammo > 0)
	{
		env->ammo--;
		env->r_ammo--;
		fire_animation(env);
	}
	else if (key == 1 && env->ammo == 0 && env->r_ammo > 0)
		reload_animation(env);
//	if (key == KEY_R && env->r_ammo > 0 && env->r_ammo < 6)
//		reload_animation(env);
//	else
		return (0);
}
