/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verti_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videloff <videloff@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 12:56:29 by jominodi          #+#    #+#             */
/*   Updated: 2020/03/04 14:48:55 by videloff         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"
/*
void	check_ver_3(t_env *env, float xy[2], t_ray *spr, float ang)
{
	if (env->map[(int)xy[1] / 64][(int)xy[0] / 64].type == 'P')
	{
		spr->next = create_ray(sqrt(pow(env->cam.y - (int)xy[0], 2) +
						pow(env->cam.x -
			(int)xy[1], 2)) * cos((ang - env->cam.angle) * RAD),
				(int)xy[1] % 64, 6);
		spr = spr->next;
		spr->type = 1;
		spr->mapx = (int)xy[0] / 64;
		spr->mapy = (int)xy[1] / 64;
	}
}

void	check_ver_2(t_env *env, float xy[2], t_ray *spr, float ang)
{
	static float poscer[3];

	if (env->map[(int)xy[1] / 64][(int)xy[0] / 64].type == 'L')
	{
		spr->next = create_ray(sqrt(pow(env->cam.x - ((int)(xy[1] / 64) * 64
		+ 32), 2) + pow(env->cam.y - ((int)(xy[0] / 64) * 64 + 32), 2)), 23, 7);
		spr = spr->next;
		spr->mod = 0;
		poscer[0] = (env->cam.y - ((int)(xy[0] / 64) * 64 + 32)) / spr->dist;
		poscer[1] = (env->cam.x - ((int)(xy[1] / 64) * 64 + 32)) / spr->dist;
		poscer[2] = right_angle(ang, atan(poscer[0] / poscer[1]) * 180 / M_PI);
		spr->mod = 32 - spr->dist * tan((ang - poscer[2]) * M_PI / 180);
		spr->mod = (spr->mod >= 64 || spr->mod < 0) ? 0 : spr->mod;
		spr->mapx = (int)xy[0] / 64;
		spr->mapy = (int)xy[1] / 64;
		spr->type = 2;
	}
	check_ver_3(env, xy, spr, ang);
}

int		check_ver_1(t_env *env, float xy[2], t_ray *spr, float ang)
{
	if (env->map[(int)xy[1] / 64][(int)xy[0] / 64].type == 'D' &&
		(int)xy[1] / 64 == (int)(xy[1] + env->xa2 / 2) / 64 &&
		(int)(xy[0] + env->ya2 / 2) / 64 == (int)xy[0] / 64)
	{
		spr->next = create_ray(sqrt(pow(env->cam.y -
			(int)(xy[0] + env->ya2 / 2), 2) + pow(env->cam.x -
			(int)(xy[1] + env->xa2 / 2), 2)) * cos((ang - env->cam.angle)
			* RAD), (int)(xy[1] + env->xa2 / 2) % 64, 4);
		spr = spr->next;
		spr->door = (int)env->map[(int)xy[1] / 64][(int)xy[0] /
							64].id - 60;
		spr->type = 3;
		spr->mapx = (int)xy[0] / 64;
		spr->mapy = (int)xy[1] / 64;
	}
	check_ver_2(env, xy, spr, ang);
	if (env->map[(int)xy[1] / 64][(int)xy[0] / 64].type == 'W' ||
		((int)xy[0] / 64 < 0 && (int)xy[0] / 64 >= SIZE_MAP &&
		(int)xy[1] / 64 < 0 && (int)xy[1] / 64 >= SIZE_MAP))
		return (0);
	return (1);
}
/*
void	give_xy_value_ver(float (*xy)[2], float ang, t_env *env)
{
	(*xy)[0] = (ang > 270 || ang < 90) ?
		(int)(env->cam.y / 64) * 64 + 64 : (int)(env->cam.y / 64) * 64 - 1;
	(*xy)[1] = (ang > 270 || ang < 90) ?
		env->cam.x - (env->cam.y - (*xy)[0]) * tan(ang * RAD) :
			env->cam.x - (env->cam.y - ((*xy)[0] + 1)) * tan(ang * RAD);
}*/

t_ray	*find_ver_wall(t_env *env, float ang)
{
	float	xy[2];
	t_ray	*spr;
	t_ray	*ver;

	ver = create_ray(0, 0, 0);
	spr = ver;
	ver->id = (ang < 90 || ang > 270) ? 1 : 3;
	give_xy_value_ver(&xy, ang, env);
	env->xa2 = give_value(ang, 1);
	env->ya2 = (ang > 270 || ang < 90) ? 64 : -64;
	while ((int)xy[0] / 64 >= 0 && (int)xy[0] / 64 < SIZE_MAP &&
		(int)xy[1] / 64 >= 0 && (int)xy[1] / 64 < SIZE_MAP)
	{
		if (check_ver_1(env, xy, spr, ang) == 0)
			break ;
		xy[1] += env->xa2;
		xy[0] += env->ya2;
	}
	ver->dist = sqrt(pow(env->cam.y - (int)xy[0], 2) + pow(env->cam.x -
		(int)xy[1], 2)) * cos((ang - env->cam.angle) * RAD);
	ver->mod = (int)xy[1] % 64;
	return (ver);
}
*/