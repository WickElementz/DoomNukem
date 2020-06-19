/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raiko <raiko@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 13:49:17 by kanne             #+#    #+#             */
/*   Updated: 2020/06/19 21:36:35 by raiko            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		horizontal_move(int x, t_env *env)
{
	static int o_x;

	if (x < o_x)
		env->ev.m_left = 0;
	else if (x > o_x)
		env->ev.m_right = 0;
	o_x = x;
}

static void		vertical_move(int y, t_env *env)
{
	static int o_y;

	if (y < o_y)
		env->ev.m_up = 0;
	else if (y > o_y)
		env->ev.m_down = 0;
	o_y = y;
}

void			event_mouse(t_env *env)
{
	if (env->ev.m_right == 0)
	{
		anglemove(&env->cam, SENSIM);
		env->ev.m_right = 1;
	}
	if (env->ev.m_left == 0)
	{
		anglemove(&env->cam, -SENSIM);
		env->ev.m_left = 1;
	}
	if (env->ev.m_up == 0 && env->up > 0)
	{
		env->up -= 5;
		env->ev.m_up = 1;
	}
	if (env->ev.m_down == 0 && env->up < 600)
	{
		env->up += 5;
		env->ev.m_down = 1;
	}
}

int				mouse_move(int x, int y, t_env *env)
{
	mlx_mouse_hide(env->mlx_ptr, env->win_ptr);
	if (x < 5)
		mlx_mouse_move(env->mlx_ptr, env->win_ptr, 480, y);
	else if (x > 955)
		mlx_mouse_move(env->mlx_ptr, env->win_ptr, 0, y);
	else if (y < 5)
		mlx_mouse_move(env->mlx_ptr, env->win_ptr, x, -600);
	else if (y > 595)
		mlx_mouse_move(env->mlx_ptr, env->win_ptr, x, 0);
	vertical_move(y, env);
	horizontal_move(x, env);
	event_mouse(env);
	return (0);
}
