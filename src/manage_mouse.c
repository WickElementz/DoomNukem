/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   manage_mouse.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kanne <kanne@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/14 13:49:17 by kanne        #+#   ##    ##    #+#       */
/*   Updated: 2020/01/16 12:27:43 by kanne       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "doom_nukem.h"

static void		horizontal_move(int x, t_env *env)
{
	static int o_x;

	if (x < o_x)
		env->ev.s_left = 1;
	else if (x > o_x)
		env->ev.s_right = 1;
	o_x = x;
}

static void		vertical_move(int y, t_env *env)
{
	static int o_y;

	if (y < o_y)
		env->ev.uparrow = 1;
	else if (y > o_y)
		env->ev.downarrow = 1;
	o_y = y;
}

int				mouse_move(int x, int y, t_env *env)
{
//	if (x >= 0 && x <= 960 && y >= 0 && y <= 600)
//	{
		vertical_move(y, env);
		horizontal_move(x, env);
//	}
	return (0);
}
