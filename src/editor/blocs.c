/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blocs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jominodi <jominodi@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 12:40:36 by videloff          #+#    #+#             */
/*   Updated: 2020/02/25 12:32:15 by jominodi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "doom_nukem.h"

void		remove_block(int o_x, int o_y, t_edit *edit)
{
	int x;
	int y;

	x = (o_x - 230) / edit->zoom + edit->mapx;
	y = (o_y - 50) / edit->zoom + edit->mapy;
	if (edit->map[x][y].type == 'K')
	{
		edit->num_key--;
		if (edit->map[x][y].id != 'a')
			check_link_dk_editor(edit, x, y, 'D');
	}
	else if (edit->map[x][y].type == 'D')
	{
		edit->num_door--;
		if (edit->map[x][y].id != 'a')
			check_link_dk_editor(edit, x, y, 'K');
	}
	edit->map[x][y].type = 'F';
}

void		place_block(int o_x, int o_y, t_edit *edit)
{
	int x;
	int y;

	x = (o_x - 230) / edit->zoom + edit->mapx;
	y = (o_y - 50) / edit->zoom + edit->mapy;
	edit->map[x][y].type = edit->id;
	if (edit->id == 'K')
	{
		edit->num_key++;
		edit->map[x][y].id = 'a';
	}
	else if (edit->id == 'D')
	{
		edit->num_door++;
		edit->map[x][y].id = 'a';
	}
	if (edit->map[x][y].type != 'D' && edit->map[x][y].type != 'K')
		edit->map[x][y].id = '0';
}

void		choose_block(int x, int y, t_edit *edit)
{
	const char	nom[12] = {'F', 'W', 'P', 'D', 'B', 'E',
						'L', 'A', 'G', 'Z', 'K', 'C'};
	int			secu;
	float		tmp;

	tmp = ((float)y - 82) / (float)77;
	y = (int)tmp;
	tmp -= y;
	if (tmp - 0.65 >= 0)
		return ;
	else
		secu = y;
	edit->id = x <= 185 ? nom[secu] : nom[secu + 6];
}
