/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jominodi <jominodi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:31:04 by jominodi          #+#    #+#             */
/*   Updated: 2020/06/23 02:05:17 by jominodi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	display_error(t_edit *edit)
{
	if (edit->verif.err == 1)
		mlx_string_put(edit->mlx_ptr, edit->win_ptr, 390, 20, 0xFF0000,
						ERR_VALID_DOOR);
	else if (edit->verif.err == 2)
		mlx_string_put(edit->mlx_ptr, edit->win_ptr, 390, 20, 0xFF0000,
						ERR_NUM_DK);
	else if (edit->verif.err == 3)
		mlx_string_put(edit->mlx_ptr, edit->win_ptr, 390, 20, 0xFF0000,
						ERR_LINK_DK);
	else if (edit->verif.err == 4)
		mlx_string_put(edit->mlx_ptr, edit->win_ptr, 390, 20, 0xFF0000,
						ERR_START);
	else if (edit->verif.err == 5)
		mlx_string_put(edit->mlx_ptr, edit->win_ptr, 390, 20, 0xFF0000,
						ERR_END);
	else if (edit->verif.err == 6)
		mlx_string_put(edit->mlx_ptr, edit->win_ptr, 390, 20, 0xFF0000,
						ERR_WALL);
	else if (edit->verif.err == 7)
		mlx_string_put(edit->mlx_ptr, edit->win_ptr, 390, 20, 0xFF0000,
						ERR_SUP_DK);
}

void	print_key_door_link(t_edit *edit)
{
	int		x;
	int		y;
	char	str[2];

	x = edit->mapx;
	str[1] = '\0';
	while ((x - edit->mapx) < 20 && edit->zoom == 25)
	{
		y = edit->mapy;
		while ((y - edit->mapy) < 20 && edit->zoom == 25)
		{
			if ((edit->map[x][y].type == 'D' || edit->map[x][y].type == 'K' ||
				edit->map[x][y].type == 'W' || edit->map[x][y].type == 'Z')
				&& edit->map[x][y].id >= '0' && edit->map[x][y].id <= '9' &&
					edit->zoom == 25)
			{
				str[0] = edit->map[x][y].id;
				mlx_string_put(edit->mlx_ptr, edit->win_ptr, (x - edit->mapx) *
					25 + 240, (y - edit->mapy) * 25 + 63, 0xFFFFFF, str);
			}
			y++;
		}
		x++;
	}
}

void	display_editor(t_edit *edit)
{
	print_hud_editor(edit);
	choose_life(edit);
	choose_bullet(edit);
	read_tab_editor(edit);
	mlx_put_image_to_window(edit->mlx_ptr, edit->win_ptr, edit->img_ptr, 0, 0);
	print_key_door_link(edit);
	display_error(edit);
}

void	loop_mlx_editor(t_edit *edit)
{
	display_editor(edit);
	mlx_hook(edit->win_ptr, 2, 1, hold_key_editor, edit);
	mlx_mouse_hook(edit->win_ptr, mouse_hook_editor, edit);
	mlx_hook(edit->win_ptr, 33, 1L << 17, exit_hook_editor, edit);
	mlx_loop(edit->mlx_ptr);
}

void	editor(char *mode, char *file)
{
	t_edit	edit;

	init_edit_info(&edit);
	edit.filename = strdup(file);
	if (ft_strcmp(mode, "create") == 0)
		initialise_tab_editor(&edit);
	else
	{
		fill_tab_editor(&edit);
		if (open_file_editor(&edit, 0) == -1)
			error_editor(&edit, 1, -13);
	}
	verif_path(file);
	if (init_mlx_editor(&edit) < 0)
		exit(0);
	print_hud_editor(&edit);
	loop_mlx_editor(&edit);
}
