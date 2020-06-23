/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jominodi <jominodi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:07:19 by jominodi          #+#    #+#             */
/*   Updated: 2020/06/23 02:21:01 by jominodi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void		display_key(t_env *env)
{
	clock_t	t_key;

	t_key = clock();
	if (env->clock_key == 0 && (env->clock_key = 1))
		env->t4 = t_key;
	if (env->t4 + 20000000 > t_key)
		mlx_string_put(env->mlx_ptr, env->win_ptr, 300, 550, 0x00FFFF,
			"You grabbed a keycard, it has been added to your inventory.");
	else
	{
		env->clock_key = 0;
		env->player.display_key = 0;
	}
}

void		display_trap(t_env *env)
{
	clock_t	t_trap;

	t_trap = clock();
	if (env->clock_trap == 0 && (env->clock_trap = 1))
		env->t5 = t_trap;
	if (env->t5 + 10000000 > t_trap)
		mlx_string_put(env->mlx_ptr, env->win_ptr, 380, 580, 0x00FFFF,
			"Trapped, You lost some life points");
	else
	{
		env->clock_trap = 0;
		env->player.display_trap = 0;
	}
}

void		check_status2(t_env *env, int x, int y)
{
	if (env->map[x][y].type == 'K')
	{
		env->player.key[env->player.keyid] = env->map[x][y].id;
		env->clock_key = 0;
		env->player.display_key = 1;
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
	else if (env->map[x][y].type == 'Z')
	{
		env->player.screen = 1;
		env->player.display_trap = 1;
		env->player.life -= (env->map[x][y].id - 48) * 10 + 10;
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
