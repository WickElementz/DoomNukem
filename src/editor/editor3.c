/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   editor3.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/06 15:30:18 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/07 16:35:42 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "doom_nukem.h"

void	place_block(int x, int y, t_edit *edit, int click)
{
	int tmp_xy[2];

	tmp_xy[0] = (x - 230) / edit->zoom;
	tmp_xy[1] = (y - 50) / edit->zoom;
	if (click == 1)
		edit->tab[tmp_xy[0] + edit->mapx][tmp_xy[1] + edit->mapy].type = edit->id;
	else if (click == 2)
		edit->tab[tmp_xy[0] + edit->mapx][tmp_xy[1] + edit->mapy].type = 'F';
}