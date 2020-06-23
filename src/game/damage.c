/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   damage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanne <kanne@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 11:10:19 by yalabidi          #+#    #+#             */
/*   Updated: 2020/06/23 11:36:31 by kanne            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

t_ray		if_gunner(t_env *env, float xy[2])
{
	t_ray	ret;

	ret.dist = sqrt(pow(env->cam.y - (int)xy[0], 2) + pow(env->cam.x -
						(int)xy[1], 2));
	ret.mapx = (int)xy[0] / 64;
	ret.mapy = (int)xy[1] / 64;
	ret.type = env->map[(int)xy[1] / 64][(int)xy[0] / 64].type;
	return (ret);
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
		if (env->map[(int)xy[1] / 64][(int)xy[0] / 64].type == 'G' ||
		env->map[(int)xy[1] / 64][(int)xy[0] / 64].type == 'P')
			return (if_gunner(env, xy));
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
		if (env->map[(int)xy[1] / 64][(int)xy[0] / 64].type == 'G' ||
		env->map[(int)xy[1] / 64][(int)xy[0] / 64].type == 'P')
			return (if_gunner(env, xy));
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
	break_glass(env, hor, ver);
}
