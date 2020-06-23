/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videloff <videloff@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 18:01:00 by jominodi          #+#    #+#             */
/*   Updated: 2020/06/22 14:29:22 by videloff         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void		error_editor(t_edit *edit, int error, int fd)
{
	char *line;

	if (fd != -13)
	{
		while (get_next_line(fd, &line))
			free(line);
		close(fd);
	}
	if (error == 1)
		ft_putstr_fd("File does not exist or is invalid at some point.\n", 2);
	else if (error == 2)
		ft_putstr_fd("The map contains at least one invalid char.\n", 2);
	else if (error == 3)
		ft_putstr_fd("Numbers of doors and keys are not equals.\n", 2);
	else if (error == 4)
	{
		ft_putstr_fd("The map file must be a 100x50 characters,\n", 2);
		ft_putstr_fd("each line followed by a newline.\n", 2);
	}
	if (edit->filename)
		free(edit->filename);
	exit(-1);
}

int			valid_char_new(char *line)
{
	int i;

	i = 0;
	if (ft_strlen(line) != 100)
	{
		free(line);
		return (-1);
	}
	while (line[i])
	{
		if (((line[i] != 'K' && line[i] != 'D' && line[i] != 'F' &&
			line[i] != 'W' && line[i] != 'P' && line[i] != 'B' &&
			line[i] != 'E' && line[i] != 'L' && line[i] != 'A' &&
			line[i] != 'G' && line[i] != 'Z' && line[i] != 'C' && i % 2 == 0) ||
			(i % 2 == 1 && !ft_isdigit(line[i])) || (i % 2 == 1 && line[i - 1]
			== 'W' && ft_atoi(&line[i]) > 3)) && line[i])
		{
			free(line);
			return (-1);
		}
		i++;
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
	free(line);
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
	while ((tmp = get_next_line(fd, &line)) > 0)
	{
		edit->size_y = ft_strlen(line);
		if (valid_char_new(line) == -1)
			error_editor(edit, 2, fd);
		save_tab_editor(line, edit, ++i);
		edit->size_y != 100 ? error_editor(edit, 4, fd) : 0;
	}
	if (i != 49)
		error_editor(edit, 4, fd);
	if (edit->num_door != edit->num_key)
		error_editor(edit, 3, fd);
	edit->link_dk = (char)edit->num_key + 48;
	close(fd);
	return (1);
}
