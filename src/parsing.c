/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 14:27:12 by yalabidi     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/16 11:10:36 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

void	set_map_null(t_env *env)
{
	int i;

	i = 0;
	if (env->f_mini != 1)
	{
		if (env->map)
			free(env->map);
		if (env)
			free(env);
		error(2);
	}
	while (i <= env->map_x_max)
		env->map[i++] = NULL;
}

int		second_open(char *file, t_env *env)
{
	int		y;
	int		fd;
	char	*tmp;
	char	*line;

	y = 0;
	if (!((fd = open(file, O_RDONLY)) > 1) || (read(fd, &tmp, 0)) != 0)
		return (-1);
	while (get_next_line(fd, &line) == 1)
	{
		y = set_line(line, y, env, ft_countword(line, ' '));
		if (line)
			free(line);
	}
	close(fd);
	return (1);
}

int		valid_char(char *str, int x, t_env *env)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == 'F')
			env->f_mini = 1;
		if (str[i] != 'W' && str[i] != 'F' && str[i])
			return (-1);
	}
	if (x != env->map_y_max)
		return (-1);
	return (1);
}

int		first_open(char *file, t_env *env, int x, int fd)
{
	char	tmp;
	char	*line;

	if ((!((fd = open(file, O_RDONLY)) > 1)) || ((read(fd, &tmp, 0)) != 0))
		return (-1);
	while ((tmp = get_next_line(fd, &line) > 0))
	{
		env->map_x_max++;
		x = ft_countword(line, ' ');
		env->map_y_max = (env->map_y_max == -1) ? x : env->map_y_max;
		if (valid_char(line, x, env) == -1)
		{
			line ? free(line) : 0;
			error(2);
		}
		line ? free(line) : 0;
	}
	if (!(env->map = (t_block**)malloc(sizeof(t_block*) *
			(env->map_x_max + 1))))
		return (-1);
	env->map_y_max++;
	set_map_null(env);
	close(fd);
	return (1);
}

int		parsing(char *file, t_env *env)
{
	init_info(env);
	if (!first_open(file, env, 0, 0))
	{
		free(env);
		error(1);
	}
	env->f_mini = 0;
	if (!second_open(file, env))
	{
		free(env->map);
		free(env);
		error(1);
	}
	set_angle(env, 0);
	return (0);
}
