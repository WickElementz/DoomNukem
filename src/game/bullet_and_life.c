/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bullet_and_life.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videloff <videloff@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:47:10 by jominodi          #+#    #+#             */
/*   Updated: 2020/06/22 14:29:22 by videloff         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static void		draw_life(t_env *env, int xy[2])
{
	unsigned int	color;
	t_clr			clr;

	xy[0] = 805;
	while (xy[0] < 908)
	{
		xy[1] = 8;
		while (xy[1] < 22)
		{
			color = (env->sick == 0) ? 0xD1E7C3 : 0xD1E7C3 + 23541;
			clr = gclr(color, 0);
			if (xy[0] < env->player.life + 805)
				put_pxl(env, xy[0], xy[1], clr);
			xy[1]++;
		}
		xy[0]++;
	}
}

static void		print_bullet(t_env *env, int xy[6], int id, int tmp)
{
	t_clr			clr;
	unsigned int	color;

	ft_memcpy(&color, &env->sprite[id].data[(xy[0] + (env->sprite[id].sl / 4) *
				xy[1]) * 4], sizeof(int));
	if ((int)color != NONE)
	{
		color = (env->sick == 0) ? color : color + 23541;
		clr = gclr(color, 0);
		put_pxl(env, xy[2], tmp, clr);
	}
}

static void		bullet(t_env *env, int xy[6], int id)
{
	int				tmp;
	int				ammo_tmp;

	ammo_tmp = 0;
	while (ammo_tmp++ < env->player.ammo)
	{
		xy[0] = 0;
		xy[2] -= 12;
		while (xy[0] < xy[4])
		{
			xy[1] = 0;
			tmp = xy[3];
			while (xy[1] < xy[5])
			{
				print_bullet(env, xy, id, tmp);
				xy[1]++;
				tmp++;
			}
			xy[0]++;
			xy[2]--;
		}
	}
}

void			draw_li_bu(t_env *env)
{
	int		xy[6];

	xy[0] = 0;
	xy[1] = 0;
	draw_life(env, xy);
	xy[2] = 915;
	xy[3] = 28;
	xy[4] = 6;
	xy[5] = 20;
	bullet(env, xy, 1);
}
