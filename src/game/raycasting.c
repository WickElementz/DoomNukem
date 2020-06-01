/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jominodi <jominodi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 13:51:12 by videloff          #+#    #+#             */
/*   Updated: 2020/06/01 11:02:51 by jominodi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_ray	*find_ver_wall(t_env *env, float ang)
{
	float	xy[4];
	t_ray	*sprite;
	t_ray	*ver;

	ver = create_ray(0, 0, 0);
	sprite = ver;
	set_xy(env->cam, ang, &xy, 0);
	while ((int)xy[0] / 64 >= 0 && (int)xy[0] / 64 < SIZE_MAP &&
		(int)xy[1] / 64 >= 0 && (int)xy[1] / 64 < SIZE_MAP)
	{
		if (check_type(xy, env->map, 'D'))
			sprite->next = add_doors(xy, env, ang, 0);
		if (check_type(xy, env->map, 'Y'))
			sprite->next = create_spr(xy, env, ang);
		if (check_type(xy, env->map, 'P'))
			sprite->next = add_pane(xy, env, ang, 0);
		if (sprite->next != NULL)
			sprite = sprite->next;
		if (check_type(xy, env->map, 'W'))
			break ;
		xy[1] += xy[3];
		xy[0] += xy[2];
	}
	set_wall_v(ang, env->cam, xy, ver);
	return (ver);
}

t_ray	*find_hor_wall(t_env *env, float ang)
{
	float	xy[4];
	t_ray	*sprite;
	t_ray	*hor;

	hor = create_ray(0, 0, 0);
	sprite = hor;
	set_xy(env->cam, ang, &xy, 1);
	while ((int)xy[0] / 64 >= 0 && (int)xy[0] / 64 < SIZE_MAP &&
		(int)xy[1] / 64 >= 0 && (int)xy[1] / 64 < SIZE_MAP)
	{
		if (check_type(xy, env->map, 'D'))
			sprite->next = add_doors(xy, env, ang, 1);
		if (check_type(xy, env->map, 'Y'))
			sprite->next = create_spr(xy, env, ang);
		if (check_type(xy, env->map, 'P'))
			sprite->next = add_pane(xy, env, ang, 1);
		if (sprite->next != NULL)
			sprite = sprite->next;
		if (check_type(xy, env->map, 'W'))
			break ;
		xy[1] += xy[3];
		xy[0] += xy[2];
	}
	set_wall_h(ang, env->cam, xy, hor);
	return (hor);
}

/*
** dist[0] = distance du mur
** dist[1] = colonne qu'on touche
** dist[2] = Orientation du mur
*/

t_ray	*closest_wall(t_env *env, float ang)
{
	t_ray	*distance;
	t_ray	*hor;
	t_ray	*ver;

	distance = create_ray(0, 0, 0);
	distance->ang = ang;
	if (ang != 0 && ang != 180)
		hor = find_hor_wall(env, ang);
	else
		hor = create_ray(2147483648, 0, 0);
	if (ang != 90 && ang != 270)
		ver = find_ver_wall(env, ang);
	else
		ver = create_ray(2147483648, 0, 0);
	distance->dist = (hor->dist < ver->dist) ? hor->dist : ver->dist;
	distance->mod = (hor->dist < ver->dist) ? hor->mod : ver->mod;
	distance->id = (hor->dist < ver->dist) ? hor->id : ver->id;
	distance->next = sprite_list(hor, ver);
	free_listr(hor);
	free_listr(ver);
	return (distance);
}

void	*raycasting(void *data)
{
	int			xy[3];
	int			ray;
	float		ang;
	t_ray		*distance;
	t_thread	*thread;

	thread = (t_thread *)data;
	ray = thread->start - 1;
	xy[2] = 0;
	while (++ray < thread->end)
	{
		ang = thread->env->cam.angle + (ray * 0.0625) - 30;
		ang = (ang > 359) ? ang - 360 : ang;
		ang = (ang < 0) ? ang + 360 : ang;
		distance = closest_wall(thread->env, ang);
		xy[0] = ray;
		xy[1] = 0;
		draw_column(thread->env, distance, xy);
		free_listr(distance);
	}
	return (NULL);
}
