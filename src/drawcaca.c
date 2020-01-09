/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 13:14:05 by videloff     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/19 12:28:43 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

static void		split_pix(int (*wmmi)[5])
{
	int remain;
	int mult;

	mult = (*wmmi)[0] / 64;
	remain = (*wmmi)[0] % 64;
	if (remain == 0)
	{
		(*wmmi)[2] = mult;
		(*wmmi)[3] = 0;
		(*wmmi)[4] = 3;
	}
	else if (remain > 32)
	{
		(*wmmi)[2] = (*wmmi)[0] / 64 + 1;
		(*wmmi)[3] = 64 / (64 - remain) + 1;
		(*wmmi)[4] = 1;
	}
	else
	{
		(*wmmi)[2] = (*wmmi)[0] / 64;
		(*wmmi)[3] = 64 / remain + 1;
		(*wmmi)[4] = -1;
	}
}


static int		draw_wall(t_env *env, float view[WIN_WIDTH][3], int xy[2], int (*wmmi)[5])
{
	int mult;
	int line;
	int iter;
	unsigned int color;
	
	line = (*wmmi)[0] > WIN_HEIGHT ? 32 - (WIN_HEIGHT / 2 / (*wmmi)[2]) - 1 : 0;
	split_pix(wmmi);
 	dprintf(1, "col: %d || wallh: %d || multb: %d || iter: %d\n", xy[0], (*wmmi)[0], (*wmmi)[2], (*wmmi)[3]);
//	dprintf(1, "%d\n", xy[1]);
	while (xy[1] < ((*wmmi)[0] + (*wmmi)[1]) && xy[1] < WIN_HEIGHT)
	{
//		dprintf(1, "%d <= %d\n", xy[1], (*wmmi)[0] + (*wmmi)[1]);
		iter = 0;
		while (((iter < (*wmmi)[3] || (*wmmi)[4] == 3) && xy[1] < ((*wmmi)[0] + (*wmmi)[1]) && xy[1] < WIN_HEIGHT))
		{
			mult = 0;
			ft_memcpy(&color, &env->text[(int)view[xy[0]][2]].data[((int)view[xy[0]][1] + (64 * line)) * 4], sizeof(int));
			while (mult++ < (*wmmi)[2] && xy[1] < ((*wmmi)[0] + (*wmmi)[1]) && xy[1] < WIN_HEIGHT)
			{
				if (xy[1] < WIN_HEIGHT && xy[1] >= 0)
					put_pxl(env, xy[0], xy[1], color);
				xy[1]++;
			}
			iter++;
			line++;
		}
		if ((*wmmi)[4] != 3 && xy[1] < ((*wmmi)[0] + (*wmmi)[1]) && xy[1] < WIN_HEIGHT)
		{
			mult = (*wmmi)[4];
			ft_memcpy(&color, &env->text[(int)view[xy[0]][2]].data[((int)view[xy[0]][1] + (64 * line)) * 4], sizeof(int));
			while (mult++ < (*wmmi)[2] && xy[1] < ((*wmmi)[0] + (*wmmi)[1]) && xy[1] < WIN_HEIGHT)
			{
				if (xy[1] < WIN_HEIGHT && xy[1] >= 0)
					put_pxl(env, xy[0], xy[1], color);
				xy[1]++;
			}
			line++;
		}
	}
	return (xy[1]);
}

/*
** w = wall hauteur du mur dans l'univers
** m = marge
** m = mult nb e pixel fixe
**	{
**		wall / 64
**	}
** i = iteration
**	{
**		if (remain > 32)
**			-1px
**		if (remain > 32)
**			+1px
**	}
*/

void			draw_floor_and_sky(t_env *env, float view[WIN_WIDTH][3], int xy[2])
{
	int wmmi[5];

	//window_clear(env);
	while (++xy[0] < WIN_WIDTH)
	{
		if (view[xy[0]][0] == 0)
			wmmi[0] = WIN_HEIGHT;
		else
			wmmi[0] = round((SCREEN * BLOCK) / (view[xy[0]][0] * cos((-30 + (((double)FOV / (double)WIN_WIDTH) * xy[0])) * M_PI / 180)));
		wmmi[1] = wmmi[0] >= WIN_HEIGHT ? 0 : (WIN_HEIGHT - wmmi[0]) / 2;
		while (xy[1] < wmmi[1])
			put_pxl(env, xy[0], xy[1]++, 0x3498DB);
		xy[1] = draw_wall(env, view, xy, &wmmi);
		while (xy[1] < WIN_HEIGHT)
			put_pxl(env, xy[0], xy[1]++, 0xE67E22);
		xy[1] = 0;
	}
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
}
