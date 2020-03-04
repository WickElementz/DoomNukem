/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jominodi <jominodi@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:07:19 by jominodi          #+#    #+#             */
/*   Updated: 2020/03/04 13:35:01 by jominodi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

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
		print_hud(env, 4);
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
