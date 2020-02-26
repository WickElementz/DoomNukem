/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jominodi <jominodi@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:14:05 by videloff          #+#    #+#             */
/*   Updated: 2020/02/26 11:44:35 by jominodi         ###   ########lyon.fr   */
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
		maillon->wall = (64 / maillon->dist) * ((WIN_WIDTH / 2) / tan(FOV / 2 * M_PI / 180));
		maillon->cmpt = (maillon->wall * (1 - (z / 64.0)) - WIN_HEIGHT / 2 < 0) ? 0 : maillon->wall * (1 - (z / 64.0)) - WIN_HEIGHT / 2;
		maillon->mrg = (maillon->cmpt <= 0) ? WIN_HEIGHT - ((WIN_HEIGHT / 2) - (z * maillon->wall / 64) + maillon->wall) : 0;
		maillon->cmpt += (maillon->type == 3 && maillon->door >= 0) ? maillon->wall * maillon->door / 64: 0;
	}
}

void			draw_column(t_env *env, t_ray *ray, int xy[3])
{
	t_clr	res;
	t_clr	clr;
	t_ray	*list;
	
	set_sprite(ray, env->cam.z);
	while (xy[1] - env->up < 0)
	{
		list = ray;
		while (list)
		{
			if (xy[1] > list->mrg && list->cmpt <= list->wall)
				list->cmpt++;
			list = list->next;
		}
		xy[1]++;
	}
	while (xy[1] - env->up < WIN_HEIGHT / 2)
	{
		res = add_sprite(env, ray, xy);
		list = ray->next;
		while (list && list->dist <= ray->dist)
		{
			clr = add_sprite(env, list, xy);
			if (clr.r != 0 && clr.g != 0 && clr.b != 0)
			{
				res = clr;
				list = list->next;
				break;
			}
			list = list->next;
		}
		while (list && xy[1] > list->mrg && xy[1] < list->mrg + list->wall)
		{
			list->cmpt++;
			list = list->next;
		}
		if (res.r == 0 && res.g == 0 && res.b == 0)
			res = add_color(env, ray, xy);
		if (xy[1] - env->up >= 0 && xy[1] - env->up <= WIN_HEIGHT / 2)
			put_pxl(env, xy[0], xy[1] - env->up, res);
		xy[1]++;
	}
	
}

t_clr			add_color(t_env *env, t_ray *ray, int xy[3])
{
	unsigned int	color;
	float			s;
	float			c;
	t_clr			clr;

	if (xy[1] < ray->mrg)
	{
		c = (((64 - env->cam.z) / (WIN_HEIGHT / 2 - xy[1])) * SCREEN) / cos((env->cam.angle - ray->ang) * M_PI / 180) * cos(ray->ang * M_PI / 180);
		s = (((64 - env->cam.z) / (WIN_HEIGHT / 2 - xy[1])) * SCREEN) / cos((env->cam.angle - ray->ang) * M_PI / 180) * sin(ray->ang * M_PI / 180);
		ft_memcpy(&color, &env->text[5].data[((int)(env->cam.x + s) % 64 + (int)((env->text[4].sl / 4) * ((int)(c + env->cam.y) % 64))) * 4], sizeof(int));
	}
	else if (xy[1] > ray->mrg && xy[1] < ray->mrg + ray->wall && ray->cmpt <= ray->wall)
	{
		ft_memcpy(&color, &env->text[(int)ray->id].data[(((int)ray->mod) +
			64 * (64 * ray->cmpt / ray->wall)) * 4], sizeof(int));
		ray->cmpt++;
	}
	else
	{
		c = ((env->cam.z / (xy[1] - WIN_HEIGHT / 2)) * SCREEN) / cos((env->cam.angle - ray->ang) * M_PI / 180) * cos(ray->ang * M_PI / 180);
		s = ((env->cam.z / (xy[1] - WIN_HEIGHT / 2)) * SCREEN) / cos((env->cam.angle - ray->ang) * M_PI / 180) * sin(ray->ang * M_PI / 180);
		ft_memcpy(&color, &env->text[4].data[((int)(env->cam.x + s) % 64 + (int)((env->text[4].sl / 4) * ((int)(c + env->cam.y) % 64))) * 4], sizeof(int));
	}
	if (env->sick == 1)
		color += 15000;
	clr = gclr(color, 0);
	return(clr);
}

t_clr			add_sprite(t_env *env, t_ray *ray, int xy[3])
{
	unsigned int	color;
	t_clr			clr;

	if (xy[1] > ray->mrg && xy[1] < ray->mrg + ray->wall && ray->type == 3 && ray->cmpt <= ray->wall)
	{
		if (ray->cmpt > ray->wall)
			color = 0;
		else
		{
			ft_memcpy(&color, &env->text[(int)ray->id].data[(((int)ray->mod) + 64 * (64 * ray->cmpt / ray->wall)) * 4], sizeof(int));
			ray->cmpt++;
			if (env->sick == 1)
				color *= 12 + 255;
		}
	}
	else if (xy[1] > ray->mrg && xy[1] < ray->mrg + ray->wall && ray->cmpt <= ray->wall)
	{
		ft_memcpy(&color, &env->text[(int)ray->id].data[(((int)ray->mod) + 64 * (64 * ray->cmpt / ray->wall)) * 4], sizeof(int));
		ray->cmpt++;
		if (env->sick == 1)
			color *= 12 + 255;
	}
	else
		color = 0;
	clr = gclr(color, 0);
	return(clr);
}