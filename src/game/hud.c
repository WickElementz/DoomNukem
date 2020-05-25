/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgascon <dgascon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:16:10 by jominodi          #+#    #+#             */
/*   Updated: 2020/05/25 18:13:31 by dgascon          ###   ########.fr       */
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
			clr = ((int)color != NONE) ? gclr(color, 0) : gclr(color, 255);
			put_pxl3(env, x, y, clr);
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
				put_pxl3(env, x, y, gclr(color, 0));

			}
		}
	}
}
