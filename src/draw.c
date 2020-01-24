/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 13:14:05 by videloff     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/24 13:25:27 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "doom_nukem.h"

void			free_listr(t_ray *list)
{
	if (list->next)
		free_listr(list->next);
	if (list)
		free(list);
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
		ray = (list->next != NULL) ? list : list;
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
