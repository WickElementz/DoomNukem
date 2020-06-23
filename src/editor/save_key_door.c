/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_key_door.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videloff <videloff@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 13:10:49 by jominodi          #+#    #+#             */
/*   Updated: 2020/06/22 14:29:22 by videloff         ###   ########lyon.fr   */
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
			if (edit->map[x][y].type == 'D' || edit->map[x][y].type == 'K')
				if (edit->map[x][y].id > (char)value + 48)
					edit->map[x][y].id--;
			y++;
		}
		x++;
	}
	edit->link_dk--;
}

void	check_link_dk_editor(t_edit *edit, int s_x, int s_y, char c)
{
	int x;
	int y;

	x = 0;
	while (x < 50)
	{
		y = 0;
		while (y < 50)
		{
			if (edit->map[x][y].type == c)
			{
				if (edit->map[x][y].id == edit->map[s_x][s_y].id)
				{
					c == 'K' ? edit->num_key-- : 0;
					c == 'D' ? edit->num_door-- : 0;
					edit->map[x][y].type = 'F';
					down_link_dk_editor(edit, (int)edit->map[x][y].id - 48);
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
	if (edit->map[x][y].id < '0' || edit->map[x][y].id > '9')
	{
		if (edit->map[x][y].type == 'D' && edit->link_door == 0)
		{
			edit->map[x][y].id = edit->link_dk;
			edit->save_dx = x;
			edit->save_dy = y;
			edit->link_door = 1;
		}
		if (edit->map[x][y].type == 'K' && edit->link_door == 1)
		{
			if (edit->map[edit->save_dx][edit->save_dy].id == edit->link_dk)
				edit->map[x][y].id = edit->link_dk;
			else
				edit->map[x][y].id = 'a';
			if (edit->map[x][y].id != 'a')
				edit->link_dk++;
			edit->link_door = 0;
		}
	}
}
