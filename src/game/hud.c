/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videloff <videloff@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 12:01:26 by jominodi          #+#    #+#             */
/*   Updated: 2020/06/22 14:29:22 by videloff         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	print_last_screen(t_env *env, int id)
{
	int				x;
	int				y;
	t_clr			clr;
	unsigned int	color;

	x = -1;
	while (++x < 960)
	{
		y = -1;
		while (++y < 600)
		{
			ft_memcpy(&color, &env->sprite[id].data[(x + 960 *
					y) * 4], sizeof(int));
			if (color != NONE)
			{
				clr = gclr(color, 0);
				put_pxl(env, x, y, clr);
			}
		}
	}
}

void	print_hud(t_env *env, int id)
{
	int				x;
	int				y;
	unsigned int	color;

	x = -1;
	while (++x < 960)
	{
		y = -1;
		while (++y < 600)
		{
			ft_memcpy(&color, &env->sprite[id].data[(x + 960 *
					y) * 4], sizeof(int));
			if (color != NONE)
			{
				color = (env->sick == 0) ? color : color + 23541;
				put_pxl(env, x, y, gclr(color, 0));
			}
		}
	}
}
