/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   editor2.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/06 14:55:34 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/07 14:13:40 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "doom_nukem.h"

void			load_texture_editor(t_edit *edit)
{
	int a;
	int b;

	a = 960;
	b = 960;
	edit->spr[0].img = mlx_xpm_file_to_image(edit->mlx_ptr,
		"sprites/map_editor.xpm", &a, &b);
	edit->spr[0].data = mlx_get_data_addr(edit->spr[0].img,
		&edit->spr[0].bpp, &edit->spr[0].sl, &edit->spr[0].end);
}

void			put_pxl_editor2(t_edit *edit, int x, int y, t_clr clr)
{
	if (x >= 0 && x < 500 && y >= 0 && y < 500)
	{
		edit->data_ptr2[(y * 500 + x) * 4] = clr.b;
		edit->data_ptr2[(y * 500 + x) * 4 + 1] = clr.g;
		edit->data_ptr2[(y * 500 + x) * 4 + 2] = clr.r;
		edit->data_ptr2[(y * 500 + x) * 4 + 3] = clr.a;
	}
}

void			put_pxl_editor(t_edit *edit, int x, int y, t_clr clr)
{
	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		edit->data_ptr[(y * WIN_WIDTH + x) * 4] = clr.b;
		edit->data_ptr[(y * WIN_WIDTH + x) * 4 + 1] = clr.g;
		edit->data_ptr[(y * WIN_WIDTH + x) * 4 + 2] = clr.r;
		edit->data_ptr[(y * WIN_WIDTH + x) * 4 + 3] = clr.a;
	}
}

void			choose_block(int x, int y, t_edit *edit)
{
	const char	nom[12] = {'F', 'W', 'P', 'D', 'B', 'E',
						'L', 'A', 'G', 'Z', 'K', 'C'};
	int			secu;
	float		tmp;

	tmp = ((float)y - 82) / (float)77;
	y = (int)tmp;
	tmp -= y;
	if (tmp - 0.65 >= 0)
		return ;
	else
		secu = y;		
	edit->id = x <= 185 ? nom[secu] : nom[secu + 6];
}

int				mouse_hook_editor(int key, int x, int y, t_edit *edit)
{
	if (key == 1 && y > 82 && y < 515 && ((x > 15 && x < 185) || (x > 773 && x < 943)))
		choose_block(x, y, edit);
	else if (key == 1 && x > 229 && x < 731 && y > 49 && y < 551)
		place_block(x, y, edit);
/*	if (key == 2)// && x > && x < && y > && y < )
		remove_block(int x, int y, edit);
	*/
//	dprintf(1, "x: %d ||y: %d\n", x, y);
	display_editor(edit);
	return (0);
}

void			print_hud_editor(t_edit *edit)
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
			ft_memcpy(&color, &edit->spr[0].data[(x + 960 *
					y) * 4], sizeof(int));
			clr = ((int)color != NONE) ? gclr(color, 0) : gclr(0xFFFFFF, 255);
			put_pxl_editor(edit, x, y, clr);
		}
	}
}