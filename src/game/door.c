/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jominodi <jominodi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 10:32:59 by jominodi          #+#    #+#             */
/*   Updated: 2020/06/19 16:03:16 by jominodi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		check_key(char *key, char ref)
{
	int i;

	i = 0;
	while (i < 10)
	{
		if (key[i] == ref)
			return (0);
		i++;
	}
	return (-1);
}

void	open_door(t_env *env)
{
	if (env->door_id == 0)
	{
		env->door_x = (env->cam.x + sin(env->cam.angle * RAD) * 32) / 64;
		env->door_y = (env->cam.y + cos(env->cam.angle * RAD) * 32) / 64;
		if (env->map[env->door_x][env->door_y].type == 'D' &&
		check_key(env->player.key, env->map[env->door_x]
			[env->door_y].id) != -1 && env->map[env->door_x]
			[env->door_y].id < 60)
		{
			env->map[env->door_x][env->door_y].id = 60;
			env->door_id = 1;
		}
	}
}

t_ray	*add_doors_h(float xy[4], t_env *env, float ang)
{
	t_ray	*door;

	door = create_ray(sqrt(pow(env->cam.y -
		(int)(xy[0] + xy[2] / 2), 2) + pow(env->cam.x -
		(int)(xy[1] + xy[3] / 2), 2)) * cos((ang - env->cam.angle)
		* RAD), (int)(xy[0] + xy[2] / 2) % 64, 9);
	door->door = (int)env->map[(int)xy[1] / 64][(int)xy[0] /
		64].id - 60;
	door->type = 3;
	door->mapx = (int)xy[0] / 64;
	door->mapy = (int)xy[1] / 64;
	return (door);
}

t_ray	*add_doors_h2(float xy[4], t_env *env, float ang)
{
	t_ray	*door;

	door = create_ray(sqrt(pow(env->cam.y -
		(int)(xy[0] + xy[2] / 2), 2) + pow(env->cam.x -
		(int)(xy[1] + xy[3] / 2), 2)) * cos((ang - env->cam.angle)
		* RAD), (int)(xy[0] + xy[2] / 2) % 64, 13);
	door->door = (int)env->map[(int)xy[1] / 64][(int)xy[0] /
		64].id - 60;
	door->type = 3;
	door->mapx = (int)xy[0] / 64;
	return (door);
}

t_ray	*add_doors_v(float xy[4], t_env *env, float ang)
{
	t_ray	*door;

	door = create_ray(sqrt(pow(env->cam.y -
		(int)(xy[0] + xy[2] / 2), 2) + pow(env->cam.x -
		(int)(xy[1] + xy[3] / 2), 2)) * cos((ang - env->cam.angle)
		* RAD), (int)(xy[1] + xy[3] / 2) % 64, 9);
	door->door = (int)env->map[(int)xy[1] / 64][(int)xy[0] /
		64].id - 60;
	door->type = 3;
	door->mapx = (int)xy[0] / 64;
	door->mapy = (int)xy[1] / 64;
	return (door);
}

t_ray	*add_doors_v2(float xy[4], t_env *env, float ang)
{
	t_ray	*door;

	door = create_ray(sqrt(pow(env->cam.y -
		(int)(xy[0] + xy[2] / 2), 2) + pow(env->cam.x -
		(int)(xy[1] + xy[3] / 2), 2)) * cos((ang - env->cam.angle)
		* RAD), (int)(xy[1] + xy[3] / 2) % 64, 13);
	door->door = (int)env->map[(int)xy[1] / 64][(int)xy[0] /
		64].id - 60;
	door->type = 3;
	door->mapx = (int)xy[0] / 64;
	return (door);
}

void	setup_door_h(t_env *env, float xy[4], float ang, t_ray **spr)
{
	if (check_key(env->player.key, env->map[(int)xy[1] / 64]
		[(int)xy[0] / 64].id) == 0)
	{
		(*spr)->next = add_doors_h2(xy, env, ang);
		*spr = (*spr)->next;
	}
	(*spr)->next = add_doors_h(xy, env, ang);
}

void	setup_door_v(t_env *env, float xy[4], float ang, t_ray **spr)
{
	if (check_key(env->player.key, env->map[(int)xy[1] / 64]
		[(int)xy[0] / 64].id) == 0)
	{
		(*spr)->next = add_doors_v2(xy, env, ang);
		*spr = (*spr)->next;
	}
	(*spr)->next = add_doors_v(xy, env, ang);
}
