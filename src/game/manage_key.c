/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videloff <videloff@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 12:06:15 by jominodi          #+#    #+#             */
/*   Updated: 2020/06/22 14:29:22 by videloff         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static void		event_key2(t_env *env)
{
	if (env->ev.s_right == 1)
		anglemove(&env->cam, SENSI);
	if (env->ev.s_left == 1)
		anglemove(&env->cam, -SENSI);
	if (env->ev.uparrow == 1 && (env->up > 0))
		env->up -= 10;
	if (env->ev.downarrow == 1 && (env->up < 600))
		env->up += 10;
	if (env->ev.hp_down == 1)
	{
		env->player.life -= 10;
		env->ev.hp_down = 0;
	}
	display(env);
}

int				event_key(t_env *env)
{
	static int up[2];

	up[0] = env->up;
	up[1] = env->player.corona;
	if (env->ev.forward == 1)
		ft_move_z(env->map, &env->cam, 1, up);
	else if (env->ev.back == 1)
		ft_move_z(env->map, &env->cam, -1, up);
	if (env->ev.left == 1)
		ft_move_x(env->map, &env->cam, -1, up);
	else if (env->ev.right == 1)
		ft_move_x(env->map, &env->cam, 1, up);
	if (env->ev.walk == 1)
		env->cam.speed = 3;
	if (env->ev.run == 1)
		env->cam.speed = 9;
	event_key2(env);
	return (0);
}

int				hold_key2(int key, t_env *env)
{
	if (key == KEY_W)
		env->ev.forward = 1;
	else if (key == KEY_S)
		env->ev.back = 1;
	if (key == KEY_A)
		env->ev.left = 1;
	else if (key == KEY_D)
		env->ev.right = 1;
	if (key == KEY_E)
		open_door(env);
	if (key == KEY_Z && env->jump == 0)
		env->crouch_id = env->crouch_id == 1 ? 2 : 1;
	if (key == KEY_SPACEBAR && env->jump == 0 && env->crouch_id == 0)
		env->jump = 1;
	if (key == KEY_F && env->player.ammo > 0 && env->gun.id == 0)
	{
		env->player.ammo--;
		env->player.stock--;
		env->gun.id = 1;
	}
	else if (key == KEY_F && env->player.ammo == 0 && env->player.stock > 0)
		env->reload.id = 1;
	return (0);
}

int				hold_key(int key, t_env *env)
{
	hold_key2(key, env);
	if (key == KEY_SHIFT_LEFT)
		env->ev.run = 1;
	else if (key == KEY_ALT)
		env->ev.walk = 1;
	if (key == KEY_UP)
		env->ev.uparrow = 1;
	else if (key == KEY_DOWN)
		env->ev.downarrow = 1;
	if (key == KEY_LEFT)
		env->ev.s_left = 1;
	if (key == KEY_R && env->reload.id == 0 &&
			env->player.ammo < env->player.stock)
		env->reload.id = 1;
	else if (key == KEY_RIGHT)
		env->ev.s_right = 1;
	if (key == KEY_MINUS && env->player.life > 0)
		env->ev.hp_down = 1;
	if (key == KEY_ESCAPE)
		free_env(env, 0);
	return (0);
}

int				unhold_key(int key, t_env *env)
{
	if (key == KEY_SHIFT_LEFT && (env->cam.speed = 6))
		env->ev.run = 0;
	else if (key == KEY_ALT && (env->cam.speed = 6))
		env->ev.walk = 0;
	if (key == KEY_W)
		env->ev.forward = 0;
	if (key == KEY_S)
		env->ev.back = 0;
	if (key == KEY_A)
		env->ev.left = 0;
	if (key == KEY_D)
		env->ev.right = 0;
	if (key == KEY_UP)
		env->ev.uparrow = 0;
	else if (key == KEY_DOWN)
		env->ev.downarrow = 0;
	if (key == KEY_LEFT)
		env->ev.s_left = 0;
	else if (key == KEY_RIGHT)
		env->ev.s_right = 0;
	return (0);
}
