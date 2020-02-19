/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jominodi <jominodi@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 13:15:12 by jominodi          #+#    #+#             */
/*   Updated: 2020/02/19 10:38:15 by jominodi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	read_tab_editor(t_edit *edit)
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
				clr = gclr_editor(edit, x / edit->zoom + edit->mapx,
								y / edit->zoom + edit->mapy);
			put_pxl_editor2(edit, x, y, clr);
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
				edit->tab[x][y].type = 'W';
			else
				edit->tab[x][y].type = 'F';
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
			edit->tab[x][y].type = 'W';
			y++;
		}
		x++;
	}
}
