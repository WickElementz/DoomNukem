/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hud.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/20 12:47:10 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 14:45:31 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "doom_nukem.h"

/*static void		life_and_mun(t_env *env, int drawxy[2], unsigned int color[2]);
{
	// draw life
	while (drawxy[0] < 960)
	{
		drawxy[1] = 0;
		while (drawxy[1] < 600)
		{
			ft_memcpy(&color[0], &env->sprite[0].data[(drawxy[0] + 960 *
						drawxy[0]) * 4], sizeof(int));
			color[1] = 0;
			if (color[0] != 0xFFFFFF)
				put_pxl(env, drawxy[0], drawxy[1], color);
			drawxy[1]++;
		}
		drawxy[0]++;
	}
	// draw mun
	while (drawxy[0] < 960)
	{
		drawxy[1] = 0;
		while (drawxy[1] < 600)
		{
			ft_memcpy(&color[0], &env->sprite[0].data[(drawxy[0] + 960 *
						drawxy[0]) * 4], sizeof(int));
			color[1] = 0;
			if (color[0] != 0xFFFFFF)
				put_pxl(env, drawxy[0], drawxy[1], color);
			drawxy[1]++;
		}
		drawxy[0]++;
	}
}*/

static void		helmet(t_env *env, int drawxy[2], unsigned int color[2])
{
	drawxy[0] = 0;
	while (drawxy[0] < 960)
	{
		drawxy[1] = 0;
		while (drawxy[1] < 600)
		{
			ft_memcpy(&color[0], &env->sprite[1].data[(drawxy[0] + 960 *
						drawxy[1]) * 4], sizeof(int));
			if ((int)color[0] != NONE)
				put_pxl(env, drawxy[0], drawxy[1], color);
			drawxy[1]++;
		}
		drawxy[0]++;
	}
}

static void		gun(t_env *env, int drawxy[2], unsigned int color[2])
{
	int 			x;
	int 			y;

	drawxy[0] = 351;
	x = 0;
	while (drawxy[0] < 607)
	{
		drawxy[1] = 342;
		y = 0;
		while (drawxy[1] < 600)
		{
			ft_memcpy(&color[0], &env->sprite[0].data[(x + 86 *
						(86 * y / 258)) * 4], sizeof(int));
			if ((int)color[0] != NONE)
				put_pxl(env, drawxy[0], drawxy[1], color);
			y++;
			drawxy[1]++;
		}
		if (drawxy[0] % 3 == 0)
			x++;
		drawxy[0]++;
	}
}

void			draw_hud(t_env *env)
{
	int				drawxy[2];
	unsigned int	color[2];

	drawxy[0] = 0;
	drawxy[1] = 0;
	color[1] = 0;
	gun(env, drawxy, color);
	helmet(env, drawxy, color);
//	life_and_mun(env, drawxy, color);
}