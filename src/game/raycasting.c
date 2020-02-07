/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   raycasting.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/28 13:51:12 by videloff     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/04 12:45:56 by jominodi    ###    #+. /#+    ###.fr     */
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

t_ray	*find_ver_wall(t_env *env, float ang)
{
	float	xy[2];
	float	xaya[2];
	t_ray	*sprite;
	t_ray	*ver;

	ver = create_ray(0, 0, 0);
	sprite = ver;
	ver->id = (ang < 90 || ang > 270) ? 1 : 3;
	xy[0] = (ang > 270 || ang < 90) ?
		(int)(env->cam.y / 64) * 64 + 64 : (int)(env->cam.y / 64) * 64 - 1;
	xy[1] = (ang > 270 || ang < 90) ?
		env->cam.x - (env->cam.y - xy[0]) * tan(ang * M_PI / 180) :
			env->cam.x - (env->cam.y - (xy[0] + 1)) * tan(ang * M_PI / 180);
	xaya[1] = give_value(ang, 1);
	xaya[0] = (ang > 270 || ang < 90) ? 64 : -64;
	while ((int)xy[0] / 64 >= 0 && (int)xy[0] / 64 < env->map_y_max &&
		(int)xy[1] / 64 >= 0 && (int)xy[1] / 64 < env->map_x_max)
	{
		if (env->map[(int)xy[1] / 64][(int)xy[0] / 64].type == 'G')
		{
			sprite->next = create_ray(sqrt(pow(env->cam.y - (int)xy[0], 2) + pow(env->cam.x -
				(int)xy[1], 2)) * cos((ang - env->cam.angle) * M_PI / 180), (int)xy[1] % 64, 6);
			sprite->type = 1;
			sprite = sprite->next;
		}
		if (env->map[(int)xy[1] / 64][(int)xy[0] / 64].type == 'W' ||
			((int)xy[0] / 64 < 0 && (int)xy[0] / 64 >= env->map_y_max &&
			(int)xy[1] / 64 < 0 && (int)xy[1] / 64 >= env->map_x_max))
				break ;
		xy[1] += xaya[1];
		xy[0] += xaya[0];
	}
	ver->dist = sqrt(pow(env->cam.y - (int)xy[0], 2) + pow(env->cam.x -
		(int)xy[1], 2)) * cos((ang - env->cam.angle) * M_PI / 180);
	ver->mod = (int)xy[1] % 64;
	return (ver);
}

t_ray	*find_hor_wall(t_env *env, float ang)
{
	float	xy[2];
	float	xaya[2];
	t_ray	*sprite;
	t_ray	*hor;

	hor = create_ray(0, 0, 0);
	sprite = hor;
	hor->id = (ang < 180) ? 0 : 2;
	xy[1] = (ang < 180) ? (int)(env->cam.x / 64) * 64 + 64 :
		(int)(env->cam.x / 64) * 64 - 1;
	xy[0] = (ang < 180) ? env->cam.y - (env->cam.x - xy[1]) /
		tan(ang * M_PI / 180) : env->cam.y - (env->cam.x - (xy[1] + 1)) /
			tan(ang * M_PI / 180);
	xaya[0] = give_value(ang, 2);
	xaya[1] = (ang < 180) ? 64 : -64;
	while ((int)xy[0] / 64 >= 0 && (int)xy[0] / 64 < env->map_y_max &&
		(int)xy[1] / 64 >= 0 && (int)xy[1] / 64 < env->map_x_max)
	{
		if (env->map[(int)xy[1] / 64][(int)xy[0] / 64].type == 'G' ||
			env->map[(int)xy[1] / 64][(int)xy[0] / 64].type == 'S')
		{
			sprite->next = create_ray(sqrt(pow(env->cam.y - (int)xy[0], 2) +
				pow(env->cam.x - (int)xy[1], 2)) * cos((ang - env->cam.angle) *
				M_PI / 180), (int)xy[0] % 64, 6);
			sprite->type = 1;
			sprite = sprite->next;
		}
		if (env->map[(int)xy[1] / 64][(int)xy[0] / 64].type == 'W' ||
			((int)xy[0] / 64 < 0 && (int)xy[0] / 64 >= env->map_y_max &&
			(int)xy[1] / 64 < 0 && (int)xy[1] / 64 >= env->map_x_max))
				break ;
		xy[1] += xaya[1];
		xy[0] += xaya[0];
	}
	hor->dist = sqrt(pow(env->cam.y - (int)xy[0], 2) + pow(env->cam.x -
		(int)xy[1], 2)) * cos((ang - env->cam.angle) * M_PI / 180);
	hor->mod = (int)xy[0] % 64;
	return (hor);
}

/*
** dist[0] = distance du mur
** dist[1] = colonne qu'on touche
** dist[2] = Orientation du mur
*/

t_ray	*closest_wall(t_env *env, float ang)
{
	t_ray	*distance;
	t_ray	*hor;
	t_ray	*ver;

	distance = create_ray(0, 0, 0);
	distance->ang = ang;
	if (ang != 0 && ang != 180)
		hor = find_hor_wall(env, ang);
	else
		hor = create_ray(2147483648, 0, 0);
	if (ang != 90 && ang != 270)
		ver = find_ver_wall(env, ang);
	else
		ver = create_ray(2147483648, 0, 0);
	distance->dist = (hor->dist < ver->dist) ? hor->dist : ver->dist;
	distance->mod = (hor->dist < ver->dist) ? hor->mod : ver->mod;
	distance->id = (hor->dist < ver->dist) ? hor->id : ver->id;
	distance->next = sprite_list(hor, ver);
	return (distance);
}

void	raycasting(t_env *env)
{
	t_ray	*distance;
	float	ang;
	int		xy[3];
	int		ray;
	float	cone;

	ray = -1;
	cone = (float)FOV / (float)WIN_WIDTH;
	xy[2] = 0;
	while (++ray < WIN_WIDTH)
	{
		ang = env->cam.angle + (ray * cone) - 30;
		ang = (ang > 359) ? ang - 360 : ang;
		ang = (ang < 0) ? ang + 360 : ang;
		distance = closest_wall(env, ang);
		xy[0] = ray;
		xy[1] = 0;
		draw_column(env, distance, xy);
		free_listr(distance);
	}
}

void	display(t_env *env)
{
	raycasting(env);
	draw_hud(env);
	check_status(env);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
	if (env->gun.id != 0)
		fire(env);
	else if (env->reload.id != 0)
		reload(env);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr2, 0, 0);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr3, 0, 0);
	if(env->win != 1 && env->p_health > 0)
		mlx_string_put(env->mlx_ptr, env->win_ptr, 860, 75, 0xD1E7C3, ft_itoa(env->r_ammo));
}

/*
** IMG1 = Raycasting + vie + munitions
** IMG 2 = GUN
** IMG3 = HUD
*/