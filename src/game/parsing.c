/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jominodi <jominodi@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 12:16:17 by jominodi          #+#    #+#             */
/*   Updated: 2020/03/02 12:44:25 by jominodi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void		error_pars(t_env *env, int error)
{
	if (error == 1)
		ft_putstr_fd("Le fichier n existe pas ou ne peut pas etre lu\n", 2);
	else if (error == 2)
		ft_putstr_fd("Un caractere de la map n'est pas valide\n", 2);
	else if (error == 3)
		ft_putstr_fd("Il y a un nombre different de clefs / portes", 2);
	else if (error == 4)
		ft_putstr_fd("Le nombre de ligne du fichier doit etre egal a 50\n", 2);
	free(env);
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
		error_pars(env, 1);
	while ((tmp = get_next_line(fd, &line) > 0))
	{
		env->size_x = ft_strlen(line);
		if (valid_char_new(line) == -1)
			error_pars(env, 2);
		save_map(line, env, ++i);
		line ? free(line) : 0;
	}
	if (i > 49)
		error_pars(env, 4);
	if (env->num_door != env->num_key)
		error_pars(env, 3);
	env->link_dk = env->num_key;
	close(fd);
	check_map(env);
}
