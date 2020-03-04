/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jominodi <jominodi@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 13:02:55 by jominodi          #+#    #+#             */
/*   Updated: 2020/03/04 10:59:33 by jominodi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

t_thread	*init_thread(t_env *env)
{
	t_thread	*tab;
	int			i;

	i = 0;
	tab = malloc(sizeof(t_thread) * 8);
	while (i < 8)
	{
		tab[i].start = 120 * i;
		tab[i].end = 120 * i + 120;
		tab[i].env = env;
		i++;
	}
	return (tab);
}

void		ray_multi_thread(t_env *env)
{
	static t_thread	*tab = NULL;
	int				i;

	i = -1;
	if (tab == NULL)
		tab = init_thread(env);
	while (++i < THREADS)
		pthread_create(&tab[i].t, NULL, raycasting, &tab[i]);
	i = -1;
	while (++i < THREADS)
		pthread_join(tab[i].t, NULL);
}

void		display(t_env *env)
{
	check_status(env);
	if (env->player.corona != 0)
		corona(env);
	ray_multi_thread(env);
	draw_hud(env);
	if (env->door_id != 0)
		door(env);
	if (env->jump != 0 || (env->coro_jump == 1 && env->player.corona == 0))
		jump(env);
	if (env->crouch_id != 0 || env->coro_crouch != 0)
		crouch_animation(env);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
	if (env->gun.id != 0)
		fire(env);
	else if (env->reload.id != 0)
		reload(env);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr2, 0, 0);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr3, 0, 0);
	if (env->win != 1 && env->player.life > 0)
		mlx_string_put(env->mlx_ptr, env->win_ptr, 860, 75, 0xD1E7C3,
						ft_itoa(env->player.stock));
}
