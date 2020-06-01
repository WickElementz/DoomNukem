/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jominodi <jominodi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 11:53:16 by jominodi          #+#    #+#             */
/*   Updated: 2020/06/01 11:02:51 by jominodi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		print_gun_animation(t_env *env, int id)
{
	int				xy[4];
	unsigned int	color;

	xy[0] = 211;
	xy[2] = 0;
	while (xy[0] < 552)
	{
		xy[1] = 234;
		xy[3] = 0;
		while (xy[1]++ < 600)
		{
			ft_memcpy(&color, &env->gun.spr[id].data[(xy[2] +
				(env->gun.spr[id].sl / 4) *
					(171 * xy[3] / 342)) * 4], sizeof(int));
			if (color != NONE)
			{
				color = (env->sick == 0) ? color : color + 23541;
				put_pxl(env, xy[0], xy[1], gclr(color, 0));
			}
			xy[3]++;
		}
		xy[0]++;
		if (xy[0] > 210 && xy[0] < 554 && xy[0] % 2 == 0)
			xy[2]++;
	}
}

void		print_reload_animation(t_env *env, int id)
{
	int				xy[4];
	unsigned int	color;

	xy[0] = 211;
	xy[2] = 0;
	while (xy[0] < 552)
	{
		xy[1] = 234;
		xy[3] = 0;
		while (xy[1]++ < 600)
		{
			ft_memcpy(&color, &env->reload.spr[id].data[(xy[2] +
				(env->reload.spr[id].sl / 4) *
					(171 * xy[3] / 342)) * 4], sizeof(int));
			if (color != NONE)
			{
				color = (env->sick == 0) ? color : color + 23541;
				put_pxl(env, xy[0], xy[1], gclr(color, 0));
			}
			xy[3]++;
		}
		xy[0]++;
		if (xy[0] > 210 && xy[0] < 554 && xy[0] % 2 == 0)
			xy[2]++;
	}
}

void		print_gun(t_env *env, int id, int xy[4])
{
	unsigned int	color;

	ft_memcpy(&color, &env->gun.spr[id].data[(xy[2] +
		(env->gun.spr[id].sl / 4) *
			(171 * xy[3] / 342)) * 4], sizeof(int));
	if (color != NONE)
	{
		color = (env->sick == 0) ? color : color + 23541;
		put_pxl(env, xy[0], xy[1], gclr(color, 0));
	}
}

void		gun(t_env *env, int id)
{
	int				xy[4];

	xy[0] = 0;
	xy[2] = 0;
	while (xy[0] < 960)
	{
		xy[1] = 0;
		xy[3] = 0;
		while (xy[1] < 600)
		{
			if (xy[0] > 210 && xy[0] < 552 && xy[1] > 234 && (xy[3]++))
				print_gun(env, id, xy);
			xy[1]++;
		}
		xy[0]++;
		if (xy[0] > 210 && xy[0] < 554 && xy[0] % 2 == 0)
			xy[2]++;
	}
}
