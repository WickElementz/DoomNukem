/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raiko <raiko@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:59:05 by videloff          #+#    #+#             */
/*   Updated: 2020/06/23 16:02:01 by raiko            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/doom_nukem.h"

void	loop_mlx(t_env *env)
{
	mlx_mouse_move(env->mlx_ptr, env->win_ptr, 480, 360);
	display(env);
	mlx_hook(env->win_ptr, 2, 1, hold_key, env);
	mlx_hook(env->win_ptr, 3, 2, unhold_key, env);
	mlx_mouse_hook(env->win_ptr, mouse_hook, env);
	mlx_hook(env->win_ptr, 6, 1 << 6, mouse_move, env);
	mlx_loop_hook(env->mlx_ptr, event_key, env);
	mlx_hook(env->win_ptr, 33, 1L << 17, exit_hook, env);
	mlx_loop(env->mlx_ptr);
}

void	destroy_textures(t_env *env)
{
	int i;

	i = -1;
	while (++i < 17)
		mlx_destroy_image(env->mlx_ptr, env->text[i].img);
	i = -1;
	while (++i < 4)
		mlx_destroy_image(env->mlx_ptr, env->sprite[i].img);
	i = -1;
	while (++i < 8)
		mlx_destroy_image(env->mlx_ptr, env->gun.spr[i].img);
	i = -1;
	while (++i < 6)
		mlx_destroy_image(env->mlx_ptr, env->reload.spr[i].img);
}

void	free_env(t_env *env, int set)
{
	mlx_destroy_image(env->mlx_ptr, env->img_ptr);
	destroy_textures(env);
	if (set > 0 && set <= 4)
		error(set);
	mlx_destroy_window(env->mlx_ptr, env->win_ptr);
	free(env->mlx_ptr);
	exit(0);
}

int		main(int ac, char **av)
{
	int		fd;
	t_env	env;

	fd = 0;
	if ((((fd = open(av[1], O_RDONLY)) < 1) || (read(fd, NULL, 0) == -1))
			&& ac == 2)
		error(1);
	if (ac == 3 && ft_strcmp("edit", av[1]) == 0)
		editor(av[1], av[2]);
	else if (ac == 3 && ft_strcmp("create", av[1]) == 0)
		editor(av[1], av[2]);
	else if (ac == 2)
	{
		init_info(&env);
		parsing(av[1], &env, 0);
		if ((init_mlx(&env)) < 0)
			free_env(&env, 4);
		loop_mlx(&env);
		free_env(&env, 0);
	}
	else
		usage();
	return (0);
}
