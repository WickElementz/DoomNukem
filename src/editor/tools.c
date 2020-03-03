/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jominodi <jominodi@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 17:03:02 by jominodi          #+#    #+#             */
/*   Updated: 2020/02/27 14:08:21 by jominodi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

char	*ctoa(t_edit *edit, int i)
{
	int		strtmp;
	int		edittmp;
	char	*str;

	str = malloc(sizeof(char) * 101);
	strtmp = 0;
	edittmp = 0;
	while (edittmp < 50)
	{
		str[strtmp] = edit->map[edittmp][i].type;
		strtmp++;
		str[strtmp] = edit->map[edittmp][i].id;
		strtmp++;
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
		write(fd, str, 101);
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
		if (edit->map[x][y].type == id[corr])
		{
			edit->color = clrtab[corr];
			break ;
		}
		corr++;
	}
	return (gclr(edit->color, 0));
}
