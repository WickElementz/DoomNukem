/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalabidi <yalabidi@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:14:05 by videloff          #+#    #+#             */
/*   Updated: 2020/03/12 12:43:58 by yalabidi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void			free_listr(t_ray *list)
{
	if (list->next)
		free_listr(list->next);
	if (list)
		free(list);
}

void			set_sprite(t_ray *maillon, int z)
{
	if (maillon->next)
		set_sprite(maillon->next, z);
	if (maillon)
	{
		maillon->wall = (64 / maillon->dist) * ((WIN_WIDTH / 2) /
						tan(FOV / 2 * RAD));
		maillon->cmpt = (maillon->wall * (1 - (z / 64.0)) - WIN_HEIGHT / 2 < 0)
						? 0 : maillon->wall * (1 - (z / 64.0)) - WIN_HEIGHT / 2;
		maillon->mrg = (maillon->cmpt <= 0) ? WIN_HEIGHT - ((WIN_HEIGHT / 2) -
						(z * maillon->wall / 64) + maillon->wall) : 0;
		maillon->cmpt += (maillon->type == 3 && maillon->door >= 0) ?
						maillon->wall * maillon->door / 64 : 0;
	}
}

t_clr			add_color(t_env *env, t_ray *ray, int xy[3])
{
	unsigned int	color;
	float			cs[2];
	t_clr			clr;

	if (xy[1] < ray->mrg)
		color = add_color2(env, ray, xy, &cs);
	else if (xy[1] > ray->mrg && xy[1] < ray->mrg + ray->wall &&
				ray->cmpt <= ray->wall && ray->cmpt < ray->wall - 1)
	{
		ft_memcpy(&color, &env->text[(int)ray->id].data[(((int)ray->mod) +
			(env->text[(int)ray->id].sl / 4) * (64 * ray->cmpt / ray->wall)) * 4], sizeof(int));
		ray->cmpt++;
	}
	else
		color = add_color3(env, ray, xy, &cs);
	if (env->sick == 1)
		clr = gclr(color + 5000, 245);
	else
		clr = gclr(color, 0);
	return (clr);
}

t_clr			add_sprite(t_env *env, t_ray *ray, int xy[3])
{
	unsigned int	color;
	t_clr			clr;

	color = 0;
	if (xy[1] > ray->mrg && xy[1] < ray->mrg + ray->wall && ray->type == 3 &&
		ray->cmpt <= ray->wall)
	{
		if (ray->cmpt > ray->wall)
			color = 0;
		else
			color = add_sprite2(env, ray, color);
	}
	else if (xy[1] > ray->mrg && xy[1] < ray->mrg + ray->wall && ray->cmpt <=
				ray->wall)
	{
		if (ray->cmpt < ray->wall - 1)
			ft_memcpy(&color, &env->text[(int)ray->id].data[(((int)ray->mod) +
					(env->text[(int)ray->id].sl / 4) * (64 * ray->cmpt / ray->wall)) * 4], sizeof(int));
		ray->cmpt++;
		if (env->sick == 1)
			color *= 12 + 255;
	}
	else
		color = 0;
	clr = gclr(color, 0);
	return (clr);
}

void			draw_column(t_env *env, t_ray *ray, int xy[3])
{
	t_clr	res;
	t_clr	clr;
	t_ray	*l;

	set_sprite(ray, env->cam.z);
	if (ray->mod < 64)
		xy[1] = draw_column2(env, ray, xy);
	while (ray->mod < 64 && xy[1]++ - env->up < WIN_HEIGHT / 2)
	{
		res = add_sprite(env, ray, xy);
		l = ray->next;
		while (l && l->dist <= ray->dist)
		{
			clr = add_sprite(env, l, xy);
			if (clr.r != 0 && clr.g != 0 && clr.b != 0)
			{
				res = clr;
				l = l->next;
				break ;
			}
			l = l->next;
		}
		while (l && xy[1] > l->mrg && xy[1] < l->mrg + l->wall && (l->cmpt++))
			l = l->next;
		if (ray->mod < 64)
			res = draw_column3(env, ray, res, xy);
	}
}
