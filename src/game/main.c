/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raiko <raiko@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:59:05 by videloff          #+#    #+#             */
/*   Updated: 2020/05/26 10:20:25 by raiko            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/doom_nukem.h"

void	loop_mlx(t_env *env)
{
	display(env);
	mlx_hook(env->win_ptr, 2, 1, hold_key, env);
	mlx_hook(env->win_ptr, 3, 2, unhold_key, env);
	mlx_hook(env->win_ptr, 17, 0, exit_hook, env);
	mlx_loop_hook(env->mlx_ptr, event_key, env);
	mlx_loop(env->mlx_ptr);
}

void	free_env(t_env *env, int set)
{
	mlx_destroy_image(env->mlx_ptr, env->img_ptr);
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
		usage();
	return (0);
}
