/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fire.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: videloff <videloff@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/22 15:29:10 by videloff     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 15:50:01 by videloff    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "doom_nukem.h"

void	reload_animation(t_env *env)
{

}

void	fire_animation(t_env *env)
{

}

int		mouse_hook(int key, t_env *env)
{
	if (key == LEFT_CLIC && env->ammo > 0)
		fire_animation(env);
	else if (key == LEFT_CLIC && env->ammo == 0 && env->r_ammo > 0)
		reload_animation(env);
	if (key == RELOAD && env->r_ammo > 0)
		reload_animation(env);	else
	return (0);
}
