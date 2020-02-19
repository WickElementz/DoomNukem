/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blocs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videloff <videloff@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 12:40:36 by videloff          #+#    #+#             */
/*   Updated: 2020/02/19 12:40:40 by videloff         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "doom_nukem.h"

void		remove_block(int o_x, int o_y, t_edit *edit)
{
	int x;
	int y;

	x = (o_x - 230) / edit->zoom;
	y = (o_y - 50) / edit->zoom;
	if (edit->tab[x + edit->mapx][y + edit->mapy].type == 'K')
	{
		edit->num_key--;
		check_link_dk_editor(edit, x + edit->mapx, y + edit->mapy, 'D');
	}
	else if (edit->tab[x + edit->mapx][y + edit->mapy].type == 'D')
	{
		edit->num_door--;
		check_link_dk_editor(edit, x + edit->mapx, y + edit->mapy, 'K');
	}
	edit->tab[x + edit->mapx][y + edit->mapy].type = 'F';
}

void		place_block(int o_x, int o_y, t_edit *edit)
{
	int x;
	int y;

	x = (o_x - 230) / edit->zoom;
	y = (o_y - 50) / edit->zoom;
	if (edit->id == 'K')
	{
		edit->num_key++;
		edit->tab[x + edit->mapx][y + edit->mapy].id = 'a';
	}
	else if (edit->id == 'D')
	{
		edit->num_door++;
		edit->tab[x + edit->mapx][y + edit->mapy].id = 'a';
	}
	edit->tab[x + edit->mapx][y + edit->mapy].type = edit->id;
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
