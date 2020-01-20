/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sprite.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yalabidi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/16 15:28:00 by yalabidi     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/16 15:28:02 by yalabidi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "doom_nukem.h"

t_spr	*cpy_spr(t_spr *spr)
{
	t_spr	*new;
	
	if (!(new = (t_spr*)malloc(sizeof(t_spr))))
		return (NULL);
	new->dist = spr->dist;
	new->mod = spr->mod;
	new->id = spr->id;
	new->mapy = spr->mapy;
	new->mapx = spr->mapx;
	new->next = NULL;
	return (new);
}

t_spr   *sprite_list(t_ray *hor, t_ray *ver)
{
    t_spr     *move_ver;
    t_spr     *move_hor;
    t_spr     *move_base;
    t_spr     *base;

    if (!hor->next && !ver->next)
        return (NULL);
    move_ver = ver->next;
    move_hor = hor->next;
    base = create_spr(0, 0, 0, 0);
    move_base = base;
    while (move_hor || move_ver)
    {
        if ((move_hor->dist < move_ver->dist) || (!move_ver && move_hor))
        {
            move_base = cpy_spr(move_hor);
            move_hor = move_hor->next;
        }
        else if ((move_hor->dist > move_ver->dist) || (!move_hor && move_ver))
        {
            move_base = cpy_spr(move_ver);
            move_ver = move_ver->next;
        }
        move_base = move_base->next;
    }
    return (base);
}