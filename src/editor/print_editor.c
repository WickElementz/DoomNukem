/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_editor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jominodi <jominodi@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 17:02:55 by jominodi          #+#    #+#             */
/*   Updated: 2020/02/27 14:08:10 by jominodi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	put_pxl_editor2(t_edit *edit, int x, int y, t_clr clr)
{
	if (x >= 0 && x < 500 && y >= 0 && y < 500)
	{
		edit->data_ptr2[(y * WIN_WIDTH + x) * 4] = clr.b;
		edit->data_ptr2[(y * WIN_WIDTH + x) * 4 + 1] = clr.g;
		edit->data_ptr2[(y * WIN_WIDTH + x) * 4 + 2] = clr.r;
		edit->data_ptr2[(y * WIN_WIDTH + x) * 4 + 3] = clr.a;
	}
}

void	put_pxl_editor(t_edit *edit, int x, int y, t_clr clr)
{
	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		edit->data_ptr[(y * WIN_WIDTH + x) * 4] = clr.b;
		edit->data_ptr[(y * WIN_WIDTH + x) * 4 + 1] = clr.g;
		edit->data_ptr[(y * WIN_WIDTH + x) * 4 + 2] = clr.r;
		edit->data_ptr[(y * WIN_WIDTH + x) * 4 + 3] = clr.a;
	}
}

void	print_hud_editor(t_edit *edit)
{
	int				x;
	int				y;
	t_clr			clr;
	unsigned int	color;

	x = -1;
	while (++x < 960)
	{
		y = -1;
		while (++y < 600)
		{
			ft_memcpy(&color, &edit->spr[0].data[(x + 960 *
					y) * 4], sizeof(int));
			clr = ((int)color != NONE) ? gclr(color, 0) : gclr(0xFFFFFF, 255);
			put_pxl_editor(edit, x, y, clr);
		}
	}
}
