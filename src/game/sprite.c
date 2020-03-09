/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jominodi <jominodi@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 15:28:00 by yalabidi          #+#    #+#             */
/*   Updated: 2020/03/09 12:02:44 by jominodi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

t_ray			*cpy_spr(t_ray *spr)
{
	t_ray	*new;

	if (!spr)
		return (NULL);
	if (!(new = (t_ray*)malloc(sizeof(t_ray))))
		return (NULL);
	new->dist = spr->dist;
	new->type = spr->type;
	new->mod = spr->mod;
	new->id = spr->id;
	new->mapy = spr->mapy;
	new->mapx = spr->mapx;
	new->door = spr->door;
	new->next = NULL;
	return (new);
}

static t_ray	*del_glass(t_ray *base)
{
	t_ray	*clean;
	t_ray	*c;
	t_ray	*b;
	int		i;

	i = 1;
	clean = cpy_spr(base);
	c = clean;
	b = base;
	while (b)
	{
		if (b->next && b->next->id == 6 && c->id == 6 &&
		((b->mapx - b->next->mapx >= -1 && b->mapx -
		b->next->mapx <= 1 && b->mapy - b->next->mapy == 0) || (b->mapy -
		b->next->mapy >= -1 && b->mapy - b->next->mapy <= 1 &&
		b->mapx - b->next->mapx == 0)))
			i = 0;
		if (i == 1 && b->next && (c->next = cpy_spr(b->next)))
			c = c->next;
		b = b->next;
		i = 1;
	}
	free_listr(base);
	return (clean);
}

void			sprite_list2(t_ray *move_hor, t_ray *move_ver, t_ray *move_base)
{
	while (move_hor || move_ver)
	{
		if (move_hor && move_ver)
		{
			move_base->next = (move_hor->dist < move_ver->dist) ?
				cpy_spr(move_hor) : cpy_spr(move_ver);
			if (move_hor->dist < move_ver->dist)
				move_hor = move_hor->next;
			else
				move_ver = move_ver->next;
		}
		else
		{
			move_base->next = (move_hor) ?
				cpy_spr(move_hor) : cpy_spr(move_ver);
			if (move_hor)
				move_hor = move_hor->next;
			else
				move_ver = move_ver->next;
		}
		move_base = move_base->next;
	}
}

t_ray			*sprite_list(t_ray *hor, t_ray *ver)
{
	t_ray	*move_ver;
	t_ray	*move_hor;
	t_ray	*move_base;
	t_ray	*base;

	if (!hor->next && !ver->next)
		return (NULL);
	move_ver = ver->next;
	move_hor = hor->next;
	if (move_hor && move_ver)
		base = (move_hor->dist < move_ver->dist) ?
			cpy_spr(move_hor) : cpy_spr(move_ver);
	else
		base = (move_hor) ? cpy_spr(move_hor) : cpy_spr(move_ver);
	move_base = base;
	sprite_list2(move_hor, move_ver, move_base);
	base = del_glass(base);
	return (base);
}

/*
** Fonction pour choisir le bon id du sprite
*/

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
	return (spr);
}
