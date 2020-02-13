/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sprite.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/16 15:28:00 by yalabidi     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 15:37:44 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "doom_nukem.h"

t_ray	*cpy_spr(t_ray *spr)
{
	t_ray	*new;
	
	if (!(new = (t_ray*)malloc(sizeof(t_ray))))
		return (NULL);
	new->dist = spr->dist;
	new->type = spr->type;
	new->mod = spr->mod;
	new->id = spr->id;
	new->mapy = spr->mapy;
	new->mapx = spr->mapx;
	new->next = NULL;
	return (new);
}

static t_ray	*del_glass(t_ray *base)
{
	t_ray	*clean;
	t_ray	*c;
	t_ray	*b;

	clean = cpy_spr(base);
	c = clean;
	b = base;
	while (b)
	{
		while (b->next && (b->mapx - b->next->mapx <= 1 ||
			b->mapx - b->next->mapx >= -1 || 
			b->mapy - b->next->mapy <= 1 ||
			b->mapy - b->next->mapy >= -1))
			{
				b = b->next;
			}
		c->next = cpy_spr(b);
		b = b->next;
		c = c->next;
	}
	free_listr(base);
	return (clean);
}

t_ray   *sprite_list(t_ray *hor, t_ray *ver)
{
	t_ray     *move_ver;
	t_ray     *move_hor;
	t_ray     *move_base;
	t_ray     *base;

	if (!hor->next && !ver->next)
		return (NULL);
	move_ver = ver->next;
	move_hor = hor->next;
	if (move_hor && move_ver)
		base = (move_hor->dist < move_ver->dist) ? cpy_spr(move_hor) : cpy_spr(move_ver);
	else
		base = (move_hor) ? cpy_spr(move_hor) : cpy_spr(move_ver);
	move_base = base;
	while (move_hor || move_ver)
	{
		if (move_hor && move_ver)
		{
			move_base->next = (move_hor->dist > move_ver->dist) ? cpy_spr(move_ver) : cpy_spr(move_ver);
			move_ver = move_ver->next;
			move_hor = move_hor->next;
		}
		else if (!move_hor && move_ver)
		{
			move_base->next = cpy_spr(move_ver);
			move_ver = move_ver->next;
		}
		else if (move_hor && !move_ver)
		{
			move_base->next = cpy_spr(move_hor);
			move_hor = move_hor->next;
		}
		move_base = move_base->next;
	}
	base = del_glass(base);
	free_listr(hor);
	free_listr(ver);
	return (base);
}
