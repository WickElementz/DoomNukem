/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_keyboard.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videloff <videloff@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:31:44 by jominodi          #+#    #+#             */
/*   Updated: 2020/03/02 15:15:36 by videloff         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void		zoom(t_edit *edit)
{
	static int posx = 0;
	static int posy = 0;

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

int			exit_hook_editor(t_edit *edit)
{
	mlx_destroy_image(edit->mlx_ptr, edit->img_ptr);
	mlx_destroy_image(edit->mlx_ptr, edit->img_ptr2);
	if (edit)
		free(edit);
	exit(0);
	return (0);
}

int			hold_key_editor(int key, t_edit *edit)
{
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
		zoom(edit);
	display_editor(edit);
	return (0);
}
