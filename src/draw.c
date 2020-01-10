/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 13:14:05 by videloff     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/10 15:37:50 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "doom_nukem.h"

static void		put_pxl(t_env *env, int x, int y, unsigned int color)
{
	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
		env->data_ptr[y * WIN_WIDTH + x] = color;
}

static void		draw(t_env *env, float view[3], int xy[2])
{
	int				wall;
	int				cmpt;
	unsigned int	color;
	int mrg;

	wall = (64 / view[0]) * ((WIN_WIDTH / 2) / tan(FOV / 2 * M_PI / 180));
	cmpt = (wall <= WIN_HEIGHT) ? 0 : wall / 2 - WIN_HEIGHT / 2;
	xy[1] = (wall <= WIN_HEIGHT) ? (WIN_HEIGHT - wall) / 2 : 0;
	mrg = wall + xy[1];
	while (xy[1] < WIN_HEIGHT && cmpt < wall)
	{
		ft_memcpy(&color, &env->text[(int)view[2]].data[(((int)view[1]) +
					64 * (64 * cmpt / wall)) * 4], sizeof(int));
		put_pxl(env, xy[0], xy[1]++, color);
		cmpt++;
	}
	while (xy[1] < WIN_HEIGHT)
	{
		put_pxl(env, xy[0], xy[1], 0x95671F);
		put_pxl(env, xy[0], xy[1] - mrg, 0x308FC9);
		xy[1]++;
	}
}

void			draw_column(t_env *env, float view[WIN_WIDTH][3], int xy[2])
{
//	dprintf(1, "%f\n", env->cam.angle);
	while (++xy[0] < WIN_WIDTH)
	{
		xy[1] = 0;
		draw(env, view[xy[0]], xy);
	}
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
}
