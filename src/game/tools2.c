/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raiko <raiko@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:07:53 by jominodi          #+#    #+#             */
/*   Updated: 2020/06/23 11:43:20 by raiko            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

t_ray	*add_pane(float xy[4], t_env *env, float ang, int bol)
{
	t_ray	*pane;

	pane = create_ray(sqrt(pow(env->cam.y - (int)xy[0], 2) +
		pow(env->cam.x - (int)xy[1], 2)) * cos((ang - env->cam.angle)
		* RAD), (int)xy[1] % 64, 6);
	if (bol == 1)
		pane->mod = (int)xy[0] % 64;
	pane->type = 1;
	pane->mapx = (int)xy[0] / 64;
	pane->mapy = (int)xy[1] / 64;
	return (pane);
}

void	set_xy(t_pos cam, float ang, float (*xy)[4], int bol)
{
	if (bol == 0)
	{
		(*xy)[0] = (ang > 270 || ang < 90) ?
			(int)(cam.y / 64) * 64 + 64 : (int)(cam.y / 64) * 64 - 1;
		(*xy)[1] = (ang > 270 || ang < 90) ?
			cam.x - (cam.y - (*xy)[0]) * tan(ang * RAD) :
				cam.x - (cam.y - ((*xy)[0] + 1)) * tan(ang * RAD);
		(*xy)[3] = give_value(ang, 1);
		(*xy)[2] = (ang > 270 || ang < 90) ? 64 : -64;
	}
	if (bol == 1)
	{
		(*xy)[1] = (ang < 180) ? (int)(cam.x / 64) * 64 + 64 :
			(int)(cam.x / 64) * 64 - 1;
		(*xy)[0] = (ang < 180) ? cam.y - (cam.x - (*xy)[1]) /
			tan(ang * RAD) : cam.y - (cam.x - ((*xy)[1] + 1)) /
				tan(ang * RAD);
		(*xy)[2] = give_value(ang, 2);
		(*xy)[3] = (ang < 180) ? 64 : -64;
	}
}

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
	(*xy)[0] = (ang < 180) ?
		env->cam.y - (env->cam.x - (*xy)[1]) / tan(ang * RAD) :
			env->cam.y - (env->cam.x - ((*xy)[1] + 1)) / tan(ang * RAD);
}

void	break_glass(t_env *env, t_ray hor, t_ray ver)
{
	if (ver.dist == 2147483648 && hor.dist == 2147483648)
		return ;
	if (ver.dist <= hor.dist)
	{
		if (env->map[ver.mapy][ver.mapx].type == 'P' && ver.dist < 500)
			env->map[ver.mapy][ver.mapx].type = 'F';
		if (env->map[ver.mapy][ver.mapx].type == 'G')
		{
			env->map[ver.mapy][ver.mapx].id += calc_damage((int)ver.dist);
			if (env->map[ver.mapy][ver.mapx].id >= '9')
				env->map[ver.mapy][ver.mapx].type = 'F';
		}
	}
	if (hor.dist <= ver.dist)
	{
		if (env->map[hor.mapy][hor.mapx].type == 'P' && hor.dist < 500)
			env->map[hor.mapy][hor.mapx].type = 'F';
		if (env->map[hor.mapy][hor.mapx].type == 'G')
		{
			env->map[hor.mapy][hor.mapx].id += calc_damage((int)hor.dist);
			if (env->map[hor.mapy][hor.mapx].id >= '9')
				env->map[hor.mapy][hor.mapx].type = 'F';
		}
	}
}
