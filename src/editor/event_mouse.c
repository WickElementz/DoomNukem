/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   event_mouse.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/07 17:10:47 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/11 11:49:04 by jominodi    ###    #+. /#+    ###.fr     */
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

void			choose_block(int x, int y, t_edit *edit)
{
	const char	nom[12] = {'F', 'W', 'P', 'D', 'B', 'E',
						'L', 'A', 'G', 'Z', 'K', 'C'};
	int			secu;
	float		tmp;

	tmp = ((float)y - 82) / (float)77; //2.18
	y = (int)tmp; // 2
	tmp -= y; // 0.18
	if (tmp - 0.65 >= 0)
		return ;
	else
		secu = y;		
	edit->id = x <= 185 ? nom[secu] : nom[secu + 6];
}

int				mouse_hook_editor(int key, int x, int y, t_edit *edit)
{
	dprintf(1, "%d %d", x, y);
	if (key == 1 && y > 82 && y < 515 && ((x > 15 && x < 185) || (x > 773 && x < 943)))
		choose_block(x, y, edit);
	else if (key == 1 && x > 229 && x < 731 && y > 49 && y < 551)
		place_block(x, y, edit, 1);
	else if (key == 1 && x > 730 && x < 961 && y >= 0 && y < 80)
	{
		save_map(edit);
		free(edit);
		exit(0);
	}
	if (key == 2 && x > 229 && x < 731 && y > 49 && y < 551)
		place_block(x, y, edit, 2);
	display_editor(edit);
	return (0);
}