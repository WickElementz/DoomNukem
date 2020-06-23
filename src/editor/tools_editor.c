/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_editor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videloff <videloff@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 17:03:02 by jominodi          #+#    #+#             */
/*   Updated: 2020/06/22 14:29:22 by videloff         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	verif_path(char *file)
{
	char	str[5];
	int		i;

	i = -1;
	while (++i < 4 && file[i])
		str[i] = file[i];
	str[4] = '\0';
	if (ft_strcmp(str, "map/") != 0)
	{
		ft_putstr("The map's path does not work. Please, use the");
		ft_putstr(" 'map/' path with the edit/create option instead.\n");
		exit(-1);
	}
}

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
