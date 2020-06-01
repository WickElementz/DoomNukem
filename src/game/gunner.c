/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gunner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jominodi <jominodi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 09:30:59 by kanne             #+#    #+#             */
/*   Updated: 2020/06/01 11:02:51 by jominodi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	check_dist(t_env *env, float xy[2], float xaya[2])
{
	while ((int)xy[0] / 64 >= 0 && (int)xy[0] / 64 < SIZE_MAP &&
		(int)xy[1] / 64 >= 0 && (int)xy[1] / 64 < SIZE_MAP)
	{
		if (env->map[(int)xy[1] / 64][(int)xy[0] / 64].type == 'W' ||
			env->map[(int)xy[1] / 64][(int)xy[0] / 64].type == 'P' ||
			env->map[(int)xy[1] / 64][(int)xy[0] / 64].type == 'D' ||
			((int)xy[0] / 64 < 0 && (int)xy[0] / 64 >= SIZE_MAP &&
			(int)xy[1] / 64 < 0 && (int)xy[1] / 64 >= SIZE_MAP))
			break ;
		else if (env->map[(int)xy[1] / 64][(int)xy[0] / 64].type == 'G' &&
			sqrt(pow(env->cam.y - (int)xy[0], 2) +
			pow(env->cam.x - (int)xy[1], 2)) < 450)
		{
			return (sqrt(pow(env->cam.y - (int)xy[0], 2) +
			pow(env->cam.x - (int)xy[1], 2)));
		}
		xy[1] += xaya[1];
		xy[0] += xaya[0];
	}
	return (sqrt(pow(env->cam.y - (int)xy[0], 2) + pow(env->cam.x -
	(int)xy[1], 2)) * -1);
}

static int	check_gunner_ver(t_env *env, int ang)
{
	float	xy[2];
	float	xaya[2];

	xy[0] = (ang > 270 || ang < 90) ?
		(int)(env->cam.y / 64) * 64 + 64 : (int)(env->cam.y / 64) * 64 - 1;
	xy[1] = (ang > 270 || ang < 90) ?
		env->cam.x - (env->cam.y - xy[0]) * tan(ang * RAD) :
			env->cam.x - (env->cam.y - (xy[0] + 1)) * tan(ang * RAD);
	xaya[1] = give_value(ang, 1);
	xaya[0] = (ang > 270 || ang < 90) ? 64 : -64;
	return (check_dist(env, xy, xaya));
}

static int	check_gunner_hor(t_env *env, int ang)
{
	float	xy[2];
	float	xaya[2];

	xy[1] = (ang < 180) ? (int)(env->cam.x / 64) * 64 + 64 :
		(int)(env->cam.x / 64) * 64 - 1;
	xy[0] = (ang < 180) ? env->cam.y - (env->cam.x - xy[1]) /
		tan(ang * RAD) : env->cam.y - (env->cam.x - (xy[1] + 1)) /
			tan(ang * RAD);
	xaya[0] = give_value(ang, 2);
	xaya[1] = (ang < 180) ? 64 : -64;
	return (check_dist(env, xy, xaya));
}

void		check_gunner(t_env *env)
{
	int ang;

	ang = 0;
	while (ang++ < 360)
	{
		if (((check_gunner_hor(env, ang) > 0) ||
		(check_gunner_ver(env, ang) > 0)) &&
		((check_gunner_hor(env, ang) < 0 &&
		check_gunner_ver(env, ang) < abs(check_gunner_hor(env, ang))) ||
		(check_gunner_ver(env, ang) < 0 &&
		check_gunner_hor(env, ang) < abs(check_gunner_ver(env, ang)))))
			gunner_fire(env);
	}
}

void		gunner_fire(t_env *env)
{
	clock_t	time;

	time = clock();
	if (env->gunner_id == 0 && (env->gunner_id = 1))
		env->t3 = time;
	if (env->t3 + 6000000 < time)
	{
		env->player.life -= 10;
		env->gunner_id = 0;
	}
}
