/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   damage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jominodi <jominodi@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 11:10:19 by yalabidi          #+#    #+#             */
/*   Updated: 2020/03/04 13:54:18 by jominodi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	give_xy_value_ver(float (*xy)[2], float ang, t_env *env)
{
	(*xy)[0] = (ang > 270 || ang < 90) ?
		(int)(env->cam.y / 64) * 64 + 64 : (int)(env->cam.y / 64) * 64 - 1;
	(*xy)[1] = (ang > 270 || ang < 90) ?
		env->cam.x - (env->cam.y - (*xy)[0]) * tan(ang * RAD) :
			env->cam.x - (env->cam.y - ((*xy)[0] + 1)) * tan(ang * RAD);
}

void	give_xy_value_hor(float (*xy)[2], float ang, t_env *env)
{
	(*xy)[1] = (ang < 180) ? (int)(env->cam.x / 64) * 64 + 64 :
		(int)(env->cam.x / 64) * 64 - 1;
	(*xy)[0] = (ang < 180) ? env->cam.y - (env->cam.x - (*xy)[1]) /
		tan(ang * RAD) : env->cam.y - (env->cam.x - ((*xy)[1] + 1)) /
			tan(ang * RAD);
}

t_ray		find_hor_gun(t_env *env, double angle)
{
	float	xy[2];
	float	xaya[2];
	t_ray	hor;

	give_xy_value_hor(&xy, angle, env);
	xaya[0] = give_value(angle, 2);
	xaya[1] = (angle < 180) ? 64 : -64;
	while ((int)xy[0] / 64 >= 0 && (int)xy[0] / 64 < SIZE_MAP &&
		(int)xy[1] / 64 >= 0 && (int)xy[1] / 64 < SIZE_MAP)
	{
		if (env->map[(int)xy[1] / 64][(int)xy[0] / 64].type == 'W' ||
			((int)xy[0] / 64 < 0 && (int)xy[0] / 64 >= SIZE_MAP &&
			(int)xy[1] / 64 < 0 && (int)xy[1] / 64 >= SIZE_MAP))
			break ;
		if (env->map[(int)xy[1] / 64][(int)xy[0] / 64].type == 'G')
		{
			hor.dist = sqrt(pow(env->cam.y - (int)xy[0], 2) + pow(env->cam.x -
				(int)xy[1], 2));
			hor.mapx = (int)xy[0] / 64;
			hor.mapy = (int)xy[1] / 64;
			return (hor);
		}
		xy[1] += xaya[1];
		xy[0] += xaya[0];
	}
	hor.dist = 2147483648;
	return (hor);
}

t_ray		find_ver_gun(t_env *env, double angle)
{
	float	xy[2];
	float	xaya[2];
	t_ray	ver;

	give_xy_value_ver(&xy, angle, env);
	xaya[1] = give_value(angle, 1);
	xaya[0] = (angle > 270 || angle < 90) ? 64 : -64;
	while ((int)xy[0] / 64 >= 0 && (int)xy[0] / 64 < SIZE_MAP &&
		(int)xy[1] / 64 >= 0 && (int)xy[1] / 64 < SIZE_MAP)
	{
		if (env->map[(int)xy[1] / 64][(int)xy[0] / 64].type == 'W' ||
			((int)xy[0] / 64 < 0 && (int)xy[0] / 64 >= SIZE_MAP &&
			(int)xy[1] / 64 < 0 && (int)xy[1] / 64 >= SIZE_MAP))
			break ;
		if (env->map[(int)xy[1] / 64][(int)xy[0] / 64].type == 'G')
		{
			ver.dist = sqrt(pow(env->cam.y - (int)xy[0], 2) + pow(env->cam.x -
				(int)xy[1], 2));
			ver.mapx = (int)xy[0] / 64;
			ver.mapy = (int)xy[1] / 64;
			return (ver);
		}
		xy[1] += xaya[1];
		xy[0] += xaya[0];
	}
	ver.dist = 2147483648;
	return (ver);
}

int			calc_damage(int dist)
{
	if (dist < 65)
		return (9);
	if (dist < 130)
		return (5);
	else if (dist < 275)
		return (3);
	else if (dist < 400)
		return (2);
	else if (dist < 800)
		return (1);
	return (0);
}

void		deal_damage(t_env *env)
{
	t_ray	hor;
	t_ray	ver;

	if (env->cam.angle != 0 && env->cam.angle != 180)
		hor = find_hor_gun(env, env->cam.angle);
	else
		hor.dist = 2147483648;
	if (env->cam.angle != 90 && env->cam.angle != 270)
		ver = find_ver_gun(env, env->cam.angle);
	else
		ver.dist = 2147483648;
	if (ver.dist == 2147483648 && hor.dist == 2147483648)
		return ;
	else if (ver.dist <= hor.dist && env->map[ver.mapy][ver.mapx].type == 'G')
	{
		env->map[ver.mapx][ver.mapy].id += calc_damage((int)ver.dist);
		if (env->map[ver.mapy][ver.mapx].id >= '9')
			env->map[ver.mapy][ver.mapx].type = 'F';
	}
	else if (env->map[hor.mapy][hor.mapx].type == 'G')
	{
		env->map[hor.mapy][hor.mapx].id += calc_damage((int)hor.dist);
		if (env->map[hor.mapy][hor.mapx].id >= '9')
			env->map[hor.mapy][hor.mapx].type = 'F';
	}
}
