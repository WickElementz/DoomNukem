/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raiko <raiko@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 17:10:47 by jominodi          #+#    #+#             */
/*   Updated: 2020/06/02 12:02:33 by raiko            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

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

int			mouse_hook_editor(int key, int x, int y, t_edit *edit)
{
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
		link_door_key_editor(edit, (x - 230) / edit->zoom + edit->mapx,
						(y - 50) / edit->zoom + edit->mapy);
	display_editor(edit);
	return (0);
}
