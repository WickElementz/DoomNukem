/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kanne <kanne@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/01 10:59:05 by videloff     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/17 12:56:30 by kanne       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "doom_nukem.h"

static int		init_mlx(t_env *env)
{
	if (!(env->mlx_ptr = mlx_init()))
		return (-1);
	if (!(env->win_ptr =
		mlx_new_window(env->mlx_ptr, WIN_WIDTH, WIN_HEIGHT / 2, "Wolf")))
		return (-1);
	if (!(env->img_ptr = mlx_new_image(env->mlx_ptr, WIN_WIDTH, WIN_HEIGHT / 2)))
		return (-1);
	env->data_ptr = mlx_get_data_addr(env->img_ptr, &env->bpp,
					&env->size_line, &env->endian);
	if (env->data_ptr == NULL)
		return (-1);
	load_texture(env);
	return (0);
}

static void		loop_mlx(t_env *env)
{
	raycasting(env);
	mlx_loop_hook(env->mlx_ptr, event_key, env);
	mlx_hook(env->win_ptr, 2, 1, hold_key, env);
	mlx_hook(env->win_ptr, 3, 2, unhold_key, env);
	mlx_hook(env->win_ptr, 6, 0, mouse_move, env);
	mlx_loop(env->mlx_ptr);
}

void			init_info(t_env *env)
{
	env->k_ev = 0;
	env->f_mini = 0;
	env->map_y_max = -1;
	env->up = 300;
	env->cam.speed = 4;
	env->map_x_max = 1;
}

void			free_env(t_env *env, int set)
{
	if (env)
	{
		if (env->map)
			while (env->map_x_max >= 0)
				if (env->map[env->map_x_max])
					free(env->map[env->map_x_max--]);
		free(env);
	}
	if (set > 0 && set <= 4)
		error(set);
	exit(0);
}

int				main(int ac, char **av)
{
	int		fd;
	t_env	*env;

	fd = 0;
	if (((fd = open(av[1], O_RDONLY)) < 1) || (read(fd, NULL, 0) == -1))
		error(1);
	if (ac != 2)
		usage();
	if (!(env = malloc(sizeof(t_env))))
		error(3);
	parsing(av[1], env);
	close(fd);
	if ((init_mlx(env)) < 0)
		free_env(env, 4);
	loop_mlx(env);
	free_env(env, 0);
	return (0);
}
