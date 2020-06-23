/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_to_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jominodi <jominodi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 10:00:33 by jominodi          #+#    #+#             */
/*   Updated: 2020/06/23 02:01:21 by jominodi         ###   ########lyon.fr   */
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
	t_env		env;

	check_map_editor(edit);
	if (edit->verif.err == 0)
	{
		init_info(&env);
		env.mlx_ptr = edit->mlx_ptr;
		env.win_ptr = edit->win_ptr;
		env.player.life = edit->p_l * 10;
		env.player.stock = edit->p_b * 6 + 6;
		mlx_destroy_image(edit->mlx_ptr, edit->spr[0].img);
		mlx_destroy_image(edit->mlx_ptr, edit->img_ptr);
		init_mlx_from_edit(&env);
		save_edit_to_env(edit, &env);
		loop_mlx(&env);
	}
}
