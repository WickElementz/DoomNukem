/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jominodi <jominodi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 10:32:59 by jominodi          #+#    #+#             */
/*   Updated: 2020/06/01 11:02:51 by jominodi         ###   ########lyon.fr   */
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
