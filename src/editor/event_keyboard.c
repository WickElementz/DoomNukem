/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   event_keyboard.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/07 17:02:52 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/07 17:15:48 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "doom_nukem.h"

int			hold_key_editor(int key, t_edit *edit)
{
	static int posx = 0;
	static int posy = 0;
	if (key == KEY_ESCAPE)
	{
		if (edit)
			free(edit);
		exit(0);
	}
	if (key == KEY_LEFT && edit->mapx > 0 && edit->zoom == 25)
		edit->mapx -= 1;
	if (key == KEY_UP && edit->mapy > 0 && edit->zoom == 25)
		edit->mapy -= 1;
	if (key == KEY_RIGHT && edit->mapx < 30 && edit->zoom == 25)
		edit->mapx += 1;
	if (key == KEY_DOWN && edit->mapy < 30 && edit->zoom == 25)
		edit->mapy += 1;
	if (key == KEY_TAB)
	{
		if (edit->zoom == 10)
		{
			edit->mapx = posx;
			edit->mapy = posy;
		}
		else
		{
			posx = edit->mapx;
			posy = edit->mapy;
			edit->mapx = 0;
			edit->mapy = 0;
		}
		edit->zoom = edit->zoom == 10 ? 25 : 10;
	}
	display_editor(edit);
	return (0);
}
