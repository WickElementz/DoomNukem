/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videloff <videloff@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 11:00:54 by yalabidi          #+#    #+#             */
/*   Updated: 2020/02/21 12:38:02 by videloff         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void		check_status(t_env *env)
{
	if (env->player.life <= 0)
		print_hud(env, 3);
	if (env->win == 1)
		print_hud(env, 2);
}

void		ft_move_x(t_block map[50][50], t_position *cam, int way)
{
	double	rad;
	double	new[2];
	double	tmp;

	if (way == 1)
	{
		tmp = (cam->angle > 270) ? cam->angle + 90 - 360 : cam->angle + 90;
		rad = tmp * M_PI / 180;
	}
	if (way == -1)
	{
		tmp = (cam->angle < 90) ? cam->angle - 90 + 360 : cam->angle - 90;
		rad = tmp * M_PI / 180;
	}
	new[0] = cam->y + (cos(rad) * cam->speed);
	new[1] = cam->x + (sin(rad) * cam->speed);
	walkable_block_x(new, map, cam);
}

void		ft_move_z(t_block map[50][50], t_position *cam, int way)
{
	double	new[2];
	double	rad;
	double	tmp;

	if (way == 1)
		rad = (cam->angle) * M_PI / 180;
	if (way == -1)
	{
		tmp = (cam->angle > 180) ? cam->angle - 180 : cam->angle + 180;
		rad = tmp * M_PI / 180;
	}
	new[0] = cam->y + cos(rad) * cam->speed;
	new[1] = cam->x + sin(rad) * cam->speed;
	walkable_block_z(new, map, cam);
}

void		anglemove(t_position *cam, int way)
{
	if (cam->angle == 360 - SENSI && way == SENSI)
		cam->angle = 0;
	else if (cam->angle == 0 && way == -SENSI)
		cam->angle = 360 - SENSI;
	else
		cam->angle += way;
}
