/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   editor.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/05 10:31:34 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 14:58:16 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "doom_nukem.h"

int			hold_key2(int key, t_edit *edit)
{
	if (key == KEY_ESCAPE)
	{
		if (edit)
			free(edit);
		exit(0);
	}
	return (0);
}

static int        init_mlx_editor(t_edit *edit)
{
	if (!(edit->mlx_ptr = mlx_init()))
		return (-1);
	if (!(edit->win_ptr =
		mlx_new_window(edit->mlx_ptr, 960, 600, "Edit-Doom")))
		return (-1);
	if (!(edit->img_ptr = mlx_new_image(edit->mlx_ptr, 960, 600)))
		return (-1);
	edit->data_ptr = mlx_get_data_addr(edit->img_ptr, &edit->bpp,
					&edit->sl, &edit->end);
	return (0);
}

void	display_editor(t_edit *edit)
{
	char str[2];
	str[0] = edit->id;
	str[1] = '\0';
	mlx_put_image_to_window(edit->mlx_ptr, edit->win_ptr, edit->img_ptr, 0, 0);
	mlx_string_put(edit->mlx_ptr, edit->win_ptr, 480, 300, 0x000000, str);
}

static void		loop_mlx_editor(t_edit *edit)
{
	display_editor(edit);
	mlx_mouse_move(edit->win_ptr, 500, -320);
	mlx_hook(edit->win_ptr, 2, 1, hold_key2, edit);
	mlx_mouse_hook(edit->win_ptr, mouse_hook_editor, edit);  
	mlx_loop(edit->mlx_ptr);
}

void        editor()
{
	t_edit	*edit;

	if (!(edit = malloc(sizeof(t_edit))))
		error(3);
	ft_bzero(edit, sizeof(t_edit));
	if (init_mlx_editor(edit) < 0)
		dprintf(1, "fail");
	load_texture_editor(edit);
	print_hud_editor(edit);
	loop_mlx_editor(edit);
}