/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   event.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/28 11:00:54 by yalabidi     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/30 13:23:07 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "doom_nukem.h"

void		check_status(t_env *env)
{
	if (env->p_health <= 0)
		print_hud(env, 3);
	if (env->win == 1)
		print_hud(env, 2);
}

void		ft_move_x(t_block **map, t_position *cam, int way, int max[2])
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
	if (new[0] + 2 <= max[0] * 100 && new[0] - 2 >= 0)
		if (map[(int)(new[1] - 2) / BLOCK][(int)(cam->y) / BLOCK].type == 'F' &&
			map[(int)(new[1] + 2) / BLOCK][(int)(cam->y) / BLOCK].type == 'F')
			cam->x = new[1];
	if (new[1] + 2 <= max[1] * 100 && new[1] - 2 >= 0)
		if (map[(int)(cam->x) / BLOCK][(int)(new[0] - 2) / BLOCK].type == 'F' &&
			map[(int)(cam->x) / BLOCK][(int)(new[0] + 2) / BLOCK].type == 'F')
			cam->y = new[0];
}

void		ft_move_z(t_block **map, t_position *cam, int way, int max[2])
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
	if (new[0] + 2 <= max[0] * 100 && new[0] - 2 >= 0)
		if (map[(int)(new[1] + 2) / BLOCK][(int)(cam->y) / BLOCK].type == 'F' &&
			map[(int)(new[1] - 2) / BLOCK][(int)(cam->y) / BLOCK].type == 'F')
			cam->x = new[1];
	if (new[1] + 2 <= max[1] * 100 && new[1] - 2 >= 0)
		if (map[(int)(cam->x) / BLOCK][(int)(new[0] + 2) / BLOCK].type == 'F' &&
			map[(int)(cam->x) / BLOCK][(int)(new[0] - 2) / BLOCK].type == 'F')
			cam->y = new[0];
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
