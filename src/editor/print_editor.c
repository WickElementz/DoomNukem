/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_editor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jominodi <jominodi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 17:02:55 by jominodi          #+#    #+#             */
/*   Updated: 2020/06/01 11:02:51 by jominodi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

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
