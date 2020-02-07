/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   editor.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/05 10:31:34 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/07 14:46:45 by jominodi    ###    #+. /#+    ###.fr     */
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
	if (key == KEY_LEFT)
		edit->mapx -= 25;
	if (key == KEY_UP)
		edit->mapy += 25;
	if (key == KEY_RIGHT)
		edit->mapx += 25;
	if (key == KEY_DOWN)
		edit->mapy -= 25;
	display_editor(edit);
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
	if (!(edit->img_ptr2 = mlx_new_image(edit->mlx_ptr, 500, 500)))
		return (-1);
	edit->data_ptr2 = mlx_get_data_addr(edit->img_ptr2, &edit->bpp,
					&edit->sl, &edit->end);
	return (0);
}

void	print_block(t_edit *edit, int xy[2])
{
	int x1;
	int y1;
	int x2;
	int y2;
	t_clr clr;

	x2 = xy[0] * 25 + 25;
	x1 = x2 - 25;
	y2 = xy[1] * 25;
	dprintf(1, "%d || %d || %d || %d\n", x1, x2, y2, y2 + 25);
	while (x1 < x2)
	{
		y1 = y2;
		while (y1 < y2 + 25)
		{
			clr = gclr(edit->color, 0);
			put_pxl_editor2(edit, y1, x1, clr);
			y1++;
		}
		x1++;
	}

}

void	read_tab(t_edit *edit)
{
	const char	id[12] = {'F', 'W', 'P', 'D', 'B', 'E',
						'L', 'A', 'G', 'Z', 'K', 'C'};
	const int	clrtab[12] = {FLOOR, WALL, PANE, DOOR, BEGINNING, ENDING,
					LIFE, AMMO, GUNNER, PILLAR, KEY, CORONA};
	int			xy[4];
	int			corr;

	edit->color = NONE;
	xy[0] = edit->mapx / 25;
	xy[2] = xy[0] + 20;
	xy[3] = edit->mapy / 25 + 20;

	while (xy[0] < xy[2])
	{
		xy[1] = edit->mapy / 25;
		while(xy[1] < xy[3])
		{
			corr = 0;
			while (corr < 12)
			{
				if (edit->tab[xy[0]][xy[1]].type == id[corr])
					edit->color = clrtab[corr];
				corr++;
			}
			print_block(edit, xy);
			xy[1]++;
		}
		xy[0]++;
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
	mlx_mouse_move(edit->win_ptr, 500, -320);
	mlx_hook(edit->win_ptr, 2, 1, hold_key2, edit);
	mlx_hook(edit->win_ptr, 4, 0, mouse_hook_editor, edit);  
	mlx_loop(edit->mlx_ptr);
}

void		initialise_tab(t_edit *edit)
{
	int x;
	int y;

	x = 0;
	while (x < 50)
	{
		y = 0;
		while (y < 50)
		{
			if (x == 0 || y == 0 || x == 49 || y == 49)
				edit->tab[x][y].type = 'W';
			else
				edit->tab[x][y].type = 'F';
			y++;
		}
		x++;
	}
}

void        editor()
{
	t_edit	*edit;

	if (!(edit = malloc(sizeof(t_edit))))
		error(3);
	ft_bzero(edit, sizeof(t_edit));
	if (init_mlx_editor(edit) < 0)
	{
		if (edit)
			free(edit);
		exit(0);
	}
	initialise_tab(edit);
	load_texture_editor(edit);
	print_hud_editor(edit);
	loop_mlx_editor(edit);
}