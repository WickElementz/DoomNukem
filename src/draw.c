/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yalabidi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/06 14:37:49 by yalabidi     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/06 14:37:50 by yalabidi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_draw(t_env *env, float view[3], int xy[2])
{
	int				wall;
	int				cmpt;
	unsigned int	color;

	wall = (64 / view[0]) * ((WIN_WIDTH / 2) / tan(FOV / 2 * M_PI / 180));
	cmpt = (wall <= WIN_HEIGHT) ? 0 : wall / 2 - WIN_HEIGHT / 2;
	while (xy[1] < WIN_HEIGHT && cmpt < wall)
	{	
		if (xy[1] < (WIN_HEIGHT - wall) / 2 && wall < WIN_HEIGHT)
			put_pxl(env, xy[0], xy[1]++, 0x3498DB);
		else
		{
			ft_memcpy(&color, &env->text[(int)view[2]].data[(((int)view[1]) + 64 * (64 * cmpt / wall)) * 4], sizeof(int));
			put_pxl(env, xy[0], xy[1]++, color);
			cmpt++;
		}
	}
	while (xy[1] < WIN_HEIGHT)
	{
		put_pxl(env, xy[0], xy[1]++, 0xE67E22);
	}
}

void		draw_floor_and_sky(t_env *env, float view[WIN_WIDTH][3], int xy[2])
{
	window_clear(env);
	while (xy[0]++ < WIN_WIDTH)
	{
		xy[1] = 0;
		ft_draw(env, view[xy[0]], xy);
	}
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
}