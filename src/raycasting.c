/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   raycasting.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: videloff <videloff@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/28 13:51:12 by videloff     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/10 14:24:15 by videloff    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "doom_nukem.h"

float	give_value(float ang, int dif)
{
	float	ya;

	ya = 0.0;
	if (dif == 1)
		ya = (ang > 270 || ang < 90) ? 64 * tan(ang * M_PI / 180) :
			-64 * tan(ang * M_PI / 180);
	else if (dif == 2)
		ya = (ang > 270 || ang < 90) ? 64 / fabs(tan(ang * M_PI / 180)) : -64 /
			fabs(tan(ang * M_PI / 180));
	return (ya);
}

void	find_ver_wall(t_env *env, float ang, float (*xaya)[2], float (*ver)[3])
{
	float	xy[2];

	(*ver)[2] = (ang < 90 || ang > 270) ? 1 : 3;
	xy[0] = (ang > 270 || ang < 90) ?
		(int)(env->cam.y / 64) * 64 + 64 : (int)(env->cam.y / 64) * 64 - 1;
	xy[1] = (ang > 270 || ang < 90) ?
		env->cam.x - (env->cam.y - xy[0]) * tan(ang * M_PI / 180) :
			env->cam.x - (env->cam.y - (xy[0] + 1)) * tan(ang * M_PI / 180);
	(*xaya)[1] = give_value(ang, 1);
	(*xaya)[0] = (ang > 270 || ang < 90) ? 64 : -64;
	while ((int)xy[0] / 64 >= 0 && (int)xy[0] / 64 < env->map_y_max &&
		(int)xy[1] / 64 >= 0 && (int)xy[1] / 64 < env->map_x_max)
	{
		if (env->map[(int)xy[1] / 64][(int)xy[0] / 64].type != 'F' ||
			((int)xy[0] / 64 < 0 && (int)xy[0] / 64 >= env->map_y_max &&
				(int)xy[1] / 64 < 0 && (int)xy[1] / 64 >= env->map_x_max))
			break ;
		xy[1] += (*xaya)[1];
		xy[0] += (*xaya)[0];
	}
	(*ver)[0] = sqrt(pow(env->cam.y - (int)xy[0], 2) + pow(env->cam.x -
		(int)xy[1], 2)) * cos((ang - env->cam.angle) * M_PI / 180);
	(*ver)[1] = (int)xy[1] % 64;
}

void	find_hor_wall(t_env *env, float ang, float (*xaya)[2], float (*hor)[3])
{
	float	xy[2];

	(*hor)[2] = (ang < 180) ? 0 : 2;
	xy[1] = (ang < 180) ? (int)(env->cam.x / 64) * 64 + 64 :
		(int)(env->cam.x / 64) * 64 - 1;
	xy[0] = (ang < 180) ? env->cam.y - (env->cam.x - xy[1]) /
		tan(ang * M_PI / 180) : env->cam.y - (env->cam.x - (xy[1] + 1)) /
			tan(ang * M_PI / 180);
	(*xaya)[0] = give_value(ang, 2);
	(*xaya)[1] = (ang < 180) ? 64 : -64;
	while ((int)xy[0] / 64 >= 0 && (int)xy[0] / 64 < env->map_y_max &&
		(int)xy[1] / 64 >= 0 && (int)xy[1] / 64 < env->map_x_max)
	{
		if (env->map[(int)xy[1] / 64][(int)xy[0] / 64].type != 'F' ||
			((int)xy[0] / 64 < 0 && (int)xy[0] / 64 >= env->map_y_max &&
				(int)xy[1] / 64 < 0 && (int)xy[1] / 64 >= env->map_x_max))
			break ;
		xy[1] += (*xaya)[1];
		xy[0] += (*xaya)[0];
	}
	(*hor)[0] = sqrt(pow(env->cam.y - (int)xy[0], 2) + pow(env->cam.x -
		(int)xy[1], 2)) * cos((ang - env->cam.angle) * M_PI / 180);
	(*hor)[1] = (int)xy[0] % 64;
}

/*
** dist[0] = distance du mur
** dist[1] = colonne qu'on touche
** dist[2] = Orientation du mur
*/

void	closest_wall(t_env *env, int ray, float (*distance)[3])
{
	float	hori[3];
	float	verti[3];
	float	xaya[2];
	float	ang;
	float	cone;

	cone = (float)FOV / (float)WIN_WIDTH;
	ang = env->cam.angle + (ray * cone) - 30;
	ang = (ang > 359) ? ang - 360 : ang;
	ang = (ang < 0) ? ang + 360 : ang;
	if (ang != 0 && ang != 180)
		find_hor_wall(env, ang, &xaya, &hori);
	else
		hori[0] = 2147483648;
	if (ang != 90 && ang != 270)
		find_ver_wall(env, ang, &xaya, &verti);
	else
		verti[0] = 2147483648;
	(*distance)[0] = (hori[0] < verti[0]) ? hori[0] : verti[0];
	(*distance)[1] = (hori[0] < verti[0]) ? hori[1] : verti[1];
	(*distance)[2] = (hori[0] < verti[0]) ? hori[2] : verti[2];
}

void	raycasting(t_env *env)
{
	float	distance[WIN_WIDTH][3];
	int		ray;
	int		xy[2];

	ray = -1;
	xy[0] = -1;
	xy[1] = 0;
	while (++ray < WIN_WIDTH)
		closest_wall(env, ray, &distance[ray]);
	draw_column(env, distance, xy);
}
