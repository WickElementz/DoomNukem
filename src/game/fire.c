/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fire.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/22 15:29:10 by videloff     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/04 12:44:39 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "doom_nukem.h"

void			fire(t_env *env)
{
	clock_t t2;

	t2 = clock();
	if (env->clock == 0 && env->gun.id != 0 && (env->clock = 1))
		env->t = t2;
	if (env->gun.id != 0 && env->gun.id != env->gun.obj)
	{
		print_gun_animation(env, env->gun.id);
		if (env->t + env->gun.time <= t2)
		{
			env->gun.id++;
			env->t += env->gun.time;
		}
	}
	else if (env->gun.id == env->gun.obj)
	{
		env->gun.id = 0;
		env->clock = 0;
		print_gun_animation(env, env->gun.id);
	}
	env->reload.id = 0;
}

static void		reload2(t_env *env)
{
	env->reload.id = 0;
	env->clock = 0;
	print_reload_animation(env, env->reload.id);
}

void			reload(t_env *env)
{
	clock_t t2;

	t2 = clock();
	if (env->clock == 0 && (env->clock = 1))
		env->t = t2;
	if (env->reload.id != 0 && env->ammo < 6 && env->r_ammo > 0)
	{
		print_reload_animation(env, env->reload.id);
		if (env->t + env->reload.time <= t2)
		{
			if (env->ammo == 6 && env->ammo <= env->r_ammo)
				env->reload.id = 1;
			else if (env->ammo < 6 && env->ammo < env->r_ammo &&
						env->reload.id == 5)
				env->reload.id = 2;
			else if (env->reload.id != 5)
				env->reload.id++;
			if (env->ammo < 6 && env->ammo < env->r_ammo && env->reload.id == 5)
				env->ammo++;
			env->t += env->reload.time;
		}
	}
	if (env->ammo == 6 || env->ammo == env->r_ammo)
		reload2(env);
}

int				mouse_hook(int key, int x, int y, t_env *env)
{
	x = y;
	if (key == 1 && env->ammo > 0 && env->gun.id == 0)
	{
		env->ammo--;
		env->r_ammo--;
		env->gun.id = 1;
	}
	else if (key == 1 && env->ammo == 0 && env->r_ammo > 0)
		env->reload.id = 1;
	return (0);
}
