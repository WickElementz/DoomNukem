/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fire.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jominodi <jominodi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:29:10 by videloff          #+#    #+#             */
/*   Updated: 2020/06/01 11:02:51 by jominodi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

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
		deal_damage(env);
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
	if (env->reload.id != 0 && env->player.ammo < 6 && env->player.stock > 0)
	{
		print_reload_animation(env, env->reload.id);
		if (env->t + env->reload.time <= t2)
		{
			if (env->player.ammo == 6 && env->player.ammo <= env->player.stock)
				env->reload.id = 1;
			if (env->player.ammo < 6 && env->player.ammo < env->player.stock &&
						env->reload.id == 5)
				env->reload.id = 2;
			else if (env->reload.id != 5)
				env->reload.id++;
			if (env->player.ammo < 6 && env->player.ammo < env->player.stock &&
					env->reload.id == 5)
				env->player.ammo++;
			env->t += env->reload.time;
		}
	}
	if (env->player.ammo == 6 || env->player.ammo == env->player.stock)
		reload2(env);
}

int				mouse_hook(int key, int x, int y, t_env *env)
{
	x = y;
	y = x;
	if (key == 1 && env->player.ammo > 0 && env->gun.id == 0)
	{
		env->player.ammo--;
		env->player.stock--;
		env->gun.id = 1;
	}
	else if (key == 1 && env->player.ammo == 0 && env->player.stock > 0)
		env->reload.id = 1;
	return (0);
}
