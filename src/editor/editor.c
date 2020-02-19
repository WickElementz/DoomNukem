/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jominodi <jominodi@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:31:04 by jominodi          #+#    #+#             */
/*   Updated: 2020/02/19 11:10:56 by jominodi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void			display_error(t_edit *edit)
{
	if (edit->verif.err == 1)
		mlx_string_put(edit->mlx_ptr, edit->win_ptr, 20, 20, 0xFFFFFF,
						ERR_VALID_DOOR);
	else if (edit->verif.err == 2)
		mlx_string_put(edit->mlx_ptr, edit->win_ptr, 20, 20, 0xFFFFFF,
						ERR_NUM_DK);
	else if (edit->verif.err == 3)
		mlx_string_put(edit->mlx_ptr, edit->win_ptr, 20, 20, 0xFFFFFF,
						ERR_LINK_DK);
	else if (edit->verif.err == 4)
		mlx_string_put(edit->mlx_ptr, edit->win_ptr, 20, 20, 0xFFFFFF,
						ERR_START);
	else if (edit->verif.err == 5)
		mlx_string_put(edit->mlx_ptr, edit->win_ptr, 20, 20, 0xFFFFFF,
						ERR_END);
	else if (edit->verif.err == 6)
		mlx_string_put(edit->mlx_ptr, edit->win_ptr, 20, 20, 0xFFFFFF,
						ERR_WALL);
}

void			display_editor(t_edit *edit)
{
	read_tab_editor(edit);
	mlx_put_image_to_window(edit->mlx_ptr, edit->win_ptr, edit->img_ptr2,
								230, 50);
	mlx_put_image_to_window(edit->mlx_ptr, edit->win_ptr, edit->img_ptr, 0, 0);
	display_error(edit);
}

static void		loop_mlx_editor(t_edit *edit)
{
	display_editor(edit);
	mlx_mouse_move(edit->win_ptr, 500, -320);
	mlx_hook(edit->win_ptr, 2, 1, hold_key_editor, edit);
	mlx_hook(edit->win_ptr, 4, 0, mouse_hook_editor, edit);
	mlx_loop(edit->mlx_ptr);
}

void			editor(char *mode, char *file)
{
	t_edit	*edit;

	if (!(edit = malloc(sizeof(t_edit))))
		error(3);
	init_edit_info(edit);
	if (init_mlx_editor(edit) < 0)
	{
		if (edit)
			free(edit);
		exit(0);
	}
	edit->filename = malloc(sizeof(char) * (ft_strlen(file) + 1));
	edit->filename = file;
	if (ft_strcmp(mode, "create") == 0)
		initialise_tab_editor(edit);
	else
	{
		fill_tab_editor(edit);
		if (open_file_editor(edit, 0) == -1)
			error_editor(edit, 3);
	}
	load_texture_editor(edit);
	print_hud_editor(edit);
	loop_mlx_editor(edit);
}
