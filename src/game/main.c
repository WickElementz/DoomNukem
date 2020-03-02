/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jominodi <jominodi@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:59:05 by videloff          #+#    #+#             */
/*   Updated: 2020/03/02 12:27:27 by jominodi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

int		init_mlx(t_env *env)
{
	if (!(env->mlx_ptr = mlx_init()))
		return (-1);
	if (!(env->win_ptr =
		mlx_new_window(env->mlx_ptr, WIN_WIDTH, WIN_HEIGHT / 2, "Doom-Nukem")))
		return (-1);
	if (!(env->img_ptr = mlx_new_image(env->mlx_ptr, WIN_WIDTH, 600)))
		return (-1);
	env->data_ptr = mlx_get_data_addr(env->img_ptr, &env->bpp,
					&env->size_line, &env->endian);
	if (!(env->img_ptr2 = mlx_new_image(env->mlx_ptr, WIN_WIDTH, 600)))
		return (-1);
	env->data_ptr2 = mlx_get_data_addr(env->img_ptr2, &env->bpp,
					&env->size_line, &env->endian);
	if (!(env->img_ptr3 = mlx_new_image(env->mlx_ptr, WIN_WIDTH, 600)))
		return (-1);
	env->data_ptr3 = mlx_get_data_addr(env->img_ptr3, &env->bpp,
					&env->size_line, &env->endian);
	if (env->data_ptr == NULL)
		return (-1);
	load_texture(env);
	print_hud(env, 4);
	gun(env, 0);
	return (0);
}

void	loop_mlx(t_env *env)
{
	display(env);
	mlx_mouse_move(env->win_ptr, 500, -320);
	mlx_hook(env->win_ptr, 2, 1, hold_key, env);
	mlx_hook(env->win_ptr, 3, 2, unhold_key, env);
	mlx_hook(env->win_ptr, 6, 0, mouse_move, env);
	mlx_mouse_hook(env->win_ptr, mouse_hook, env);
	mlx_loop_hook(env->mlx_ptr, event_key, env);
	mlx_loop(env->mlx_ptr);
}

void	init_info(t_env *env)
{
	ft_bzero(env, sizeof(t_env));
	env->cam.z = 32.0;
	env->up = 300;
	env->cam.speed = 6;
	env->player.life = 100;
	env->player.ammo = 6;
	env->player.stock = 12;
	env->gun.obj = 8;
	env->gun.time = 220000;
	env->reload.time = 250000;
	env->player.ammo = 6;
	env->player.life = 100;
}

void	free_env(t_env *env, int set)
{
	if (env)
		free(env);
	if (set > 0 && set <= 4)
		error(set);
	exit(0);
}

int		main(int ac, char **av)
{
	int		fd;
	t_env	*env;

	fd = 0;
	if ((((fd = open(av[1], O_RDONLY)) < 1) || (read(fd, NULL, 0) == -1))
			&& ac == 2)
		error(1);
	if (ac < 2 || ac >= 4)
		usage();
	if (ac == 3 && ft_strcmp("edit", av[1]) == 0)
		editor(av[1], av[2]);
	else if (ac == 3 && ft_strcmp("create", av[1]) == 0)
		editor(av[1], av[2]);
	else if (ac == 2)
	{
		if (!(env = malloc(sizeof(t_env))))
			error(3);
		init_info(env);
		parsing(av[1], env, 0);
		if ((init_mlx(env)) < 0)
			free_env(env, 4);
		loop_mlx(env);
		free_env(env, 0);
	}
	else
		ft_putstr("please use ./doom-nukem edit 'name of map'");
	return (0);
}
