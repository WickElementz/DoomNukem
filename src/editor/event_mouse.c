/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jominodi <jominodi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 17:10:47 by jominodi          #+#    #+#             */
/*   Updated: 2020/06/23 09:53:20 by jominodi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void		top_right_button(int x, t_edit *edit)
{
	if (x > 767 && x < 823)
		editor_to_game(edit);
	else if (x > 827 && x < 883)
	{
		check_map_editor(edit);
		if (edit->verif.err == 0)
			save_map_editor(edit);
	}
	else if (x > 887 && x < 943)
		exit_hook_editor(edit);
}

void		change_wall(t_edit *edit, int x, int y)
{
	if (edit->map[x][y].id >= '0' && edit->map[x][y].id < '3')
		edit->map[x][y].id += 1;
	else if (edit->map[x][y].id == '3')
		edit->map[x][y].id = '0';
}

void		change_pillar(t_edit *edit, int x, int y)
{
	if (edit->map[x][y].id >= '0' && edit->map[x][y].id < '9')
		edit->map[x][y].id += 1;
	else if (edit->map[x][y].id == '9')
		edit->map[x][y].id = '0';
}

void		mouse_hook_editor2(t_edit *edit, int mapx, int mapy)
{
	if (edit->map[mapx][mapy].type == 'K' ||
		edit->map[mapx][mapy].type == 'D')
		link_door_key_editor(edit, mapx, mapy);
	else if (edit->map[mapx][mapy].type == 'W')
		change_wall(edit, mapx, mapy);
	else if (edit->map[mapx][mapy].type == 'Z')
		change_pillar(edit, mapx, mapy);
}

int			mouse_hook_editor(int key, int x, int y, t_edit *edit)
{
	int	mapx;
	int	mapy;

	mapx = (x - 230) / edit->zoom + edit->mapx;
	mapy = (y - 50) / edit->zoom + edit->mapy;
	if (key == 1 && y > 82 && y < 515 && ((x > 15 && x < 185) ||
			(x > 773 && x < 943)))
		choose_block(x, y, edit);
	else if (key == 1 && x > 229 && x < 731 && y > 49 && y < 551
				&& edit->id != 'a')
		place_block(x, y, edit);
	else if (key == 1 && x > 767 && x < 947 && y > 19 && y < 65)
		top_right_button(x, edit);
	if (key == 3 && x > 229 && x < 731 && y > 49 && y < 551)
		remove_block(x, y, edit);
	if (key == 2)
		mouse_hook_editor2(edit, mapx, mapy);
	display_editor(edit);
	return (0);
}
