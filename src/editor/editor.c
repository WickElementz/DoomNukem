/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   editor.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/05 10:31:34 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/07 16:46:27 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "doom_nukem.h"

int			hold_key2(int key, t_edit *edit)
{
	static int posx = 0;
	static int posy = 0;
	if (key == KEY_ESCAPE)
	{
		if (edit)
			free(edit);
		exit(0);
	}
	if (key == KEY_LEFT && edit->mapx > 0 && edit->zoom == 25)
		edit->mapx -= 1;
	if (key == KEY_UP && edit->mapy > 0 && edit->zoom == 25)
		edit->mapy -= 1;
	if (key == KEY_RIGHT && edit->mapx < 30 && edit->zoom == 25)
		edit->mapx += 1;
	if (key == KEY_DOWN && edit->mapy < 30 && edit->zoom == 25)
		edit->mapy += 1;
	if (key == KEY_TAB)
	{
		if (edit->zoom == 10)
		{
			edit->mapx = posx;
			edit->mapy = posy;
		}
		else
		{
			posx = edit->mapx;
			posy = edit->mapy;
			edit->mapx = 0;
			edit->mapy = 0;
		}
		
		edit->zoom = edit->zoom == 10 ? 25 : 10;

	}
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
	if (!(edit->img_ptr2 = mlx_new_image(edit->mlx_ptr, 960, 600)))
		return (-1);
	edit->data_ptr2 = mlx_get_data_addr(edit->img_ptr2, &edit->bpp,
					&edit->sl, &edit->end);
	return (0);
}

t_clr	get_color(t_edit *edit, int x, int y)
{
	const char	id[12] = {'F', 'W', 'P', 'D', 'B', 'E',
						'L', 'A', 'G', 'Z', 'K', 'C'};
	const int	clrtab[12] = {FLOOR, WALL, PANE, DOOR, BEGINNING, ENDING,
					LIFE, AMMO, GUNNER, PILLAR, KEY, CORONA};
	int corr;

	corr = 0;
	while(corr < 12)
	{
		if (edit->tab[x][y].type == id[corr])
		{
			edit->color = clrtab[corr];
			break ;
		}
		corr++;
	}
	return (gclr(edit->color, 0));
}

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
	edit->zoom = 25;
	initialise_tab(edit);
	load_texture_editor(edit);
	print_hud_editor(edit);
	loop_mlx_editor(edit);
}