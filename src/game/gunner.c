/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gunner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanne <kanne@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 09:30:59 by kanne             #+#    #+#             */
/*   Updated: 2020/03/04 10:36:18 by kanne            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

int		check_gunner_ver(t_env *env)
{
	float	xy[2];
	float	xaya[2];
	int 	ang[2];

	ang[0] = 0;
	ang[1] = env->cam.angle;
	while (ang[0]++ < 360)
	{
		xy[0] = (ang[1] > 270 || ang[1] < 90) ?
			(int)(env->cam.y / 64) * 64 + 64 : (int)(env->cam.y / 64) * 64 - 1;
		xy[1] = (ang[1] > 270 || ang[1] < 90) ?
			env->cam.x - (env->cam.y - xy[0]) * tan(ang[1] * RAD) :
				env->cam.x - (env->cam.y - (xy[0] + 1)) * tan(ang[1] * RAD);
		xaya[1] = give_value(ang[1], 1);
		xaya[0] = (ang[1] > 270 || ang[1] < 90) ? 64 : -64;
		ang[1] += 1;
		if (ang[1] > 359)
			ang[1] = 0;
		while ((int)xy[0] / 64 >= 0 && (int)xy[0] / 64 < SIZE_MAP &&
			(int)xy[1] / 64 >= 0 && (int)xy[1] / 64 < SIZE_MAP)
		{
			if (env->map[(int)xy[1] / 64][(int)xy[0] / 64].type == 'W' ||
				env->map[(int)xy[1] / 64][(int)xy[0] / 64].type == 'P' ||
				env->map[(int)xy[1] / 64][(int)xy[0] / 64].type == 'D' ||
				((int)xy[0] / 64 < 0 && (int)xy[0] / 64 >= SIZE_MAP &&
				(int)xy[1] / 64 < 0 && (int)xy[1] / 64 >= SIZE_MAP))
					break;
			else if (env->map[(int)xy[1] / 64][(int)xy[0] / 64].type == 'G' &&
			sqrt(pow(env->cam.y - (int)xy[0], 2) + pow(env->cam.x - (int)xy[1], 2)) < 450)
					return (1);
			xy[1] += xaya[1];
			xy[0] += xaya[0];
		}
	}
	return (0);
}

int		check_gunner_hor(t_env *env)
{
	float	xy[2];
	float	xaya[2];
	int		ang[2];

	ang[0] = 0;
	ang[1] = env->cam.angle;
	while (ang[0]++ < 360)
	{
		xy[1] = (ang[1] < 180) ? (int)(env->cam.x / 64) * 64 + 64 :
			(int)(env->cam.x / 64) * 64 - 1;
		xy[0] = (ang[1] < 180) ? env->cam.y - (env->cam.x - xy[1]) /
			tan(ang[1] * RAD) : env->cam.y - (env->cam.x - (xy[1] + 1)) /
				tan(ang[1] * RAD);
		xaya[0] = give_value(ang[1], 2);
		xaya[1] = (ang[1] < 180) ? 64 : -64;
		ang[1] += 1;
		if (ang[1] > 359)
			ang[1] = 0;
		while ((int)xy[0] / 64 >= 0 && (int)xy[0] / 64 < SIZE_MAP &&
			(int)xy[1] / 64 >= 0 && (int)xy[1] / 64 < SIZE_MAP)
		{
			if (env->map[(int)xy[1] / 64][(int)xy[0] / 64].type == 'W' ||
				env->map[(int)xy[1] / 64][(int)xy[0] / 64].type == 'P' ||
				env->map[(int)xy[1] / 64][(int)xy[0] / 64].type == 'D' ||
				((int)xy[0] / 64 < 0 && (int)xy[0] / 64 >= SIZE_MAP &&
				(int)xy[1] / 64 < 0 && (int)xy[1] / 64 >= SIZE_MAP))
					break;
			else if (env->map[(int)xy[1] / 64][(int)xy[0] / 64].type == 'G' &&
			sqrt(pow(env->cam.y - (int)xy[0], 2) + pow(env->cam.x - (int)xy[1], 2)) < 450)
					return (1);
            xy[1] += xaya[1];
			xy[0] += xaya[0];
		}
	}
	return (0);
}

void	gunner_fire(t_env *env)
{
	clock_t	time;

	time = clock();
	if (env->gunner_id == 0 && (env->gunner_id = 1))
		env->t3 = time;
	if (env->t3 + 4000000 < time)
	{
		env->player.life -= 10;
		env->gunner_id = 0;
	}
}