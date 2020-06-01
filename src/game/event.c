/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jominodi <jominodi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 11:00:54 by yalabidi          #+#    #+#             */
/*   Updated: 2020/06/01 11:25:37 by jominodi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			exit_hook(t_env *env)
{
	free_env(env, 0);
	return (0);
}

float		change_z(t_pos *cam, int up)
{
	if (up > 500 && cam->z - 0.3 > 5)
		return (-0.300000);
	else if (up > 400 && cam->z - 0.2 > 5)
		return (-0.2000000);
	else if (up > 300 && cam->z - 0.1 > 5)
		return (-0.10000000);
	else if (up < 100 && cam->z + 0.3 < 62)
		return (0.300000000);
	else if (up < 200 && cam->z + 0.2 < 62)
		return (0.20000000);
	else if (up < 300 && cam->z + 0.1 < 62)
		return (0.10000000);
	return (0.0);
}

void		ft_move_x(t_block map[50][50], t_pos *cam, int way, int up[2])
{
	double	rad;
	double	new[2];
	double	tmp;

	if (way == 1)
	{
		tmp = (cam->angle > 270) ? cam->angle + 90 - 360 : cam->angle + 90;
		rad = tmp * RAD;
	}
	if (way == -1)
	{
		tmp = (cam->angle < 90) ? cam->angle - 90 + 360 : cam->angle - 90;
		rad = tmp * RAD;
	}
	if (up[0] != 300 && (cam->z < 62 || cam->z > 5) && up[1] != 0)
		cam->z += change_z(cam, up[0]);
	new[0] = cam->y + (cos(rad) * cam->speed);
	new[1] = cam->x + (sin(rad) * cam->speed);
	walkable_block_x(new, map, cam);
}

void		ft_move_z(t_block map[50][50], t_pos *cam, int way, int up[2])
{
	double	new[2];
	double	rad;
	double	tmp;

	if (way == 1)
		rad = (cam->angle) * RAD;
	if (way == -1)
	{
		tmp = (cam->angle > 180) ? cam->angle - 180 : cam->angle + 180;
		rad = tmp * RAD;
	}
	if (up[0] != 300 && (cam->z < 62 || cam->z > 5) && up[1] != 0)
		cam->z += change_z(cam, up[0]);
	new[0] = cam->y + cos(rad) * cam->speed;
	new[1] = cam->x + sin(rad) * cam->speed;
	walkable_block_z(new, map, cam);
}

void		anglemove(t_pos *cam, int way)
{
	if (cam->angle == 360 - SENSI && way == SENSI)
		cam->angle = 0;
	else if (cam->angle == 0 && way == -SENSI)
		cam->angle = 360 - SENSI;
	else
		cam->angle += way;
}
