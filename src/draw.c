/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 13:14:05 by videloff     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 15:38:55 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "doom_nukem.h"

t_clr	gclra(unsigned int color)
{
	t_clr	clr;

	clr.r = (color & 0xFF0000) >> 16;
	clr.g = (color & 0x00FF00) >> 8;
	clr.b = (color & 0x0000FF);
	clr.a = 0;
	return (clr);
}

t_clr	gclr(unsigned int color)
{
	t_clr	clr;

	clr.r = (color & 0xFF0000) >> 16;
	clr.g = (color & 0x00FF00) >> 8;
	clr.b = (color & 0x0000FF);
	clr.a = 155;
	return (clr);
}

void		put_pxl(t_env *env, int x, int y, t_clr clr)
{
	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		env->data_ptr[(y * WIN_WIDTH + x) * 4] = clr.b;
		env->data_ptr[(y * WIN_WIDTH + x) * 4 + 1] = clr.g;
		env->data_ptr[(y * WIN_WIDTH + x) * 4 + 2] = clr.r;
		env->data_ptr[(y * WIN_WIDTH + x) * 4 + 3] = clr.a;
	}
}

void		draw_column(t_env *env, t_ray *ray, int xy[3])
{
	int				wall;
	int				cmpt;
	t_clr			clr;
	unsigned int	color;
	int				mrg;

	wall = (64 / ray->dist) * ((WIN_WIDTH / 2) / tan(FOV / 2 * M_PI / 180));
	cmpt = (wall <= WIN_HEIGHT) ? 0 : wall / 2 - WIN_HEIGHT / 2;
	mrg = (wall <= WIN_HEIGHT) ? (WIN_HEIGHT - wall) / 2 : 0;
	while (xy[1] - env->up < WIN_HEIGHT / 2)
	{
		if (xy[1] < mrg)
			color = 0x308FC9;
		else if (xy[1] > mrg && xy[1] < mrg + wall)
		{
			ft_memcpy(&color, &env->text[(int)ray->id].data[(((int)ray->mod) +
				64 * (64 * cmpt / wall)) * 4], sizeof(int));
			cmpt++;
		}
		else if (xy[1] > mrg + wall)
			color = 0x95671F;
		// add_sprite(ray, )
		if (env->sick == 1)
			color *= 12 + 255;
		clr = gclra(color);
		if (xy[1] - env->up >= 0 && xy[1] - env->up <= WIN_HEIGHT / 2)
			put_pxl(env, xy[0], xy[1] - env->up, clr);
		xy[1]++;
	}
}
