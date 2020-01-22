/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hud.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: videloff <videloff@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/20 12:47:10 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 16:15:40 by videloff    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "doom_nukem.h"

static void		draw_life(t_env *env, int xy[2])
{
	unsigned int	color;
	t_clr			clr;

	xy[0] = 809;
	while (xy[0] < 910)
	{
		xy[1] = 4;
		while (xy[1] < 18)
		{
			color = 0xD1E7C3;
			clr = gclr(color);
			if (xy[0] < env->p_health + 809)
				put_pxl(env, xy[0], xy[1], clr);
			xy[1]++;
		}
		xy[0]++;
	}
}

static void		print_hud(t_env *env, int xy[6], int id)
{
	t_clr			clr;
	unsigned int	color;
	int				tmp;

	xy[0] = 0;
	while (xy[0] < xy[4])
	{
		xy[1] = 0;
		tmp = xy[3];
		while (xy[1] < xy[5])
		{
			ft_memcpy(&color, &env->sprite[id].data[(xy[0] + xy[4] *
						xy[1]) * 4], sizeof(int));
			clr = gclra(color);
			if ((int)color != NONE)
				put_pxl(env, xy[2], tmp, clr);
			xy[1]++;
			tmp++;
		}
		xy[0]++;
		xy[2]++;
	}
}

static void		draw_hud2(t_env *env, int xy[6])
{
	xy[2] = 0;
	xy[3] = 365;
	xy[4] = 251;
	xy[5] = 235;
	print_hud(env, xy, 5);
	xy[2] = 340;
	xy[3] = 588;
	xy[4] = 280;
	xy[5] = 12;
	print_hud(env, xy, 6);
	xy[2] = 709;
	xy[3] = 262;
	xy[4] = 251;
	xy[5] = 338;
	print_hud(env, xy, 7);
	draw_life(env, xy);
	xy[2] = 920;
	xy[3] = 24;
	xy[4] = 6;
	xy[5] = 20;
	bullet(env, xy, 8);
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
	int				xy[6];

	xy[0] = 0;
	xy[1] = 0;
	xy[2] = 350;
	xy[3] = 342;
	xy[4] = 86;
	xy[5] = 86;
	gun(env, xy, 1);
	xy[2] = 0;
	xy[3] = 0;
	xy[4] = 126;
	xy[5] = 98;
	print_hud(env, xy, 2);
	xy[2] = 315;
	xy[3] = 0;
	xy[4] = 331;
	xy[5] = 37;
	print_hud(env, xy, 3);
	xy[2] = 784;
	xy[3] = 0;
	xy[4] = 176;
	xy[5] = 80;
	print_hud(env, xy, 4);
	draw_hud2(env, xy);
}
