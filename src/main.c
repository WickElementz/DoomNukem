/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/01 10:59:05 by videloff     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/09 12:24:17 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

static void		init_mlx(t_env *env)
{
	env->mlx_ptr = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx_ptr, WIN_WIDTH, WIN_HEIGHT - 200, "Wolf");
	env->img_ptr = mlx_new_image(env->mlx_ptr, WIN_WIDTH, WIN_HEIGHT - 200);
	env->data_ptr = (unsigned int *)mlx_get_data_addr(env->img_ptr, &env->bpp,
					&env->size_line, &env->endian);
	load_texture(env);
}

static int		loop_mlx(t_env *env)
{
	raycasting(env);
	mlx_loop_hook(env->mlx_ptr, event_key, env);
	mlx_hook(env->win_ptr, 2, 0, hold_key, env);
	mlx_hook(env->win_ptr, 3, 0, unhold_key, env);
	mlx_loop(env->mlx_ptr);
	return (0);
}

void			init_info(t_env *env)
{
	env->k_ev = 0;
	env->f_mini = 0;
	env->tn = 48;
	env->ts = 83;
	env->to = 139;
	env->te = 54;
	env->map_y_max = -1;
	env->cam.speed = 4;
	env->caca = 100;
	env->map_x_max = 1;
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
	init_mlx(env);
	loop_mlx(env);
	return (0);
}
