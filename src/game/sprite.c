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
	new->mod = spr->mod;
	new->id = spr->id;
	new->mapy = spr->mapy;
	new->mapx = spr->mapx;
	new->next = NULL;
	return (new);
}

void	add_end_lst(t_ray *base, t_ray *new)
{
	while (base->next)
		base = base->next;
	base->next = new;
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
			if (move_hor->dist > move_ver->dist)
			{
				move_base->next = cpy_spr(move_ver);
				move_ver = move_ver->next;
			}
			else 
			{
				move_base->next = cpy_spr(move_hor);
				move_hor = move_hor->next;
			}
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
	free_listr(hor);
	free_listr(ver);
	return (base);
}
