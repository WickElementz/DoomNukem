/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videloff <videloff@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 15:11:05 by videloff          #+#    #+#             */
/*   Updated: 2020/06/22 14:29:22 by videloff         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

t_clr			draw_column3(t_env *env, t_ray *ray, t_clr res, int xy[3])
{
	if (res.r == 0 && res.g == 0 && res.b == 0)
		res = add_color(env, ray, xy);
	if (xy[1] - env->up >= 0 && xy[1] - env->up <= WIN_HEIGHT / 2)
		put_pxl(env, xy[0], xy[1] - env->up, res);
	return (res);
}

int				draw_column2(t_env *env, t_ray *ray, int xy[3])
{
	t_ray	*list;

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
	return (xy[1]);
}

unsigned int	add_color3(t_env *env, t_ray *ray, int xy[3], float (*cs)[2])
{
	unsigned int color;

	color = 0;
	(*cs)[0] = ((env->cam.z / (xy[1] - WIN_HEIGHT / 2)) * SCREEN) /
	cos((env->cam.angle - ray->ang) * RAD) * cos(ray->ang * RAD);
	(*cs)[1] = ((env->cam.z / (xy[1] - WIN_HEIGHT / 2)) * SCREEN) /
	cos((env->cam.angle - ray->ang) * RAD) * sin(ray->ang * RAD);
	if ((int)(env->cam.x + (*cs)[1]) % 64 < 64 &&
		(int)(env->cam.x + (*cs)[1]) % 64 >= 0 &&
		(int)((*cs)[0] + env->cam.y) % 64 < 64 &&
		(int)((*cs)[0] + env->cam.y) % 64 >= 0)
		ft_memcpy(&color, &env->text[4].data[((int)(env->cam.x +
		(*cs)[1]) % 64 + (int)((env->text[4].sl / 4) *
		((int)((*cs)[0] + env->cam.y) % 64))) * 4],
		sizeof(int));
	return (color);
}

unsigned int	add_color2(t_env *env, t_ray *ray, int xy[3], float (*cs)[2])
{
	unsigned int color;

	color = 0;
	(*cs)[0] = (((64 - env->cam.z) / (WIN_HEIGHT / 2 - xy[1])) * SCREEN) /
	cos((env->cam.angle - ray->ang) * RAD) * cos(ray->ang * RAD);
	(*cs)[1] = (((64 - env->cam.z) / (WIN_HEIGHT / 2 - xy[1])) * SCREEN) /
	cos((env->cam.angle - ray->ang) * RAD) * sin(ray->ang * RAD);
	if ((int)(env->cam.x + (*cs)[1]) % 64 < 64 &&
		(int)(env->cam.x + (*cs)[1]) % 64 >= 0 &&
		(int)((*cs)[0] + env->cam.y) % 64 < 64 &&
		(int)((*cs)[0] + env->cam.y) % 64 >= 0)
		ft_memcpy(&color, &env->text[5].data[((int)(env->cam.x +
		(*cs)[1]) % 64 + (int)((env->text[5].sl / 4) *
		((int)((*cs)[0] + env->cam.y) % 64))) * 4],
		sizeof(int));
	return (color);
}

unsigned int	add_sprite2(t_env *env, t_ray *ray, unsigned int color)
{
	if ((((int)ray->mod)
		+ (env->text[(int)ray->id].sl / 4) *
		(64 * ray->cmpt / ray->wall)) > 4095 || (((int)ray->mod)
		+ (env->text[(int)ray->id].sl / 4) *
		(64 * ray->cmpt / ray->wall)) < 0)
		return (0);
	else
	{
		if (ray->cmpt < 4096)
			ft_memcpy(&color, &env->text[(int)ray->id].data[(((int)ray->mod)
				+ (env->text[(int)ray->id].sl / 4) *
				(64 * ray->cmpt / ray->wall)) * 4], sizeof(int));
		ray->cmpt++;
		if (env->sick == 1)
			color *= 12 + 255;
		return (color);
	}
}
