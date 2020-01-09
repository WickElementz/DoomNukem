/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: videloff <videloff@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/30 10:31:54 by videloff     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/16 17:28:34 by videloff    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static t_fdlist	*lstfdnew(int fd)
{
	t_fdlist	*chain;

	if (!(chain = malloc(sizeof(t_fdlist))))
		return (NULL);
	chain->str = ft_strnew(0);
	chain->next = NULL;
	chain->fd = fd;
	return (chain);
}

static t_fdlist	*multifd(int fd, t_fdlist *lst)
{
	t_fdlist *link;

	link = lst;
	while (link->next && link->fd != fd)
		link = link->next;
	if (link->fd == fd)
		return (link);
	if (!(link->next = lstfdnew(fd)))
		return (NULL);
	return (link->next);
}

static char		*readline(char *str, int fd)
{
	char	*temp;
	int		rd;
	char	buff[BUFF_SIZE + 1];

	rd = 1;
	temp = NULL;
	while (!ft_strchr(str, '\n') && rd)
	{
		if ((rd = read(fd, buff, BUFF_SIZE)) > 0)
		{
			buff[rd] = '\0';
			if (!(temp = ft_strsub(str, 0, ft_strlen(str))))
				return (NULL);
			free(str);
			if (!(str = ft_strjoin(temp, buff)))
				return (NULL);
			free(temp);
		}
	}
	return (str);
}

int				get_next_line(const int fd, char **line)
{
	static t_fdlist	*lst = NULL;
	int				i;
	t_fdlist		*temp;
	char			*temp2;
	char			buff[BUFF_SIZE + 1];

	if (!line || fd < 0 || BUFF_SIZE < 1 || read(fd, buff, 0) == -1)
		return (-1);
	if (!lst)
		if (!(lst = lstfdnew(fd)))
			return (-1);
	if (!(temp = multifd(fd, lst)))
		return (-1);
	if (!(temp->str = readline(temp->str, fd)))
		return (-1);
	i = 0;
	while ((temp->str)[i] && (temp->str)[i] != '\n')
		i++;
	if (!(temp->str[0]))
		return (0);
	*line = ft_strsub(temp->str, 0, i);
	temp2 = temp->str;
	temp->str = ft_strsub(temp2, i + 1, ft_strlen(temp->str));
	free(temp2);
	return (1);
}
