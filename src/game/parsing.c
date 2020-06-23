/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videloff <videloff@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 12:16:17 by jominodi          #+#    #+#             */
/*   Updated: 2020/06/22 14:29:22 by videloff         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void		error_pars(int error, int fd)
{
	char *line;

	if (fd != -13)
	{
		while (get_next_line(fd, &line))
			free(line);
		close(fd);
	}
	if (error == 1)
		ft_putstr_fd("Specified filed does not exist or can't be read.\n", 2);
	else if (error == 2)
		ft_putstr_fd("Invalid char in the map file.\n", 2);
	else if (error == 3)
		ft_putstr_fd("There must be at least as much keys than doors.\n", 2);
	else if (error == 4)
	{
		ft_putstr_fd("The file must be a 100x50 char and each line ", 2);
		ft_putstr_fd("must be followed by a newline.\n", 2);
	}
	exit(-1);
}

void		set_spawn(t_env *env, int x, int y)
{
	env->cam.x = (x * BLOCK + 32);
	env->cam.y = (y * BLOCK + 32);
}

void		save_map(char *line, t_env *env, int y)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while (i < env->size_x)
	{
		if (line[i] == 'K')
			env->num_key++;
		else if (line[i] == 'D')
			env->num_door++;
		env->map[y][x].type = line[i];
		if (line[i] == 'B')
			set_spawn(env, y, x);
		i++;
		env->map[y][x].id = line[i];
		i++;
		x++;
	}
}

void		parsing(char *filename, t_env *env, int fd)
{
	char	tmp;
	char	*line;
	int		i;

	i = -1;
	if ((!((fd = open(filename, O_RDONLY)) > 1)) ||
			((read(fd, &tmp, 0)) != 0))
		error_pars(1, -13);
	while ((tmp = get_next_line(fd, &line) > 0))
	{
		env->size_x = ft_strlen(line);
		if (valid_char_new(line) == -1)
			error_pars(2, fd);
		save_map(line, env, ++i);
		free(line);
		env->size_x != 100 ? error_pars(4, fd) : 0;
	}
	if (i != 49)
		error_pars(4, fd);
	if (env->num_door != env->num_key)
		error_pars(3, fd);
	env->link_dk = env->num_key;
	close(fd);
	check_map(env);
}
