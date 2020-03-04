/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hori_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jominodi <jominodi@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:12:20 by jominodi          #+#    #+#             */
/*   Updated: 2020/03/04 13:58:11 by jominodi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	check_hor_3(t_env *env, float xy[2], t_ray *spr, float ang)
{
	if (env->map[(int)xy[1] / 64][(int)xy[0] / 64].type == 'P')
	{
		spr->next = create_ray(sqrt(pow(env->cam.y - (int)xy[0], 2) +
			pow(env->cam.x - (int)xy[1], 2)) * cos((ang - env->cam.angle) *
			RAD), (int)xy[0] % 64, 6);
		spr = spr->next;
		spr->type = 1;
		spr->mapx = (int)xy[0] / 64;
		spr->mapy = (int)xy[1] / 64;
	}
}

void	check_hor_2(t_env *env, float xy[2], t_ray *spr, float ang)
{
	static float poscer[3];

	if (env->map[(int)xy[1] / 64][(int)xy[0] / 64].type == 'L')
	{
		spr->next = create_ray(sqrt(pow(env->cam.x - ((int)(xy[1] / 64) * 64
	+ 32), 2) + pow(env->cam.y - ((int)(xy[0] / 64) * 64 + 32), 2)), 23, 7);
		spr = spr->next;
		poscer[0] = (env->cam.y - ((int)(xy[0] / 64) * 64 + 32)) / spr->dist;
		poscer[1] = (env->cam.x - ((int)(xy[1] / 64) * 64 + 32)) / spr->dist;
		poscer[2] = right_angle(ang, atan(poscer[0] / poscer[1]) * 180 / M_PI);
		spr->mod = 32 - spr->dist * tan((ang - poscer[2]) * M_PI / 180);
		spr->mod = (spr->mod >= 64 || spr->mod < 0) ? 0 : spr->mod;
		spr->mapx = (int)xy[0] / 64;
		spr->mapy = (int)xy[1] / 64;
		spr->type = 2;
	}
	check_hor_3(env, xy, spr, ang);
}

int		check_hor_1(t_env *env, float xy[2], t_ray *spr, float ang)
{
	if (env->map[(int)xy[1] / 64][(int)xy[0] / 64].type == 'D' &&
		(int)xy[1] / 64 == (int)(xy[1] + env->ya / 2) / 64 &&
		(int)(xy[0] + env->xa / 2) / 64 == (int)xy[0] / 64)
	{
		spr->next = create_ray(sqrt(pow(env->cam.y - (int)(xy[0] +
		env->xa / 2), 2) + pow(env->cam.x - (int)(xy[1] + env->ya / 2),
		2)) * cos((ang - env->cam.angle) * RAD), (int)(xy[0] + env->xa
		/ 2) % 64, 4);
		spr = spr->next;
		spr->type = 3;
		spr->door = (int)env->map[(int)xy[1] / 64][(int)xy[0] /
							64].id - 60;
		spr->mapx = (int)xy[0] / 64;
		spr->mapy = (int)xy[1] / 64;
	}
	check_hor_2(env, xy, spr, ang);
	if (env->map[(int)xy[1] / 64][(int)xy[0] / 64].type == 'W' ||
		((int)xy[0] / 64 < 0 && (int)xy[0] / 64 >= SIZE_MAP &&
		(int)xy[1] / 64 < 0 && (int)xy[1] / 64 >= SIZE_MAP))
		return (0);
	return (1);
}
/*
void	give_xy_value_hor(float (*xy)[2], float ang, t_env *env)
{
	(*xy)[1] = (ang < 180) ? (int)(env->cam.x / 64) * 64 + 64 :
		(int)(env->cam.x / 64) * 64 - 1;
	(*xy)[0] = (ang < 180) ? env->cam.y - (env->cam.x - (*xy)[1]) /
		tan(ang * RAD) : env->cam.y - (env->cam.x - ((*xy)[1] + 1)) /
			tan(ang * RAD);
}*/

t_ray	*find_hor_wall(t_env *env, float ang)
{
	float	xy[2];
	t_ray	*spr;
	t_ray	*hor;

	hor = create_ray(0, 0, 0);
	spr = hor;
	hor->id = (ang < 180) ? 0 : 2;
	give_xy_value_hor(&xy, ang, env);
	env->xa = give_value(ang, 2);
	env->ya = (ang < 180) ? 64 : -64;
	while ((int)xy[0] / 64 >= 0 && (int)xy[0] / 64 < SIZE_MAP &&
		(int)xy[1] / 64 >= 0 && (int)xy[1] / 64 < SIZE_MAP)
	{
		if (check_hor_1(env, xy, spr, ang) == 0)
			break ;
		xy[1] += env->ya;
		xy[0] += env->xa;
	}
	hor->dist = sqrt(pow(env->cam.y - (int)xy[0], 2) + pow(env->cam.x -
		(int)xy[1], 2)) * cos((ang - env->cam.angle) * RAD);
	hor->mod = (int)xy[0] % 64;
	return (hor);
}
