/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_editor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jominodi <jominodi@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 17:03:32 by jominodi          #+#    #+#             */
/*   Updated: 2020/03/09 10:34:08 by jominodi         ###   ########lyon.fr   */
/*                                                                            */
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
	load_texture_editor(edit);
	print_hud_editor(edit);
	return (0);
}

void	init_edit_info(t_edit *edit)
{
	ft_bzero(edit, sizeof(t_edit));
	edit->size_x = -1;
	edit->zoom = 25;
	edit->id = 'W';
	edit->link_dk = '0';
}

void	init_verif_value(t_verif *verif)
{
	verif->beginning = 0;
	verif->door = 0;
	verif->ending = 0;
	verif->key = 0;
	verif->err = 0;
}

void	load_texture_editor(t_edit *edit)
{
	int a;
	int b;

	a = 960;
	b = 600;
	edit->spr[0].img = mlx_xpm_file_to_image(edit->mlx_ptr,
		"sprites/map_editor.xpm", &a, &b);
	edit->spr[0].data = mlx_get_data_addr(edit->spr[0].img,
		&edit->spr[0].bpp, &edit->spr[0].sl, &edit->spr[0].end);
}
