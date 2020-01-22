/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hud.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: videloff <videloff@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/20 12:47:10 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 12:31:18 by videloff    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "doom_nukem.h"
/*
static void		helmet(t_env *env, int drawxy[2])
{
	t_clr			clr;
	unsigned int	color;

	drawxy[0] = 0;
	while (drawxy[0] < 960)
	{
		drawxy[1] = 0;
		while (drawxy[1] < 600)
		{
			if (((int)env->sprite[1].data[(drawxy[0] + 960 * drawxy[1]) * 4]) != 0)
			{
				ft_memcpy(&color, &env->sprite[1].data[(drawxy[0] + 960 *
							drawxy[1]) * 4], sizeof(int));
				clr = gclr(color);
					put_pxl(env, drawxy[0], drawxy[1], clr);
			}
			drawxy[1]++;
		}
		drawxy[0]++;
	}
}*/

static void		draw_life(t_env *env, int drawxy[2])
{
	unsigned int	color;
	t_clr 			clr;

	// draw life
	drawxy[0] = 809;
	while (drawxy[0] < 910)
	{
		drawxy[1] = 4;
		while (drawxy[1] < 18)
		{
			color = 0xD1E7C3;
			clr = gclr(color);
			if (drawxy[0] < env->p_health + 809)
				put_pxl(env, drawxy[0], drawxy[1], clr);
			drawxy[1]++;
		}
		drawxy[0]++;
	}
}

static void		gun(t_env *env, int xy[6], int id)
{
	unsigned int 	color;
	t_clr			clr;

	xy[2] = 351;
	while (xy[2] < 607)
	{
		xy[3] = 342;
		xy[1] = 0;
		while (xy[3] < 600)
		{
			ft_memcpy(&color, &env->sprite[id].data[(xy[0] + 86 *
						(86 * xy[1] / 258)) * 4], sizeof(int));
			clr = gclra(color);
			if ((int)color != NONE)
				put_pxl(env, xy[2], xy[3], clr);
			xy[1]++;
			xy[3]++;
		}
		if (xy[2] % 3 == 0)
			xy[0]++;
		xy[2]++;
	}
}

/*
** 0 gun
** 1
** 2
** 3
** 4
** 5
** 6
** 7
*/

/*
** 0 = x XPM
** 1 = y XPM
** 2 = x draw
** 3 = y draw
** 4 = width XPM
** 5 = Height XPM
*/

static void		print_hud(t_env *env, int xy[6], int id)
{
	t_clr			clr;
	unsigned int	color;
	int				tmp;

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
	xy[0] = 0;
	xy[1] = 0;
	xy[2] = 0;
	xy[3] = 365;
	xy[4] = 251;
	xy[5] = 235;
	print_hud(env, xy, 5);
	xy[0] = 0;
	xy[1] = 0;
	xy[2] = 340;
	xy[3] = 588;
	xy[4] = 280;
	xy[5] = 12;
	print_hud(env, xy, 6);
	xy[0] = 0;
	xy[1] = 0;
	xy[2] = 709;
	xy[3] = 262;
	xy[4] = 251;
	xy[5] = 338;
	print_hud(env, xy, 7);
}



void			draw_hud(t_env *env)
{
	int				xy[6];
	xy[0] = 0;
	xy[1] = 0;
	xy[2] = 351;
	xy[3] = 342;
	xy[4] = 86;
	xy[5] = 86;
	gun(env, xy, 1);
	xy[0] = 0;
	xy[1] = 0;
	xy[2] = 0;
	xy[3] = 0;
	xy[4] = 126;
	xy[5] = 98;
	print_hud(env, xy, 2);
	xy[0] = 0;
	xy[1] = 0;
	xy[2] = 314;
	xy[3] = 0;
	xy[4] = 331;
	xy[5] = 37;
	print_hud(env, xy, 3);
	xy[0] = 0;
	xy[1] = 0;
	xy[2] = 784;
	xy[3] = 0;
	xy[4] = 176;
	xy[5] = 80;
	print_hud(env, xy, 4);
	draw_hud2(env, xy);
	draw_life(env, xy);
}
/*
void			draw_hud(t_env *env)
{
	int				drawxy[2];

	drawxy[0] = 0;
	drawxy[1] = 0;
	gun(env, drawxy);
	helmet(env, drawxy);
}
*/