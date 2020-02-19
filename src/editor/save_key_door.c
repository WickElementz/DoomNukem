/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_key_door.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videloff <videloff@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 13:10:49 by jominodi          #+#    #+#             */
/*   Updated: 2020/02/19 13:34:24 by videloff         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	down_link_dk_editor(t_edit *edit, int value)
{
	int x;
	int y;

	x = 0;
	while (x < 50)
	{
		y = 0;
		while (y < 50)
		{
			if (edit->tab[x][y].type == 'D' || edit->tab[x][y].type == 'K')
				if (edit->tab[x][y].id > (char)value + 48)
					edit->tab[x][y].id--;
			y++;
		}
		x++;
	}
	edit->link_dk--;
}

void	check_link_dk_editor(t_edit *edit, int save_x, int save_y, char c)
{
	int x;
	int y;

	x = 0;
	while (x < 50)
	{
		y = 0;
		while (y < 50)
		{
			if (edit->tab[x][y].type == c)
			{
				if (edit->tab[x][y].id == edit->tab[save_x][save_y].id)
				{
					c == 'K' ? edit->num_key-- : 0;
					c == 'D' ? edit->num_door-- : 0;
					edit->tab[x][y].type = 'F';
					down_link_dk_editor(edit, (int)edit->tab[x][y].id - 48);
					return ;
				}
			}
			y++;
		}
		x++;
	}
}

void	link_door_key_editor(t_edit *edit, int x, int y)
{
	if (edit->tab[x][y].id < '0' || edit->tab[x][y].id > '9')
	{
		if (edit->tab[x][y].type == 'D' && edit->link_door == 0)
		{
			edit->tab[x][y].id = (char)edit->link_dk + 48;
			edit->link_door = 1;
		}
		if (edit->tab[x][y].type == 'K' && edit->link_door == 1)
		{
			edit->tab[x][y].id = (char)edit->link_dk + 48;	
			edit->link_dk++;
			edit->link_door = 0;
		}
	}
}
