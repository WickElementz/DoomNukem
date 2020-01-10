/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   manage_key.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: videloff <videloff@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/10 14:44:27 by videloff     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/09 13:56:21 by videloff    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

static void		event_key2(t_env *env)
{
	if (env->ev.s_right == 1)
		anglemove(&env->cam, 3);
	if (env->ev.s_left == 1)
		anglemove(&env->cam, -3);
	if (env->ev.forward == 1 || env->ev.back == 1 || env->ev.left == 1 ||
			env->ev.right == 1 || env->ev.run == 1 || env->ev.walk == 1 ||
				env->ev.s_right == 1 || env->ev.s_left == 1)
		raycasting(env);
}

int				event_key(t_env *env)
{
	int		max[2];

	max[0] = env->map_y_max - 1;
	max[1] = env->map_x_max - 1;
	if (env->ev.forward == 1)
		ft_move_z(env->map, &env->cam, 1, max);
	if (env->ev.back == 1)
		ft_move_z(env->map, &env->cam, -1, max);
	if (env->ev.left == 1)
		ft_move_x(env->map, &env->cam, -1, max);
	if (env->ev.right == 1)
		ft_move_x(env->map, &env->cam, 1, max);
	if (env->ev.run == 1)
	{
		env->cam.speed = (env->cam.speed == 6 || env->cam.speed == 2) ? 4 : 6;
		env->ev.run = 0;
	}
	if (env->ev.walk == 1)
	{
		env->cam.speed = (env->cam.speed == 2 || env->cam.speed == 6) ? 4 : 2;
		env->ev.walk = 0;
	}
	event_key2(env);
	return (0);
}

int				hold_key(int key, t_env *env)
{
	if (key == KEY_W)
		env->ev.forward = 1;
	else if (key == KEY_S)
		env->ev.back = 1;
	if (key == KEY_LEFT)
		env->ev.s_left = 1;
	else if (key == KEY_RIGHT)
		env->ev.s_right = 1;
	if (key == KEY_A)
		env->ev.left = 1;
	if (key == KEY_D)
		env->ev.right = 1;
	if (key == KEY_SHIFT_LEFT)
		env->ev.run = 1;
	if (key == KEY_CTRL_LEFT)
		env->ev.walk = 1;
	if (key == KEY_ESCAPE)
		free_env(env, 0);
	return (0);
}

int				unhold_key(int key, t_env *env)
{
	if (key == KEY_LEFT)
		env->ev.s_left = 0;
	else if (key == KEY_RIGHT)
		env->ev.s_right = 0;
	if (key == KEY_W)
		env->ev.forward = 0;
	if (key == KEY_S)
		env->ev.back = 0;
	if (key == KEY_A)
		env->ev.left = 0;
	if (key == KEY_D)
		env->ev.right = 0;
	return (0);
}
