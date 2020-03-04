/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jominodi <jominodi@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 09:53:57 by jominodi          #+#    #+#             */
/*   Updated: 2020/03/04 13:20:20 by jominodi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

int		init_mlx_from_edit(t_env *env)
{
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
