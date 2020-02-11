/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/07 17:03:32 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/11 10:45:55 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "doom_nukem.h"

int		init_mlx_editor(t_edit *edit)
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

void	init_edit_info(t_edit *edit)
{
	ft_bzero(edit, sizeof(t_edit));
	edit->zoom = 25;
}

void	load_texture_editor(t_edit *edit)
{
	int a;
	int b;

	a = 960;
	b = 960;
	edit->spr[0].img = mlx_xpm_file_to_image(edit->mlx_ptr,
		"sprites/map_editor.xpm", &a, &b);
	edit->spr[0].data = mlx_get_data_addr(edit->spr[0].img,
		&edit->spr[0].bpp, &edit->spr[0].sl, &edit->spr[0].end);
}

void	initialise_tab(t_edit *edit)
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

