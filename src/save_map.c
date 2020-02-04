/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   save_map.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 13:03:11 by videloff     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/04 11:20:43 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "doom_nukem.h"

int		set_angle(t_env *env, int x)
{
	int y;

	while (x <= env->map_x_max)
	{
		y = 0;
		while (y <= env->map_y_max)
		{
			if (env->map[x][y].type == 'F' &&
					env->map[x][y + 1].type == 'F' && y < env->map_y_max)
			{
				env->cam.angle = 0;
				return (0);
			}
			else if (env->map[x][y].type == 'F' &&
						env->map[x + 1][y].type == 'F' && x < env->map_x_max)
			{
				env->cam.angle = 90;
				return (0);
			}
			y++;
		}
		x++;
	}
	return (0);
}

int		set_spawn(int x, int y, t_env *env)
{
	env->cam.x = (x * BLOCK + BLOCK / 2);
	env->cam.y = (y * BLOCK + BLOCK / 2);
	return (1);
}

void	place_wall(t_env *env, int x, int y)
{
	while (++y <= env->map_y_max)
		env->map[x][y].type = 'W';
}

int		set_line(char *line, int x, t_env *env, int len)
{
	int y;
	int i;

	y = -1;
	i = 0;
	if (!(env->map[x] = (t_block*)malloc(sizeof(t_block) * (len + 2))))
		error(1);
	if (x == 0)
		place_wall(env, x, -1);
	x == 0 ? x++ : x;
	if (x == 1)
		env->map[x] = (t_block*)malloc(sizeof(t_block) * (len + 2));
	while (++y <= env->map_y_max)
	{
		(line[i] && line[i] == ' ') ? i++ : i;
		env->map[x][y].type = (y == 0 || y == env->map_y_max) ? 'W' : line[i++];
		if (env->f_mini == 0 && env->map[x][y].type == 'F')
			env->f_mini = set_spawn(x, y, env);
	}
	if (++x == env->map_x_max)
	{
		env->map[x] = (t_block*)malloc(sizeof(t_block) * (len + 2));
		place_wall(env, x, -1);
	}
	return (x);
}