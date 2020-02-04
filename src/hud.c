/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hud.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/20 12:47:10 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/04 12:44:47 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
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
			color = 0xD1E7C3;
			clr = gclr(color, 0);
			if (xy[0] < env->p_health + 805)
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
	clr = gclr(color, 0);
	if ((int)color != NONE)
		put_pxl(env, xy[2], tmp, clr);
}

static void		bullet(t_env *env, int xy[6], int id)
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

void			print_hud(t_env *env, int id)
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

/*
** 0 = Parcourt le XPM		X
** 1 = Parcourt le XPM		Y
** 2 = Affiche a l'ecran	X
** 3 = Affiche a l'ecran	Y
** 4 = Taille du XPM en 	X
** 5 = Taille du XPM en		Y
*/

void			draw_hud(t_env *env)
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
