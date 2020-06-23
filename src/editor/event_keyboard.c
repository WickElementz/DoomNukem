/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_keyboard.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanne <kanne@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:31:44 by jominodi          #+#    #+#             */
/*   Updated: 2020/06/23 11:55:42 by kanne            ###   ########lyon.fr   */
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
	mlx_destroy_image(edit->mlx_ptr, edit->spr[0].img);
	mlx_destroy_window(edit->mlx_ptr, edit->win_ptr);
	free(edit->mlx_ptr);
	exit(0);
	return (0);
}

void		choose_life(t_edit *edit)
{
	int	x;
	int	y;
	int	tmp;
	int	tmpx;

	x = 24;
	tmp = edit->p_l;
	while (tmp > 0)
	{
		tmpx = x + 12;
		while (x < tmpx)
		{
			y = 563;
			while (y < 577)
			{
				put_pxl_editor(edit, x, y, gclr(0xFFFFFF, 0));
				y++;
			}
			x++;
		}
		tmp--;
		x += 4;
	}
}

void		choose_bullet(t_edit *edit)
{
	int	x;
	int	y;
	int	tmp;
	int	tmpx;

	x = 775;
	tmp = edit->p_b;
	while (tmp > 0)
	{
		tmpx = x + 12;
		while (x < tmpx)
		{
			y = 563;
			while (y < 577)
			{
				put_pxl_editor(edit, x, y, gclr(0xFFFFFF, 0));
				y++;
			}
			x++;
		}
		tmp--;
		x += 4;
	}
}

int			hold_key_editor(int key, t_edit *edit)
{
	if (key == KEY_ESCAPE)
	{
		exit_hook_editor(edit);
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
	if (key == KEY_I)
		edit->p_l += (edit->p_l < 10) ? 1 : 0;
	if (key == KEY_U)
		edit->p_l += (edit->p_l > 0) ? -1 : 0;
	if (key == KEY_P)
		edit->p_b += (edit->p_b < 10) ? 1 : 0;
	if (key == KEY_O)
		edit->p_b += (edit->p_b > 0) ? -1 : 0;
	display_editor(edit);
	return (0);
}
