/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: videloff <videloff@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 14:27:12 by yalabidi     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/10 14:24:10 by videloff    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "doom_nukem.h"

static void		set_map_null(t_env *env)
{
	int i;

	i = 0;
	if (env->f_mini != 1)
		free_env(env, 2);
	while (i <= env->map_x_max)
		env->map[i++] = NULL;
}

static int		second_open(char *file, t_env *env)
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

static int		valid_char(char *str, int x, t_env *env)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == 'F')
			env->f_mini = 1;
		if (str[i] != 'W' && str[i] != 'F' && str[i] != 'G' && str[i])
			return (-1);
	}
	if (x != env->map_y_max)
		return (-1);
	return (1);
}

static int		first_open(char *file, t_env *env, int x, int fd)
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

int				parsing(char *file, t_env *env)
{
	init_info(env);
	if (!first_open(file, env, 0, 0))
	{
		free_env(env, 3);
		error(1);
	}
	env->f_mini = 0;
	if (!second_open(file, env))
	{
		free_env(env, 1);
		error(1);
	}
	set_angle(env, 0);
	return (0);
}
