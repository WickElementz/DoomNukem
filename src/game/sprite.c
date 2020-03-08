/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videloff <videloff@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 15:28:00 by yalabidi          #+#    #+#             */
/*   Updated: 2020/03/04 14:53:06 by videloff         ###   ########lyon.fr   */
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

/*
** Modif l 56 c = c->next
*/

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
		if (b->next && b->next->id == 6 && c->id == 6 && ((b->mapx - b->next->mapx >= -1 && b->mapx -
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
	base = del_glass(base);
	return (base);
}

t_ray	*create_spr(float xy[4], t_env *env, float ang)
{
	t_ray	*spr;
	float	poscer[3];

	spr = create_ray(sqrt(pow(env->cam.x - ((int)(xy[1] / 64) * 64 + 32) , 2) +
		pow(env->cam.y - ((int)(xy[0] / 64) * 64 + 32) , 2)), 0, 7);
	poscer[0] = (env->cam.y - ((int)(xy[0] / 64) * 64 + 32)) / spr->dist;
	poscer[1] = (env->cam.x - ((int)(xy[1] / 64) * 64 + 32)) / spr->dist;
	poscer[2] = right_angle(ang, atan(poscer[0] / poscer[1]) * 180 / M_PI);
	spr->mod = 32 - spr->dist * tan((ang - poscer[2]) * M_PI / 180);
	spr->mod = (spr->mod >= 64 || spr->mod < 0) ? 0 : spr->mod; 
	spr->mapx = (int)xy[0] / 64;
	spr->mapy = (int)xy[1] / 64;
	spr->type = 2;
	/* fonction pour choisir le bon id du sprite */
	return (spr);
}

t_ray	*add_doors(float xy[4], t_env *env, float ang, int bol)
{
	t_ray	*door;

	door = create_ray(sqrt(pow(env->cam.y -
		(int)(xy[0] + xy[2] / 2), 2) + pow(env->cam.x -
		(int)(xy[1] + xy[3] / 2), 2)) * cos((ang - env->cam.angle)
		* RAD), (int)(xy[1] + xy[3] / 2) % 64, 4);
	if (bol == 1)
		door->mod = (int)(xy[0] + xy[2] / 2) % 64;
	door->door = (int)env->map[(int)xy[1] / 64][(int)xy[0] /
		64].id - 60;
	door->type = 3;
	door->mapx = (int)xy[0] / 64;
	door->mapy = (int)xy[1] / 64;
	return (door);
}

t_ray	*add_pane(float xy[4], t_env *env, float ang, int bol)
{
	t_ray	*pane;

	pane = create_ray(sqrt(pow(env->cam.y - (int)xy[0], 2) +
		pow(env->cam.x -(int)xy[1], 2)) * cos((ang - env->cam.angle)
		* RAD), (int)xy[1] % 64, 6);
	if (bol == 1)
		pane->mod = (int)xy[0] % 64;
	pane->type = 1;
	pane->mapx = (int)xy[0] / 64;
	pane->mapy = (int)xy[1] / 64;
	return (pane);
}

void	set_xy(t_position cam, float ang, float (*xy)[4], int bol)
{
	if (bol == 0)
	{
		(*xy)[0] = (ang > 270 || ang < 90) ?
			(int)(cam.y / 64) * 64 + 64 : (int)(cam.y / 64) * 64 - 1;
		(*xy)[1] = (ang > 270 || ang < 90) ?
			cam.x - (cam.y - (*xy)[0]) * tan(ang * RAD) :
				cam.x - (cam.y - ((*xy)[0] + 1)) * tan(ang * RAD);
		(*xy)[3] = give_value(ang, 1);
		(*xy)[2] = (ang > 270 || ang < 90) ? 64 : -64;
	}
	if (bol == 1)
	{
		(*xy)[1] = (ang < 180) ? (int)(cam.x / 64) * 64 + 64 :
			(int)(cam.x / 64) * 64 - 1;
		(*xy)[0] = (ang < 180) ? cam.y - (cam.x - (*xy)[1]) /
			tan(ang * RAD) : cam.y - (cam.x - ((*xy)[1] + 1)) /
				tan(ang * RAD);
		(*xy)[2] = give_value(ang, 2);
		(*xy)[3] = (ang < 180) ? 64 : -64;	
	}
}

void	set_wall_h(float ang, t_position cam, float xy[4], t_ray *hor)
{
	hor->id = (ang < 180) ? 0 : 2;
	hor->dist = sqrt(pow(cam.y - (int)xy[0], 2) + pow(cam.x -
		(int)xy[1], 2)) * cos((ang - cam.angle) * RAD);
	hor->mod = (int)xy[0] % 64;
}

void	set_wall_v(float ang, t_position cam, float xy[4], t_ray *ver)
{
	ver->id = (ang < 90 || ang > 270) ? 1 : 3;
	ver->dist = sqrt(pow(cam.y - (int)xy[0], 2) + pow(cam.x -
		(int)xy[1], 2)) * cos((ang - cam.angle) * RAD);
	ver->mod = (int)xy[1] % 64;
}