/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jominodi <jominodi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 13:33:33 by jominodi          #+#    #+#             */
/*   Updated: 2020/06/01 11:02:51 by jominodi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			verif_link_dk_editor(t_edit *edit, char type, char id)
{
	int x;
	int y;

	x = 0;
	while (x < 50)
	{
		y = 0;
		while (y < 50)
		{
			if (edit->map[x][y].type == type && edit->map[x][y].id == id
					&& id != 'a')
				return (0);
			y++;
		}
		x++;
	}
	return (-1);
}

void		verif_door_editor(t_edit *edit, int x, int y)
{
	if (edit->map[x][y + 1].type == 'W' && edit->map[x][y - 1].type == 'W')
	{
		if ((edit->map[x + 1][y].type != 'W' &&
				edit->map[x + 1][y].type != 'P') &&
					(edit->map[x - 1][y].type != 'W' &&
						edit->map[x - 1][y].type != 'P'))
			edit->verif.ver_door++;
	}
	if (edit->map[x + 1][y].type == 'W' && edit->map[x - 1][y].type == 'W')
	{
		if ((edit->map[x][y + 1].type != 'W' &&
				edit->map[x][y + 1].type != 'P') &&
					(edit->map[x][y - 1].type != 'W' &&
						edit->map[x][y - 1].type != 'P'))
			edit->verif.ver_door++;
	}
}

void		verif_map_editor(t_edit *edit, int x, int y)
{
	if (edit->map[x][y].type == 'D')
	{
		verif_door_editor(edit, x, y);
		if (edit->verif.ver_door != 1)
			edit->verif.err = 1;
		if (verif_link_dk_editor(edit, 'K', edit->map[x][y].id) == -1)
			edit->verif.err = 3;
	}
	else if (edit->map[x][y].type == 'K')
	{
		if (verif_link_dk_editor(edit, 'D', edit->map[x][y].id) == -1)
			edit->verif.err = 3;
	}
	else if (edit->map[x][y].type == 'B')
		edit->verif.beginning++;
	else if (edit->map[x][y].type == 'E')
		edit->verif.ending++;
	else if (edit->num_door > 10 || edit->num_key > 10)
		edit->verif.err = 7;
}

void		check_map_editor(t_edit *edit)
{
	int x;
	int y;

	x = 0;
	init_verif_value(&edit->verif);
	while (x < 50)
	{
		y = 0;
		while (y < 50)
		{
			edit->verif.ver_door = 0;
			if ((x == 0 || x == 49 || y == 0 || y == 49) &&
					edit->map[x][y].type != 'W')
				edit->verif.err = 6;
			verif_map_editor(edit, x, y);
			y++;
		}
		x++;
	}
	if (edit->num_door != edit->num_key)
		edit->verif.err = 2;
	else if (edit->verif.beginning != 1)
		edit->verif.err = 4;
	else if (edit->verif.ending == 0)
		edit->verif.err = 5;
}
