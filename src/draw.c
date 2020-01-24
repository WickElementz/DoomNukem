/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 13:14:05 by videloff     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/24 11:40:56 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "doom_nukem.h"

t_clr			gclr(unsigned int color)
{
	t_clr	clr;

	clr.r = (color & 0xFF0000) >> 16;
	clr.g = (color & 0x00FF00) >> 8;
	clr.b = (color & 0x0000FF);
	clr.a = 0;
	return (clr);
}

t_clr			gclra(unsigned int color)
{
	t_clr	clr;

	clr.r = (color & 0xFF0000) >> 16;
	clr.g = (color & 0x00FF00) >> 8;
	clr.b = (color & 0x0000FF);
	clr.a = 255;
	return (clr);
}

void			free_listr(t_ray *list)
{
	if (list->next)
		free_listr(list->next);
	if (list)
		free(list);
}

void			put_pxl(t_env *env, int x, int y, t_clr clr)
{
	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		env->data_ptr[(y * WIN_WIDTH + x) * 4] = clr.b;
		env->data_ptr[(y * WIN_WIDTH + x) * 4 + 1] = clr.g;
		env->data_ptr[(y * WIN_WIDTH + x) * 4 + 2] = clr.r;
		env->data_ptr[(y * WIN_WIDTH + x) * 4 + 3] = clr.a;
	}
}

void			put_pxl2(t_env *env, int x, int y, t_clr clr)
{
	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		env->data_ptr2[(y * WIN_WIDTH + x) * 4] = clr.b;
		env->data_ptr2[(y * WIN_WIDTH + x) * 4 + 1] = clr.g;
		env->data_ptr2[(y * WIN_WIDTH + x) * 4 + 2] = clr.r;
		env->data_ptr2[(y * WIN_WIDTH + x) * 4 + 3] = clr.a;
	}
}

void			draw_column(t_env *env, t_ray *ray, int xy[3])
{
	t_clr	res;
	t_clr 	clr;
	t_ray	*list;


	ray->wall = (64 / ray->dist) * ((WIN_WIDTH / 2) / tan(FOV / 2 * M_PI / 180));
	ray->cmpt = (ray->wall <= WIN_HEIGHT) ? 0 : ray->wall / 2 - WIN_HEIGHT / 2;
	ray->mrg = (ray->wall <= WIN_HEIGHT) ? (WIN_HEIGHT - ray->wall) / 2 : 0;
	list = ray;
	while (xy[1] - env->up < WIN_HEIGHT / 2)
	{
		ray = list;
		while (ray)
		{
			clr = add_sprite(env, ray, xy);
			if (clr.r != 0 || clr.g != 0 || clr.b != 0)
			{
				res = clr;
				break;
			}
			ray = ray->next;
		}
		xy[1]++;
		if (xy[1] - env->up >= 0 && xy[1] - env->up <= WIN_HEIGHT / 2)
			put_pxl(env, xy[0], xy[1] - env->up, res);
//		dprintf(1, "ca\n");
	}
}

t_clr			add_sprite(t_env *env, t_ray *ray, int xy[3])
{
	unsigned int	color;
	t_clr			clr;

	if (xy[1] < ray->mrg)
		color = 0x308FC9;
	else if (xy[1] > ray->mrg && xy[1] < ray->mrg + ray->wall)
	{
		ft_memcpy(&color, &env->text[(int)ray->id].data[(((int)ray->mod) +
			64 * (64 * ray->cmpt / ray->wall)) * 4], sizeof(int));
		ray->cmpt++;
	}
	else// if (xy[1] > ray->mrg + ray->wall)
		color = 0x95671F;
	if (env->sick == 1)
		color *= 12 + 255;
	clr = gclr(color);
	return(clr);
}
