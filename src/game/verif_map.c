/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jominodi <jominodi@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 12:33:26 by jominodi          #+#    #+#             */
/*   Updated: 2020/02/19 11:37:10 by jominodi         ###   ########lyon.fr   */
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

void		verif_pane(t_env *env, int o_x, int o_y, int add)
{
	short	x;
	short	y;

	x = o_x;
	y = o_y;
	while (env->map[x][y].type == 'P')
		y += add;
	if (env->map[x][y].type == 'W')
		env->verif.ver_p_sn++;
	y = o_y;
	while (env->map[x][y].type == 'P')
		x += add;
	if (env->map[x][y].type == 'W')
		env->verif.ver_p_we++;
	(add == 1) ? verif_pane(env, o_x, o_y, -1) : 0;
}

void		verif_map(t_env *env, int x, int y)
{
	env->verif.ver_p_sn = 0;
	env->verif.ver_p_we = 0;
	if (env->map[x][y].type == 'P')
	{
		verif_pane(env, x, y, 1);
		if (env->verif.ver_p_we < 2 && env->verif.ver_p_sn < 2)
			env->verif.err = 1;
	}
	else if (env->map[x][y].type == 'D')
	{
		verif_door(env, x, y);
		if (env->verif.ver_door != 1)
			env->verif.err = 2;
		if (verif_link_dk(env, 'K', env->map[x][y].id) == -1)
			env->verif.err = 4;
	}
	else if (env->map[x][y].type == 'K')
	{
		if (verif_link_dk(env, 'D', env->map[x][y].id) == -1)
			env->verif.err = 4;
	}
	else if (env->map[x][y].type == 'B')
		env->verif.beginning++;
	else if (env->map[x][y].type == 'E')
		env->verif.ending++;
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
				env->verif.err = 7;
			verif_map(env, x, y);
			y++;
		}
		x++;
	}
	if (env->num_door != env->num_key)
		env->verif.err = 3;
	else if (env->verif.beginning != 1)
		env->verif.err = 5;
	else if (env->verif.ending == 0)
		env->verif.err = 6;
}