/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jominodi <jominodi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:07:19 by jominodi          #+#    #+#             */
/*   Updated: 2020/06/01 14:28:26 by jominodi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		check_status2(t_env *env, int x, int y)
{
	if (env->map[x][y].type == 'K')
	{
		env->player.key[env->player.keyid] = env->map[x][y].id;
		env->map[x][y].type = 'F';
		env->player.keyid++;
	}
	else if (env->map[x][y].type == 'C')
	{
		env->sick = 1;
		gun(env, 0);
		print_hud(env, 0);
		env->coro_clock = 0;
		env->player.corona = 1;
		env->map[x][y].type = 'F';
	}
}

void		check_status(t_env *env)
{
	int x;
	int y;

	x = (int)env->cam.x / BLOCK;
	y = (int)env->cam.y / BLOCK;
	if (env->player.life <= 0)
		print_last_screen(env, 3);
	else if (env->map[x][y].type == 'E' && (env->win = 1))
		print_last_screen(env, 2);
	else if (env->map[x][y].type == 'L')
	{
		env->player.life += 20;
		env->player.life = env->player.life >= 100 ? 100 : env->player.life;
		env->map[x][y].type = 'F';
	}
	else if (env->map[x][y].type == 'A' && (env->player.stock += 6))
		env->map[x][y].type = 'F';
	check_status2(env, x, y);
}

void		check_animation(t_env *env)
{
	ray_multi_thread(env);
	if (env->player.corona != 0)
		corona(env);
	if (env->door_id != 0)
		door(env);
	if (env->jump != 0)
		jump(env);
	if (env->crouch_id != 0)
		crouch_animation(env);
	if (env->reload.id == 0 && env->gun.id == 0)
		gun(env, 0);
	if (env->gun.id != 0)
		fire(env);
	else if (env->reload.id != 0)
		reload(env);
	draw_li_bu(env);
	print_hud(env, 0);
}
