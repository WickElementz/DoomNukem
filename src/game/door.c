/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jominodi <jominodi@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 10:32:59 by jominodi          #+#    #+#             */
/*   Updated: 2020/02/26 10:32:01 by jominodi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

/*
** Y + 1 = angle > 315 || angle < 45
** Y - 1 = angle > 45 && angle < 135
** X + 1 = angle > 135 && angle < 225 
** X - 1 = angle > 225 && angle < 315
*/

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

void		open_door(t_env *env)
{
	env->x = (env->cam.x + sin(env->cam.angle * M_PI / 180) * 32) / 64;
	env->y = (env->cam.y + cos(env->cam.angle * M_PI / 180) * 32) / 64;
	if (env->map[env->x][env->y].type == 'D' && check_key(env->player.key,
		env->map[env->x][env->y].id) != -1 && env->map[env->x][env->y].id < 60)
	{
		env->map[env->x][env->y].id = 60;
		env->door_id = 1;
	}
}