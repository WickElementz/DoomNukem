/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jominodi <jominodi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:03:54 by jominodi          #+#    #+#             */
/*   Updated: 2020/06/01 11:02:51 by jominodi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

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

int		check_type(float xy[2], t_block map[50][50], char c)
{
	char t;

	t = map[(int)xy[1] / 64][(int)xy[0] / 64].type;
	if (c == 'D' && t == 'D' &&
		(int)xy[1] / 64 == (int)(xy[1] + xy[3] / 2) / 64 &&
		(int)(xy[0] + xy[2] / 2) / 64 == (int)xy[0] / 64)
		return (1);
	else if ((c == 'W' && t == 'W') ||
		((int)xy[0] / 64 < 0 && (int)xy[0] / 64 >= SIZE_MAP &&
		(int)xy[1] / 64 < 0 && (int)xy[1] / 64 >= SIZE_MAP))
		return (1);
	else if (c == 'Y' && (t == 'L' || t == 'A' || t == 'C' ||
		t == 'K' || t == 'Z' || t == 'G'))
		return (1);
	else if (c == 'P' && t == 'P')
		return (1);
	return (0);
}

void	set_wall_h(float ang, t_pos cam, float xy[4], t_ray *hor)
{
	hor->id = (ang < 180) ? 0 : 2;
	hor->dist = sqrt(pow(cam.y - (int)xy[0], 2) + pow(cam.x -
		(int)xy[1], 2)) * cos((ang - cam.angle) * RAD);
	hor->mod = (int)xy[0] % 64;
}

void	set_wall_v(float ang, t_pos cam, float xy[4], t_ray *ver)
{
	ver->id = (ang < 90 || ang > 270) ? 1 : 3;
	ver->dist = sqrt(pow(cam.y - (int)xy[0], 2) + pow(cam.x -
		(int)xy[1], 2)) * cos((ang - cam.angle) * RAD);
	ver->mod = (int)xy[1] % 64;
}
