/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   gun_phase.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/23 14:29:43 by videloff     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/24 13:32:51 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "doom_nukem.h"

int		gun_phase3(t_env *env, int (*xy)[6])
{
	if (env->phase == 8)
	{
		(*xy)[4] = 150;
		(*xy)[5] = 143;
		return(8);
	}
	else if (env->phase == 9)
	{
		(*xy)[4] = 94;
		(*xy)[5] = 183;
		return(9);
	}
	else
	{
		(*xy)[4] = 127;
		(*xy)[5] = 163;
		return(10);
	}
}

int		gun_phase2(t_env *env, int (*xy)[6])
{
	if (env->phase == 6)
	{
		(*xy)[4] = 100;
		(*xy)[5] = 99;
		return(6);
	}
	else
	{
		(*xy)[4] = 100;
		(*xy)[5] = 108;
		return(7);
	}
}

int		gun_phase(t_env *env, int (*xy)[6])
{
    (*xy)[0] = 0;
    (*xy)[1] = 0;
    (*xy)[2] = 0;
    (*xy)[3] = 0;
	if (env->phase == 1)
	{
		(*xy)[4] = 100;
		(*xy)[5] = 86;
		return(1);
	}
	else if (env->phase >= 6 && env->phase <= 7)
		return (gun_phase2(env, xy));
	else
		return (gun_phase3(env, xy));
}
