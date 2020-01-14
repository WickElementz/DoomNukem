/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: videloff <videloff@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 13:14:05 by videloff     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/13 13:04:20 by videloff    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "doom_nukem.h"

t_clr	gclr(unsigned int color)
{
	t_clr	clr;

	clr.r = (color & 0xFF0000) >> 16;
	clr.g = (color & 0x00FF00) >> 8;
	clr.b = (color & 0x0000FF);
	clr.a = 0;
	return (clr);
}

static void		put_pxl(t_env *env, int x, int y, unsigned int color[2])
{
	t_clr	clr;

	if (env->sick == 1)
		color[0] *= 1000 + 255;
	clr = gclr(color[0]);
	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		env->data_ptr[(y * WIN_WIDTH + x) * 4] = clr.b;
		env->data_ptr[(y * WIN_WIDTH + x) * 4 + 1] = clr.g;
		env->data_ptr[(y * WIN_WIDTH + x) * 4 + 2] = clr.r;
		env->data_ptr[(y * WIN_WIDTH + x) * 4 + 3] = (color[1] == 0) ? clr.a : clr.a + 105;
	}
}

void		draw_column(t_env *env, float (*view)[4], int (*xy)[3])
{
	int				wall;
	int				cmpt;
	unsigned int	color[2];
	int				mrg;

	wall = (64 / (*view)[0]) * ((WIN_WIDTH / 2) / tan(FOV / 2 * M_PI / 180));
	cmpt = (wall <= WIN_HEIGHT) ? 0 : wall / 2 - WIN_HEIGHT / 2;
	(*xy)[1] = (wall <= WIN_HEIGHT) ? (WIN_HEIGHT - wall) / 2 : 0;
	mrg = wall + (*xy)[1];
	while ((*xy)[1] < WIN_HEIGHT && cmpt < wall)
	{
		ft_memcpy(&color[0], &env->text[(int)(*view)[2]].data[(((int)(*view)[1]) +
					64 * (64 * cmpt / wall)) * 4], sizeof(int));
		if ((*xy)[1] - env->up >= 0 && (*xy)[1] - env->up <= WIN_HEIGHT / 2)
		{
			color[1] = 0;
			put_pxl(env, (*xy)[0], (*xy)[1] - env->up, color);
		}
		(*xy)[1]++;
		cmpt++;
	}
	while ((*xy)[1] < WIN_HEIGHT)
	{
		if ((*xy)[1] - env->up >= 0 && (*xy)[1] - env->up <= WIN_HEIGHT / 2)
		{
			color[0] = 0x95671F;
			color[1] = 0;
			put_pxl(env, (*xy)[0], (*xy)[1] - env->up, color);
		}
		if ((*xy)[1] - env->up  - mrg >= 0 && (*xy)[1] - env->up -mrg <= WIN_HEIGHT / 2)
		{
			color[0] = 0x308FC9;
			color[1] = 0;
			put_pxl(env, (*xy)[0], (*xy)[1] - env->up - mrg, color);
		}
		(*xy)[1]++;
	}
}
