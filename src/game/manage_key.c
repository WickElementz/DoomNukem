/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   manage_key.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/10 14:44:27 by videloff     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/31 11:16:12 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "doom_nukem.h"

static void		event_key2(t_env *env)
{
	if (env->ev.s_right == 1)
		anglemove(&env->cam, SENSI);
	if (env->ev.s_left == 1)
		anglemove(&env->cam, -SENSI);
	if (env->ev.uparrow == 1 && env->up > 0)
		env->up -= 5;
	if (env->ev.downarrow == 1 && env->up < 600)
		env->up += 5;
	if (env->ev.hp_down == 1)
	{
		env->p_health -= 10;
		env->ev.hp_down = 0;
		display(env);
	}
	if (env->ev.win == 1)
		env->win = 1;
	event_mouse(env);
	if (env->ev.forward == 1 || env->ev.back == 1 || env->ev.left == 1 ||
			env->ev.right == 1 || env->ev.run == 1 || env->ev.walk == 1 ||
				env->ev.s_right == 1 || env->ev.s_left == 1 ||
					env->ev.downarrow == 1 || env->ev.uparrow == 1 ||
						env->ev.m_right == 1 || env->ev.m_left == 1 ||
							env->ev.m_down == 1 || env->ev.m_up == 1 ||
							env->ev.win == 1)
		display(env);
}

int				event_key(t_env *env)
{
	int		max[2];

	max[0] = env->map_y_max - 1;
	max[1] = env->map_x_max - 1;
	if (env->ev.forward == 1)
		ft_move_z(env->map, &env->cam, 1, max);
	else if (env->ev.back == 1)
		ft_move_z(env->map, &env->cam, -1, max);
	if (env->ev.left == 1)
		ft_move_x(env->map, &env->cam, -1, max);
	else if (env->ev.right == 1)
		ft_move_x(env->map, &env->cam, 1, max);
	if (env->ev.walk == 1)
		env->cam.speed = 3;
	if (env->ev.run == 1)
		env->cam.speed = 9;
	event_key2(env);
	return (0);
}

int				hold_key(int key, t_env *env)
{
	if (key == KEY_W)
		env->ev.forward = 1;
	else if (key == KEY_S)
		env->ev.back = 1;
	if (key == KEY_A)
		env->ev.left = 1;
	else if (key == KEY_D)
		env->ev.right = 1;
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
	if (key == KEY_R && env->reload.id == 0 && env->ammo < env->r_ammo)
		env->reload.id = 1;
	else if (key == KEY_RIGHT)
		env->ev.s_right = 1;
	if (key == KEY_MINUS && env->p_health > 0)
		env->ev.hp_down = 1;
	if (key == KEY_EQUAL && env->p_health > 0)
		env->ev.win = 1;
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
