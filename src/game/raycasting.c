/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   raycasting.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kanne <kanne@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/28 13:51:12 by videloff     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/13 11:20:27 by kanne       ###    #+. /#+    ###.fr     */
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
		if (env->map[(int)xy[1] / 64][(int)xy[0] / 64].type == 'S')
		{
		//	sprite->next = create_ray(sqrt(pow((int) xy[1] - env->cam.y, 2) + pow((int)xy[0] + 0.5 - env->cam.x, 2)), (int)xy[0] % 64 ,7);
			sprite->next = create_ray(sqrt(pow(env->cam.y - (int)xy[0], 2) + pow(env->cam.x -
				(int)xy[1], 2)) * cos((ang - env->cam.angle) * M_PI / 180), (int)xy[1] % 64, 7);
			sprite->next->type = 2;
			sprite = sprite->next;
		}
		if (env->map[(int)xy[1] / 64][(int)xy[0] / 64].type == 'G')
		{
			sprite->next = create_ray(sqrt(pow(env->cam.y - (int)xy[0], 2) + pow(env->cam.x -
				(int)xy[1], 2)) * cos((ang - env->cam.angle) * M_PI / 180), (int)xy[1] % 64, 6);
			sprite = sprite->next;
			sprite->type = 1;
			sprite->mapx = (int)xy[0] / 64;
			sprite->mapy = (int)xy[1] / 64;
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
		if (env->map[(int)xy[1] / 64][(int)xy[0] / 64].type == 'S')
		{
		//	sprite->next = create_ray(sqrt(pow((int) xy[1] - env->cam.y, 2) + pow((int)xy[0] + 0.5 - env->cam.x, 2)), (int)xy[0] % 64 ,7);
			sprite->next = create_ray(sqrt(pow(env->cam.y - (int)xy[0], 2) + pow(env->cam.x -
				(int)xy[1], 2)) * cos((ang - env->cam.angle) * M_PI / 180), (int)xy[0] % 64, 7);
			sprite->next->type = 2;
			sprite->next->id = 7;
			sprite = sprite->next;
		}
		if (env->map[(int)xy[1] / 64][(int)xy[0] / 64].type == 'G')
		{
			sprite->next = create_ray(sqrt(pow(env->cam.y - (int)xy[0], 2) +
				pow(env->cam.x - (int)xy[1], 2)) * cos((ang - env->cam.angle) *
				M_PI / 180), (int)xy[0] % 64, 6);
<<<<<<< HEAD
			sprite->type = 1;
			sprite->mapx = (int)xy[0] / 64;
			sprite->mapy = (int)xy[1] / 64;
=======
>>>>>>> 62c56b74478cb73832375b461cb154dfbe4dc600
			sprite = sprite->next;
			sprite->type = 1;		
			sprite->mapx = (int)xy[0] / 64;
			sprite->mapy = (int)xy[1] / 64;
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

void	*raycasting(void	*data)
{
	t_ray	*distance;
	float	ang;
	int		xy[3];
	int		ray;
	float	cone;
	t_thread	*thread;

	thread = (t_thread *)data;
	ray = thread->start - 1;
	cone = (float)FOV / (float)WIN_WIDTH;
	xy[2] = 0;
	while (++ray < thread->end)
	{
		ang = thread->env->cam.angle + (ray * cone) - 30;
		ang = (ang > 359) ? ang - 360 : ang;
		ang = (ang < 0) ? ang + 360 : ang;
		distance = closest_wall(thread->env, ang);
		xy[0] = ray;
		xy[1] = 0;
		draw_column(thread->env, distance, xy);
		free_listr(distance);
	}
	return (NULL);
}

t_thread	*init_thread(t_env *env)
{
	t_thread	*tab;
	int			i;

	i = 0;
	tab = malloc(sizeof(t_thread) * 8);
	while (i < 8)
	{
		tab[i].start = 120 * i;
		tab[i].end = 120 * i + 120;
		tab[i].env = env;
		i++;
	}
	return (tab);
}

void	ray_multi_thread(t_env *env)
{
	static t_thread	*tab = NULL;
	int				i;

	i = 0;
	if (tab == NULL)
		tab = init_thread(env);
	while (i < 8)
	{
		pthread_create(&tab[i].t, NULL, raycasting, &tab[i]);
		i++;
	}
	while (i--)
		pthread_join(tab[i].t, NULL);
}

void	display(t_env *env)
{
	ray_multi_thread(env);
//	raycasting(env);
	draw_hud(env);
	check_status(env);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
//	if (env->gun.id != 0)
//		fire(env);
//	else if (env->reload.id != 0)
//		reload(env);
//	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr2, 0, 0);
//	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr3, 0, 0);
//	if(env->win != 1 && env->p_health > 0)
//		mlx_string_put(env->mlx_ptr, env->win_ptr, 860, 75, 0xD1E7C3, ft_itoa(env->r_ammo));
}

/*
** IMG1 = Raycasting + vie + munitions
** IMG 2 = GUN
** IMG3 = HUD
*/