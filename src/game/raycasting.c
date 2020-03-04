/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanne <kanne@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 13:51:12 by videloff          #+#    #+#             */
/*   Updated: 2020/03/04 10:29:46 by kanne            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

float	give_value(float ang, int dif)
{
	float	ya;

	ya = 0.0;
	if (dif == 1)
		ya = (ang > 270 || ang < 90) ? 64 * tan(ang * RAD) :
			-64 * tan(ang * RAD);
	else if (dif == 2)
		ya = (ang > 270 || ang < 90) ? 64 / fabs(tan(ang * RAD)) : -64 /
			fabs(tan(ang * RAD));
	return (ya);
}

float	right_angle(float ang, float fang)
{
	float	res;

	if (fang < 0)
		res = (ang > 45 && ang < 225) ? fabs(fang) + 90 : fabs(fang) + 270;
	else
		res = (ang > 135 && ang < 315) ? 270 - fang : 90 - fang;
	if (res == 360)
		res = 0;
	return (res);
}

t_ray	*find_ver_wall(t_env *env, float ang)
{
	float	xy[2];
	float	xaya[2];
	float	poscer[3];
	t_ray	*sprite;
	t_ray	*ver;

	ver = create_ray(0, 0, 0);
	sprite = ver;
	ver->id = (ang < 90 || ang > 270) ? 1 : 3;
	xy[0] = (ang > 270 || ang < 90) ?
		(int)(env->cam.y / 64) * 64 + 64 : (int)(env->cam.y / 64) * 64 - 1;
	xy[1] = (ang > 270 || ang < 90) ?
		env->cam.x - (env->cam.y - xy[0]) * tan(ang * RAD) :
			env->cam.x - (env->cam.y - (xy[0] + 1)) * tan(ang * RAD);
	xaya[1] = give_value(ang, 1);
	xaya[0] = (ang > 270 || ang < 90) ? 64 : -64;
	while ((int)xy[0] / 64 >= 0 && (int)xy[0] / 64 < SIZE_MAP &&
		(int)xy[1] / 64 >= 0 && (int)xy[1] / 64 < SIZE_MAP)
	{
		if (env->map[(int)xy[1] / 64][(int)xy[0] / 64].type == 'D' &&
			(int)xy[1] / 64 == (int)(xy[1] + xaya[1] / 2) / 64 &&
			(int)(xy[0] + xaya[0] / 2) / 64 == (int)xy[0] / 64)
		{
			sprite->next = create_ray(sqrt(pow(env->cam.y -
				(int)(xy[0] + xaya[0] / 2), 2) + pow(env->cam.x -
				(int)(xy[1] + xaya[1] / 2), 2)) * cos((ang - env->cam.angle)
				* RAD), (int)(xy[1] + xaya[1] / 2) % 64, 4);
			sprite = sprite->next;
			sprite->door = (int)env->map[(int)xy[1] / 64][(int)xy[0] /
								64].id - 60;
			sprite->type = 3;
			sprite->mapx = (int)xy[0] / 64;
			sprite->mapy = (int)xy[1] / 64;
		}
		if (env->map[(int)xy[1] / 64][(int)xy[0] / 64].type == 'L')
		{
			sprite->next = create_ray(sqrt(pow(env->cam.x - ((int)(xy[1] / 64) * 64 + 32) , 2) + pow(env->cam.y - ((int)(xy[0] / 64) * 64 + 32) , 2)), 23, 7);
			sprite = sprite->next;
			sprite->mod = 0;
			poscer[0] = (env->cam.y - ((int)(xy[0] / 64) * 64 + 32)) / sprite->dist;
			poscer[1] = (env->cam.x - ((int)(xy[1] / 64) * 64 + 32)) / sprite->dist;
			poscer[2] = right_angle(ang, atan(poscer[0] / poscer[1]) * 180 / M_PI);
			sprite->mod = 32 - sprite->dist * tan((ang - poscer[2]) * M_PI / 180);
			sprite->mod = (sprite->mod >= 64 || sprite->mod < 0) ? 0 : sprite->mod; 
			sprite->mapx = (int)xy[0] / 64;
			sprite->mapy = (int)xy[1] / 64;
			sprite->type = 2;
		}
		if (env->map[(int)xy[1] / 64][(int)xy[0] / 64].type == 'P')
		{
			sprite->next = create_ray(sqrt(pow(env->cam.y - (int)xy[0], 2) +
							pow(env->cam.x -
				(int)xy[1], 2)) * cos((ang - env->cam.angle) * RAD),
					(int)xy[1] % 64, 6);
			sprite = sprite->next;
			sprite->type = 1;
			sprite->mapx = (int)xy[0] / 64;
			sprite->mapy = (int)xy[1] / 64;
		}
		if (env->map[(int)xy[1] / 64][(int)xy[0] / 64].type == 'W' ||
			((int)xy[0] / 64 < 0 && (int)xy[0] / 64 >= SIZE_MAP &&
			(int)xy[1] / 64 < 0 && (int)xy[1] / 64 >= SIZE_MAP))
			break ;
		xy[1] += xaya[1];
		xy[0] += xaya[0];
	}
	ver->dist = sqrt(pow(env->cam.y - (int)xy[0], 2) + pow(env->cam.x -
		(int)xy[1], 2)) * cos((ang - env->cam.angle) * RAD);
	ver->mod = (int)xy[1] % 64;
	return (ver);
}

t_ray	*find_hor_wall(t_env *env, float ang)
{
	float	xy[2];
	float	xaya[2];
	float	poscer[3];
	t_ray	*sprite;
	t_ray	*hor;

	hor = create_ray(0, 0, 0);
	sprite = hor;
	hor->id = (ang < 180) ? 0 : 2;
	xy[1] = (ang < 180) ? (int)(env->cam.x / 64) * 64 + 64 :
		(int)(env->cam.x / 64) * 64 - 1;
	xy[0] = (ang < 180) ? env->cam.y - (env->cam.x - xy[1]) /
		tan(ang * RAD) : env->cam.y - (env->cam.x - (xy[1] + 1)) /
			tan(ang * RAD);
	xaya[0] = give_value(ang, 2);
	xaya[1] = (ang < 180) ? 64 : -64;
	while ((int)xy[0] / 64 >= 0 && (int)xy[0] / 64 < SIZE_MAP &&
		(int)xy[1] / 64 >= 0 && (int)xy[1] / 64 < SIZE_MAP)
	{
		if (env->map[(int)xy[1] / 64][(int)xy[0] / 64].type == 'D' &&
			(int)xy[1] / 64 == (int)(xy[1] + xaya[1] / 2) / 64 &&
			(int)(xy[0] + xaya[0] / 2) / 64 == (int)xy[0] / 64)
		{
			sprite->next = create_ray(sqrt(pow(env->cam.y - (int)(xy[0] +
			xaya[0] / 2), 2) + pow(env->cam.x - (int)(xy[1] + xaya[1] / 2),
			2)) * cos((ang - env->cam.angle) * RAD), (int)(xy[0] + xaya[0]
			/ 2) % 64, 4);
			sprite = sprite->next;
			sprite->type = 3;
			sprite->door = (int)env->map[(int)xy[1] / 64][(int)xy[0] /
								64].id - 60;
			sprite->mapx = (int)xy[0] / 64;
			sprite->mapy = (int)xy[1] / 64;
		}
		if (env->map[(int)xy[1] / 64][(int)xy[0] / 64].type == 'L')
		{
			sprite->next = create_ray(sqrt(pow(env->cam.x - ((int)(xy[1] / 64) * 64 + 32) , 2) +
				pow(env->cam.y - ((int)(xy[0] / 64) * 64 + 32) , 2)), 23, 7);
			sprite = sprite->next;
			poscer[0] = (env->cam.y - ((int)(xy[0] / 64) * 64 + 32)) / sprite->dist;
			poscer[1] = (env->cam.x - ((int)(xy[1] / 64) * 64 + 32)) / sprite->dist;
			poscer[2] = right_angle(ang, atan(poscer[0] / poscer[1]) * 180 / M_PI);
			sprite->mod = 32 - sprite->dist * tan((ang - poscer[2]) * M_PI / 180);
			sprite->mod = (sprite->mod >= 64 || sprite->mod < 0) ? 0 : sprite->mod; 
			sprite->mapx = (int)xy[0] / 64;
			sprite->mapy = (int)xy[1] / 64;
			sprite->type = 2;
		}
		if (env->map[(int)xy[1] / 64][(int)xy[0] / 64].type == 'P')
		{
			sprite->next = create_ray(sqrt(pow(env->cam.y - (int)xy[0], 2) +
				pow(env->cam.x - (int)xy[1], 2)) * cos((ang - env->cam.angle) *
				RAD), (int)xy[0] % 64, 6);
			sprite = sprite->next;
			sprite->type = 1;
			sprite->mapx = (int)xy[0] / 64;
			sprite->mapy = (int)xy[1] / 64;
		}
		if (env->map[(int)xy[1] / 64][(int)xy[0] / 64].type == 'W' ||
			((int)xy[0] / 64 < 0 && (int)xy[0] / 64 >= SIZE_MAP &&
			(int)xy[1] / 64 < 0 && (int)xy[1] / 64 >= SIZE_MAP))
			break ;
		xy[1] += xaya[1];
		xy[0] += xaya[0];
	}
	hor->dist = sqrt(pow(env->cam.y - (int)xy[0], 2) + pow(env->cam.x -
		(int)xy[1], 2)) * cos((ang - env->cam.angle) * RAD);
	hor->mod = (int)xy[0] % 64;
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
	/*if (ang == 0)
	{
		dprintf(1, "%f ", distance->id);
		if (distance->next)
			dprintf(1, "%f ", distance->next->id);
		if (distance->next && distance->next->next)
			dprintf(1, "%f ", distance->next->next->id);
		dprintf(1, "\n");
	}*/
	free_listr(hor);
	free_listr(ver);
	return (distance);
}

void	*raycasting(void *data)
{
	t_ray		*distance;
	float		ang;
	int			xy[3];
	int			ray;
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

