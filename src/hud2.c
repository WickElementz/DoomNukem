/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hud2.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/22 15:02:28 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/24 15:40:47 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "doom_nukem.h"

void		print_bullet(t_env *env, int xy[6], int id, int tmp)
{
	t_clr			clr;
	unsigned int	color;

	ft_memcpy(&color, &env->sprite[id].data[(xy[0] + xy[4] *
				xy[1]) * 4], sizeof(int));
	clr = gclr(color);
	if ((int)color != NONE)
		put_pxl(env, xy[2], tmp, clr);
}

void		bullet(t_env *env, int xy[6], int id)
{
	int				tmp;
	int				ammo_tmp;

	ammo_tmp = 0;
	while (ammo_tmp++ < env->ammo)
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

void		print_gun_animation(t_env *env, int id)
{
	int xy[4];
	t_clr clr;
	unsigned int color;

	xy[0] = 210;
	xy[2] = 0;
	while (xy[0] < 554)
	{
		xy[1] = 234;
		xy[3] = 0;
		while (xy[1] < 600)
		{
			ft_memcpy(&color, &env->sprite[id].data[(xy[2] + 171 *
					(171 * xy[3] / 342)) * 4], sizeof(int));
			if ((int)color != NONE)
			{
				clr = gclr(color);
				put_pxl2(env, xy[0], xy[1], clr);
			}
			else
			{
				clr = gclra(color);
				put_pxl2(env, xy[0], xy[1], clr);
			}
			xy[3]++;
			xy[1]++;
		}
		xy[0]++;
		if (xy[0] > 210 && xy[0] < 554 && xy[0] % 2 == 0)
			xy[2]++;
	}
}

void		print_gun(t_env *env, int id)
{
	int xy[4];
	t_clr clr;
	unsigned int color;

	xy[0] = 0;
	xy[2] = 0;
	while (xy[0] < 960)
	{
		xy[1] = 0;
		xy[3] = 0;
		while (xy[1] < 600)
		{
			if (xy[0] > 210 && xy[0] < 554 && xy[1] > 234)
			{
				ft_memcpy(&color, &env->sprite[id].data[(xy[2] + 171 *
						(171 * xy[3] / 342)) * 4], sizeof(int));
				if ((int)color != NONE)
				{
					clr = gclr(color);
					put_pxl2(env, xy[0], xy[1], clr);
				}
				else
				{
					clr = gclra(color);
					put_pxl2(env, xy[0], xy[1], clr);
				}
				xy[3]++;
			}
			else
			{
				color = 84141642;
				clr = gclra(color);
				put_pxl2(env, xy[0], xy[1], clr);
			}
			xy[1]++;
		}
		xy[0]++;
		if (xy[0] > 210 && xy[0] < 554 && xy[0] % 2 == 0)
			xy[2]++;
	}
}