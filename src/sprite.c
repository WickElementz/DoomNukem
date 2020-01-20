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

t_ray   *sprite_list(t_ray *hor, t_ray *ver)
{
    t_ray     *move_ver;
    t_ray     *move_hor;
    t_ray     *move_base;
    t_ray     *base;

    move_ver = ver->next;
    move_hor = hor->next;
    
}