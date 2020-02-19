/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jominodi <jominodi@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 13:33:33 by jominodi          #+#    #+#             */
/*   Updated: 2020/02/19 11:29:31 by jominodi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

/*
** Porte entouré de deux portes puis 2 different de porte & vitre
** vitre entouré mur,
** au moins 1 point E
** au moins 1 point B
*/

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
			if (edit->tab[x][y].type == type && edit->tab[x][y].id == id
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
	if (edit->tab[x][y + 1].type == 'W' && edit->tab[x][y - 1].type == 'W')
	{
		if ((edit->tab[x + 1][y].type != 'W' &&
				edit->tab[x + 1][y].type != 'P') &&
					(edit->tab[x - 1][y].type != 'W' &&
						edit->tab[x - 1][y].type != 'P'))
			edit->verif.ver_door++;
	}
	if (edit->tab[x + 1][y].type == 'W' && edit->tab[x - 1][y].type == 'W')
	{
		if ((edit->tab[x][y + 1].type != 'W' &&
				edit->tab[x][y + 1].type != 'P') &&
					(edit->tab[x][y - 1].type != 'W' &&
						edit->tab[x][y - 1].type != 'P'))
			edit->verif.ver_door++;
	}
}

void		verif_map_editor(t_edit *edit, int x, int y)
{
	if (edit->tab[x][y].type == 'D')
	{
		verif_door_editor(edit, x, y);
		if (edit->verif.ver_door != 1)
			edit->verif.err = 1;
		if (verif_link_dk_editor(edit, 'K', edit->tab[x][y].id) == -1)
			edit->verif.err = 3;
	}
	else if (edit->tab[x][y].type == 'K')
	{
		if (verif_link_dk_editor(edit, 'D', edit->tab[x][y].id) == -1)
			edit->verif.err = 3;
	}
	else if (edit->tab[x][y].type == 'B')
		edit->verif.beginning++;
	else if (edit->tab[x][y].type == 'E')
		edit->verif.ending++;
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
					edit->tab[x][y].type != 'W')
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
