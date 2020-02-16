/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   editor.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/05 10:31:34 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/11 11:40:50 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "doom_nukem.h"

void	read_tab(t_edit *edit)
{
	int		x;
	int		y;
	t_clr	clr;

	x = 0;
	while (x < 500)
	{
		y = 0;
		while (y < 500)
		{
			if (y % edit->zoom == 0)
				clr = get_color(edit, x / edit->zoom + edit->mapx, y / edit->zoom + edit->mapy);
			put_pxl_editor2(edit, x, y, clr);
			y++;
		}
		x++;
	}
}

void	display_editor(t_edit *edit)
{
	read_tab(edit);
	mlx_put_image_to_window(edit->mlx_ptr, edit->win_ptr, edit->img_ptr2, 230, 50);
	mlx_put_image_to_window(edit->mlx_ptr, edit->win_ptr, edit->img_ptr, 0, 0);
}

static void		loop_mlx_editor(t_edit *edit)
{
	display_editor(edit);
//	mlx_mouse_move(edit->win_ptr, 500, -320);
	mlx_hook(edit->win_ptr, 2, 1, hold_key_editor, edit);
	mlx_hook(edit->win_ptr, 4, 0, mouse_hook_editor, edit);  
	mlx_loop(edit->mlx_ptr);
}

void        editor(char *file, int ac)
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
	if (ac == 2)
		initialise_tab(edit);
	else
	{
		parsing_editor(file, edit);
		edit->zoom = edit->size_x > edit->size_y ? 500 / edit->size_x : 500 / edit->size_y;
		dprintf(1, "%d", edit->zoom);
	}
	load_texture_editor(edit);
	print_hud_editor(edit);
	loop_mlx_editor(edit);
}