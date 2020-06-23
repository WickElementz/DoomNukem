/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videloff <videloff@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 12:33:26 by jominodi          #+#    #+#             */
/*   Updated: 2020/06/22 14:29:22 by videloff         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

int			verif_link_dk(t_env *env, char type, char id)
{
	int x;
	int y;

	x = 0;
	while (x < 50)
	{
		y = 0;
		while (y < 50)
		{
			if (env->map[x][y].type == type && env->map[x][y].id == id
					&& id != 'a')
				return (0);
			y++;
		}
		x++;
	}
	return (-1);
}

void		verif_door(t_env *env, int x, int y)
{
	if (env->map[x][y + 1].type == 'W' && env->map[x][y - 1].type == 'W')
	{
		if ((env->map[x + 1][y].type != 'W' &&
				env->map[x + 1][y].type != 'P') &&
					(env->map[x - 1][y].type != 'W' &&
						env->map[x - 1][y].type != 'P'))
			env->verif.ver_door++;
	}
	if (env->map[x + 1][y].type == 'W' && env->map[x - 1][y].type == 'W')
	{
		if ((env->map[x][y + 1].type != 'W' &&
				env->map[x][y + 1].type != 'P') &&
					(env->map[x][y - 1].type != 'W' &&
						env->map[x][y - 1].type != 'P'))
			env->verif.ver_door++;
	}
}

void		verif_map(t_env *env, int x, int y)
{
	if (env->map[x][y].type == 'D')
	{
		verif_door(env, x, y);
		if (env->verif.ver_door != 1)
			error_valid_map(1);
		if (verif_link_dk(env, 'K', env->map[x][y].id) == -1)
			error_valid_map(3);
	}
	else if (env->map[x][y].type == 'K')
	{
		if (verif_link_dk(env, 'D', env->map[x][y].id) == -1)
			error_valid_map(3);
	}
	else if (env->map[x][y].type == 'B')
		env->verif.beginning++;
	else if (env->map[x][y].type == 'E')
		env->verif.ending++;
	else if (env->num_door > 10 || env->num_key > 10)
		error_valid_map(7);
}

void		check_map(t_env *env)
{
	int x;
	int y;

	x = 0;
	init_verif_value(&env->verif);
	while (x < 50)
	{
		y = 0;
		while (y < 50)
		{
			env->verif.ver_door = 0;
			if ((x == 0 || x == 49 || y == 0 || y == 49) &&
					env->map[x][y].type != 'W')
				error_valid_map(6);
			verif_map(env, x, y);
			y++;
		}
		x++;
	}
	if (env->num_door != env->num_key)
		error_valid_map(2);
	else if (env->verif.beginning != 1)
		error_valid_map(4);
	else if (env->verif.ending == 0)
		error_valid_map(5);
}
