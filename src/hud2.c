/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hud2.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: videloff <videloff@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/22 15:02:28 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/23 15:06:09 by videloff    ###    #+. /#+    ###.fr     */
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
	clr = gclra(color);
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
	mlx_string_put(env->mlx_ptr, env->win_ptr, 860, 60, 0x35FDEF,
					ft_itoa(env->r_ammo));
}

void		gun(t_env *env, int id, int xy[6])
{
	unsigned int	color;
	t_clr			clr;

	xy[0] = 0;
	xy[2] = (960 / 2) - xy[4];
	while (xy[2] < ((960 / 2) + xy[4]))
	{
		xy[3] = 600 - (xy[5] * 2);
		xy[1] = 0;
		while (xy[3] < 600)
		{
			ft_memcpy(&color, &env->sprite[id].data[(xy[0] + xy[4] *
						(xy[5] * xy[1] / (xy[5] * 2))) * 4], sizeof(int));
			clr = gclra(color);
			if ((int)color != NONE)
				put_pxl(env, xy[2], xy[3], clr);
			xy[1]++;
			xy[3]++;
		}
		if (xy[2] % 2 == 0)
			xy[0]++;
		xy[2]++;
	}
}
