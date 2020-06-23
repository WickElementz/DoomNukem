/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videloff <videloff@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 13:15:12 by jominodi          #+#    #+#             */
/*   Updated: 2020/06/22 14:29:22 by videloff         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	read_tab_editor(t_edit *edit)
{
	int		x;
	int		y;
	t_clr	clr;

	x = 230;
	while (x < 730)
	{
		y = 50;
		while (y < 550)
		{
			if ((y - 50) % edit->zoom == 0)
				clr = gclr_editor(edit, (x - 230) / edit->zoom + edit->mapx,
								(y - 50) / edit->zoom + edit->mapy);
			put_pxl_editor(edit, x, y, clr);
			y++;
		}
		x++;
	}
}

void	initialise_tab_editor(t_edit *edit)
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
				edit->map[x][y].type = 'W';
			else
				edit->map[x][y].type = 'F';
			edit->map[x][y].id = '0';
			y++;
		}
		x++;
	}
}

void	fill_tab_editor(t_edit *edit)
{
	int x;
	int y;

	x = 0;
	while (x < 50)
	{
		y = 0;
		while (y < 50)
		{
			edit->map[x][y].type = 'W';
			edit->map[x][y].id = '0';
			y++;
		}
		x++;
	}
}
