/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/07 18:01:00 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/11 13:37:07 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "doom_nukem.h"

int             valid_char_new(char *line)
{
    int i;

    i = -1;
    while (line[++i])
    {
        while (line[i] == ' ')
            i++;
        if (line[i] != 'F' && line[i] != 'W' && line[i] != 'P' && line[i] != 'D' &&
             line[i] != 'B' && line[i] != 'E' && line[i] != 'L' && line[i] != 'A' && line[i] != 'G' &&
                 line[i] != 'Z' && line[i] != 'K' && line[i] != 'C' && line[i])
            exit(0);
    }
    return (0);
}

static int		first_open(char *file, t_edit *edit, int x, int fd)
{
	char	tmp;
	char	*line;

	if ((!((fd = open(file, O_RDONLY)) > 1)) || ((read(fd, &tmp, 0)) != 0))
		return (-1);
	while ((tmp = get_next_line(fd, &line) > 0))
	{
		edit->size_x++;
		x = ft_countword(line, ' ');
		edit->size_y = (edit->size_y == 0) ? x : edit->size_y;
		valid_char_new(line);
		line ? free(line) : 0;
	}
	close(fd);
	return (1);
}

void    parsing_editor(char *file, t_edit *edit)
{
    first_open(file, edit, 0, 0);
}