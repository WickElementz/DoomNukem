/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   manage_mouse.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/14 13:49:17 by kanne        #+#   ##    ##    #+#       */
/*   Updated: 2020/02/04 12:40:10 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "doom_nukem.h"

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
		anglemove(&env->cam, SENSI);
		env->ev.m_right = 1;
	}
	if (env->ev.m_left == 0)
	{
		anglemove(&env->cam, -SENSI);
		env->ev.m_left = 1;
	}
	if (env->ev.m_up == 0 && env->up > 0)
	{
		env->up -= 20;
		env->ev.m_up = 1;
	}
	if (env->ev.m_down == 0 && env->up < 600)
	{
		env->up += 20;
		env->ev.m_down = 1;
	}
}

int				mouse_move(int x, int y, t_env *env)
{
	dprintf(1, "d");
	vertical_move(y, env);
	horizontal_move(x, env);
	return (0);
}
