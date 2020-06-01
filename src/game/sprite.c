/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jominodi <jominodi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 15:28:00 by yalabidi          #+#    #+#             */
/*   Updated: 2020/06/01 11:02:51 by jominodi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

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

int				get_spr_id(char c)
{
	if (c == 'L')
		return (7);
	if (c == 'G')
		return (12);
	if (c == 'A')
		return (8);
	if (c == 'C')
		return (11);
	if (c == 'Z')
		return (0);
	if (c == 'K')
		return (10);
	else
		return (0);
}
