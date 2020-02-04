/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/24 12:58:17 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/30 12:46:15 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "doom_nukem.h"

t_clr			gclr(unsigned int color, int a)
{
	t_clr	clr;

	clr.r = (color & 0xFF0000) >> 16;
	clr.g = (color & 0x00FF00) >> 8;
	clr.b = (color & 0x0000FF);
	clr.a = a;
	return (clr);
}

void			put_pxl(t_env *env, int x, int y, t_clr clr)
{
	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		env->data_ptr[(y * WIN_WIDTH + x) * 4] = clr.b;
		env->data_ptr[(y * WIN_WIDTH + x) * 4 + 1] = clr.g;
		env->data_ptr[(y * WIN_WIDTH + x) * 4 + 2] = clr.r;
		env->data_ptr[(y * WIN_WIDTH + x) * 4 + 3] = clr.a;
	}
}

void			put_pxl2(t_env *env, int x, int y, t_clr clr)
{
	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		env->data_ptr2[(y * WIN_WIDTH + x) * 4] = clr.b;
		env->data_ptr2[(y * WIN_WIDTH + x) * 4 + 1] = clr.g;
		env->data_ptr2[(y * WIN_WIDTH + x) * 4 + 2] = clr.r;
		env->data_ptr2[(y * WIN_WIDTH + x) * 4 + 3] = clr.a;
	}
}

void			put_pxl3(t_env *env, int x, int y, t_clr clr)
{
	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		env->data_ptr3[(y * WIN_WIDTH + x) * 4] = clr.b;
		env->data_ptr3[(y * WIN_WIDTH + x) * 4 + 1] = clr.g;
		env->data_ptr3[(y * WIN_WIDTH + x) * 4 + 2] = clr.r;
		env->data_ptr3[(y * WIN_WIDTH + x) * 4 + 3] = clr.a;
	}
}