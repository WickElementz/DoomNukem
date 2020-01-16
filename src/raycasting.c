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

void	find_ver_wall(t_env *env, float ang, float (*xaya)[2], t_ray *ver)
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

void	find_hor_wall(t_env *env, float ang, float (*xaya)[2], t_ray *hor)
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

void	closest_wall(t_env *env, int ray, t_ray *distance)
{
	t_ray	*hori;
	t_ray	*verti;
	float	xaya[2];
	float	ang;
	float	cone;

	cone = (float)FOV / (float)WIN_WIDTH;
	ang = env->cam.angle + (ray * cone) - 30;
	ang = (ang > 359) ? ang - 360 : ang;
	ang = (ang < 0) ? ang + 360 : ang;
	if (!(hori = (t_ray*)malloc(sizeof(t_ray)) 
		&& verti = (t_ray)malloc(sizeof(t_ray))))
		return ;
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
	(*distance)[3] = (hori[3] < verti[3]) ? hori[3] : verti[3];
}

void	raycasting(t_env *env)
{
	t_ray	*distance;
	int		xy[3];
	int		ray;

	ray = -1;
	if (!(distance = (t_ray*)malloc(sizeof(t_ray))))
		return ;
	while (++ray < WIN_WIDTH)
	{
		distance = closest_wall(env, ray);
		xy[0] = ray;
		xy[1] = 0;
		xy[2] = 0;
		draw_column(env, distance, &xy);
	}
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
}
