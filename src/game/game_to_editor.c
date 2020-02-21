/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_to_editor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jominodi <jominodi@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 10:17:50 by jominodi          #+#    #+#             */
/*   Updated: 2020/02/20 13:19:39 by jominodi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	save_env_to_edit(t_edit *edit, t_env *env)
{
	int x;
	int y;

	x = 0;
	while (x < 50)
	{
		y = 0;
		while (y < 50)
		{
			edit->map[y][x].type = env->map[x][y].type;
			if (env->map[x][y].type == 'D' || env->map[x][y].type == 'K')
				edit->map[y][x].id = env->map[x][y].id;
			y++;
		}
		x++;
	}
}

void	game_to_editor(t_env *env)
{
	t_edit	*edit;
	if (!(edit = malloc(sizeof(t_edit))))
		error(3);
	mlx_destroy_window(env->mlx_ptr, env->win_ptr);
	init_edit_info(edit);
	init_mlx_editor(edit);
	save_env_to_edit(edit, env);
	edit->filename = env->filename;
	loop_mlx_editor(edit);
	free(env);
}