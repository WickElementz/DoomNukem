/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jominodi <jominodi@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 17:03:02 by jominodi          #+#    #+#             */
/*   Updated: 2020/02/19 10:38:21 by jominodi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

char	*ctoa(t_edit *edit, int i)
{
	int		strtmp;
	int		edittmp;
	char	*str;

	str = malloc(sizeof(char) * (51 + edit->num_key + edit->num_door));
	strtmp = 0;
	edittmp = 0;
	edit->write = 51;
	while (edittmp < 50)
	{
		str[strtmp] = edit->tab[edittmp][i].type;
		strtmp++;
		if (edit->tab[edittmp][i].type == 'D' ||
			edit->tab[edittmp][i].type == 'K')
		{
			str[strtmp] = (char)edit->tab[edittmp][i].id;
			strtmp++;
			edit->write++;
		}
		edittmp++;
	}
	str[strtmp] = '\n';
	return (str);
}

void	save_map_editor(t_edit *edit)
{
	int		i;
	char	*str;
	int		fd;

	i = 0;
	fd = open(edit->filename,
				O_CREAT | O_WRONLY, 00700);
	while (i < 50)
	{
		str = ctoa(edit, i);
		write(fd, str, edit->write);
		i++;
		free(str);
	}
	close(fd);
}

t_clr	gclr_editor(t_edit *edit, int x, int y)
{
	const char	id[12] = {'F', 'W', 'P', 'D', 'B', 'E',
						'L', 'A', 'G', 'Z', 'K', 'C'};
	const int	clrtab[12] = {FLOOR, WALL, PANE, DOOR, BEGINNING, ENDING,
					LIFE, AMMO, GUNNER, PILLAR, KEY, CORONA};
	int			corr;

	corr = 0;
	while (corr < 12)
	{
		if (edit->tab[x][y].type == id[corr])
		{
			edit->color = clrtab[corr];
			break ;
		}
		corr++;
	}
	return (gclr(edit->color, 0));
}
