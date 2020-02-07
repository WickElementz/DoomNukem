/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   editor3.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/06 15:30:18 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/07 12:52:05 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "doom_nukem.h"

void	place_block(int x, int y, t_edit *edit)
{
	int tmp_xy[2];

	tmp_xy[0] = (x - 230) / 20;
	tmp_xy[1] = (y - 50) / 20;
	edit->tab[tmp_xy[0]][tmp_xy[1]].type = edit->id;
//	print_block(x / 20 * 20, y / 20 * 20, edit); 
}
/*
const char	id[12] = {'F', 'W', 'P', 'D', 'B', 'E',
						'L', 'A', 'G', 'Z', 'K', 'C'};
	const int	clrtab[12] = {FLOOR, WALL, PANE, DOOR, BEGINNING, ENDING,
					LIFE, AMMO, GUNNER, PILLAR, KEY, CORONA};
	int corr = 0;
	color = NONE;
	while (corr < 12)
	{
		if (edit->id == id[corr])
		{
			color = clrtab[corr];
			break ;
		}
		corr++;
	}*/