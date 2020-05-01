/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jominodi <jominodi@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 13:02:55 by jominodi          #+#    #+#             */
/*   Updated: 2020/03/12 11:40:44 by jominodi         ###   ########lyon.fr   */
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
	int	ang;

	ang = 0;
	check_status(env);
	check_gunner(env);
	if (env->player.corona != 0)
		corona(env);
	ray_multi_thread(env);
	draw_hud(env);
	if (env->door_id != 0)
		door(env);
	if (env->jump != 0)
		jump(env);
	if (env->crouch_id != 0)
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

t_clr			add_sprite(t_env *env, t_ray *ray, int xy[3])
{
	unsigned int	color;
	t_clr			clr;

	color = 0;
	if (xy[1] > ray->mrg && xy[1] < ray->mrg + ray->wall && ray->type == 3 &&
		ray->cmpt <= ray->wall)
		color = (ray->cmpt > ray->wall) ? 0 : add_sprite2(env, ray, color);
	else if (xy[1] > ray->mrg && xy[1] < ray->mrg + ray->wall && ray->cmpt <=
				ray->wall)
	{
		if (ray->cmpt < ray->wall - 1)
			ft_memcpy(&color, &env->text[(int)ray->id].data[(((int)ray->mod) +
					(env->text[(int)ray->id].sl / 4) *
					(64 * ray->cmpt / ray->wall)) * 4], sizeof(int));
		ray->cmpt++;
		if (env->sick == 1)
			color *= 12 + 255;
	}
	else
		color = 0;
	clr = gclr(color, 0);
	return (clr);
}


t_ray			*create_spr(float xy[4], t_env *env, float ang)
{
	t_ray	*spr;
	float	poscer[3];

	spr = create_ray(sqrt(pow(env->cam.x - ((int)(xy[1] / 64) * 64 + 32), 2) +
		pow(env->cam.y - ((int)(xy[0] / 64) * 64 + 32), 2)), 0, 7);
	poscer[0] = (env->cam.y - ((int)(xy[0] / 64) * 64 + 32)) / spr->dist;
	poscer[1] = (env->cam.x - ((int)(xy[1] / 64) * 64 + 32)) / spr->dist;
	poscer[2] = right_angle(ang, atan(poscer[0] / poscer[1]) * 180 / M_PI);
	spr->mod = 32 - spr->dist * tan((ang - poscer[2]) * M_PI / 180);
	spr->mod = (spr->mod >= 64 || spr->mod < 0) ? 0 : spr->mod;
	spr->mapx = (int)xy[0] / 64;
	spr->mapy = (int)xy[1] / 64;
	spr->type = 2;
	spr->id = get_spr_id(env->map[spr->mapy][spr->mapx].type);
	return (spr);
}
