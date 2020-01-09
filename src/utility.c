/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utility.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 14:43:34 by yalabidi     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/18 15:41:41 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	window_clear(t_env *env)
{
	int x;
	int y;

	x = -1;
	y = -1;
	while (++y < WIN_HEIGHT)
	{
		while (++x < WIN_WIDTH)
			put_pxl(env, x, y, 0);
		x = -1;
	}
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
}

void	put_pxl(t_env *env, int x, int y, unsigned int color)
{
	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
		env->data_ptr[y * WIN_WIDTH + x] = color;
}
