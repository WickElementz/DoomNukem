/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_to_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jominodi <jominodi@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 10:00:33 by jominodi          #+#    #+#             */
/*   Updated: 2020/02/25 14:02:39 by jominodi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	save_edit_to_env(t_edit *edit, t_env *env)
{
	int x;
	int y;

	x = 0;
	while (x < 50)
	{
		y = 0;
		while (y < 50)
		{
			env->map[y][x].type = edit->map[x][y].type;
			if (edit->map[x][y].type == 'D' || edit->map[x][y].type == 'K')
				env->map[y][x].id = edit->map[x][y].id;
			if (env->map[y][x].type == 'B')
				set_spawn(env, y, x);
			y++;
		}
		x++;
	}
}

void	editor_to_game(t_edit *edit)
{
	t_env		*env;
	check_map_editor(edit);
	if (edit->verif.err == 0)
	{
		if (!(env = malloc(sizeof(t_env))))
			error(3);
		mlx_destroy_window(edit->mlx_ptr, edit->win_ptr);
		init_info(env);
		init_mlx(env);
		save_edit_to_env(edit, env);
		loop_mlx(env);
		free(edit);
	}
}