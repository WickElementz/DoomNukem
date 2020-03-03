/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jominodi <jominodi@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:02:28 by jominodi          #+#    #+#             */
/*   Updated: 2020/03/02 12:25:44 by jominodi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void		print_last_screen(t_env *env, int id)
{
	int				x;
	int				y;
	t_clr			clr;
	unsigned int	color;

	x = -1;
	while (++x < 960)
	{
		y = -1;
		while (++y < 600)
		{
			ft_memcpy(&color, &env->sprite[id].data[(x + 960 *
					y) * 4], sizeof(int));
			clr = ((int)color != NONE) ? gclr(color, 0) : gclr(color, 255);
			put_pxl3(env, x, y, clr);
		}
	}
}

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
			if ((int)color != NONE)
			{
				color = (env->sick == 0) ? color : color + 23541;
				clr = gclr(color, 0);
			}
			else
				clr = gclr(color, 255);
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
			if ((int)color != NONE)
			{
				color = (env->sick == 0) ? color : color + 23541;
				clr = gclr(color, 0);
			}
			else
				clr = gclr(color, 255);
			put_pxl2(env, xy[0], xy[1], clr);
			xy[3]++;
			xy[1]++;
		}
		xy[0]++;
		if (xy[0] > 210 && xy[0] < 554 && xy[0] % 2 == 0)
			xy[2]++;
	}
}

t_clr		print_gun(t_env *env, int id, int xy[4])
{
	unsigned int	color;

	ft_memcpy(&color, &env->gun.spr[id].data[(xy[2] +
		(env->gun.spr[id].sl / 4) *
			(171 * xy[3] / 342)) * 4], sizeof(int));
	if ((int)color != NONE)
	{
		color = (env->sick == 0) ? color : color + 23541;
		return (gclr(color, 0));
	}
	else
		return (gclr(color, 255));
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
				clr = print_gun(env, id, xy);
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
