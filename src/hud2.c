/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hud2.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/22 15:02:28 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/04 11:39:50 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "doom_nukem.h"

void		print_gun_animation(t_env *env, int id)
{
	int				xy[4];
	t_clr			clr;
	unsigned int	color;

	xy[0] = 211;
	xy[2] = 0;
	while (xy[0] < 552)
	{
		xy[1] = 234;
		xy[3] = 0;
		while (xy[1] < 600)
		{
			ft_memcpy(&color, &env->gun.spr[id].data[(xy[2] +
				(env->gun.spr[id].sl / 4) *
					(171 * xy[3] / 342)) * 4], sizeof(int));
			clr = ((int)color != NONE) ? gclr(color, 0) : gclr(color, 255);
			put_pxl2(env, xy[0], xy[1], clr);
			xy[3]++;
			xy[1]++;
		}
		xy[0]++;
		if (xy[0] > 210 && xy[0] < 554 && xy[0] % 2 == 0)
			xy[2]++;
	}
}

void		print_reload_animation(t_env *env, int id)
{
	int				xy[4];
	t_clr			clr;
	unsigned int	color;

	xy[0] = 211;
	xy[2] = 0;
	while (xy[0] < 552)
	{
		xy[1] = 234;
		xy[3] = 0;
		while (xy[1] < 600)
		{
			ft_memcpy(&color, &env->reload.spr[id].data[(xy[2] +
				(env->reload.spr[id].sl / 4) *
					(171 * xy[3] / 342)) * 4], sizeof(int));
			clr = ((int)color != NONE) ? gclr(color, 0) : gclr(color, 255);
			put_pxl2(env, xy[0], xy[1], clr);
			xy[3]++;
			xy[1]++;
		}
		xy[0]++;
		if (xy[0] > 210 && xy[0] < 554 && xy[0] % 2 == 0)
			xy[2]++;
	}
}

t_clr		print_gun(t_env *env, int id, int xy[4], t_clr clr)
{
	unsigned int	color;

	ft_memcpy(&color, &env->gun.spr[id].data[(xy[2] +
		(env->gun.spr[id].sl / 4) *
			(171 * xy[3] / 342)) * 4], sizeof(int));
	clr = ((int)color != NONE) ? gclr(color, 0) : gclr(color, 255);
	return (clr);
}

void		gun(t_env *env, int id)
{
	int				xy[4];
	t_clr			clr;

	xy[0] = 0;
	xy[2] = 0;
	while (xy[0] < 960)
	{
		xy[1] = 0;
		xy[3] = 0;
		while (xy[1] < 600)
		{
			if (xy[0] > 210 && xy[0] < 552 && xy[1] > 234 && (xy[3]++))
				clr = print_gun(env, id, xy, clr);
			else
				clr = gclr(0, 255);
			put_pxl2(env, xy[0], xy[1], clr);
			xy[1]++;
		}
		xy[0]++;
		if (xy[0] > 210 && xy[0] < 554 && xy[0] % 2 == 0)
			xy[2]++;
	}
}