/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jominodi <jominodi@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 11:00:54 by yalabidi          #+#    #+#             */
/*   Updated: 2020/02/26 14:59:01 by jominodi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void		check_status(t_env *env)
{
	int x;
	int y;

	x = (int)env->cam.x / BLOCK;
	y = (int)env->cam.y / BLOCK;
	if (env->player.life <= 0)
		print_last_screen(env, 3);
	if (env->map[x][y].type == 'E')
	{
		env->win = 1;
		print_last_screen(env, 2);
	}
	if (env->map[x][y].type == 'L')
	{
		env->player.life += 20;
		env->player.life = env->player.life >= 100 ? 100 : env->player.life;
		env->map[x][y].type = 'F';
	}
	if (env->map[x][y].type == 'A')
	{
		env->player.stock += 6;
		env->map[x][y].type = 'F';
	}
	if (env->map[x][y].type == 'K')
	{
		env->player.key[env->player.keyid] = env->map[x][y].id;
		env->map[x][y].type = 'F';
		env->player.keyid++;
	}
	if (env->map[x][y].type == 'C')
	{
		env->sick = 1;
		gun(env, 0);
		print_hud(env, 4);
		env->coro_clock = 0;
		env->player.corona = 1;
		env->map[x][y].type = 'F';
	}
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
