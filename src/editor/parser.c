/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jominodi <jominodi@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 18:01:00 by jominodi          #+#    #+#             */
/*   Updated: 2020/02/25 12:57:52 by jominodi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void		error_editor(t_edit *edit, int error)
{
	if (error == 1)
		ft_putstr_fd("Le fichier n existe pas ou ne peut pas etre lu\n", 2);
	else if (error == 2)
		ft_putstr_fd("Un caractere de la map n'est pas valide\n", 2);
	else if (error == 3)
		ft_putstr_fd("Il y a un nombre different de clefs / portes\n", 2);
	else if (error == 4)
		ft_putstr_fd("Le nombre de ligne du fichier doit etre egal a 50\n", 2);
	free(edit);
	exit(-1);
}

//K D F W P B E L A G Z C

int			valid_char_new(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != 'K' && line[i] != 'D' && line[i] != 'F' &&
			line[i] != 'W' && line[i] != 'P' && line[i] != 'B' &&
			line[i] != 'E' && line[i] != 'L' && line[i] != 'A' &&
			line[i] != 'G' && line[i] != 'Z' && line[i] != 'C' &&
			(line[i + 1] < 48 || line[i + 1] > 57) && line[i])
				return (-1);
		i += 2;
	}
	return (0);
}

void		save_tab_editor(char *line, t_edit *edit, int i)
{
	int y;
	int x;

	y = 0;
	x = 0;
	while (y < edit->size_y)
	{
		if (line[y] == 'K')
			edit->num_key++;
		else if (line[y] == 'D')
			edit->num_door++;
		edit->map[x][i].type = line[y];
		y++;
		edit->map[x][i].id = line[y];
		y++;
		x++;
	}
}

int			open_file_editor(t_edit *edit, int fd)
{
	char	tmp;
	char	*line;
	int		i;

	i = -1;
	if ((!((fd = open(edit->filename, O_RDONLY)) > 1)) ||
			((read(fd, &tmp, 0)) != 0))
		return (-1);
	while ((tmp = get_next_line(fd, &line) > 0))
	{
		edit->size_y = ft_strlen(line);
		if (valid_char_new(line) == -1)
			error_editor(edit, 2);
		save_tab_editor(line, edit, ++i);
		line ? free(line) : 0;
	}
	if (i > 49)
		error_editor(edit, 4);
	if (edit->num_door != edit->num_key)
		error_editor(edit, 3);
	edit->link_dk = edit->num_key;
	close(fd);
	return (1);
}
