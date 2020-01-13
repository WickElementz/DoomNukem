/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: videloff <videloff@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/01 11:09:49 by videloff     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/09 16:22:01 by videloff    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct		s_event
{
	int				forward;
	int				back;
	int				s_left;
	int				s_right;
	int				left;
	int				right;
	int				run;
	int				walk;
	int				escape;
}					t_event;

typedef struct		s_rect
{
	int				x;
	int				y;
	int				w;
	int				h;
}					t_rect;

typedef struct		s_surface
{
	int				w;
	int				h;
	void			*pixels;
	t_rect			*boomer;
}					t_surface;

/*
**	type		= mur / sol / void / end
**	txtr		= texture de mur / sol
*/

typedef struct		s_block
{
	char			type;
	char			txtr;
}					t_block;

/*
**	position de la camera
*/

typedef struct		s_position
{
	double			x;
	double			y;
	int				speed;
	double			angle;
}					t_position;

/*
** Structure de texture
*/

typedef struct		s_texture
{
	void			*img;
	char			*data;
	int				bpp;
	int				endian;
	int				size_line;
}					t_texture;

/*
**	map_y_max	= Ligne la plus longue
**	map_x_max	= colonne la plus grande
**	w_mini		= nombre de mur minimum
**	f_mini		= nombre de floor minimum
*/

typedef	struct		s_env
{
	int				map_y_max;
	int				map_x_max;
	int				f_mini;
	int				tn;
	int				ts;
	int				to;
	int				te;
	int				y;
	int				caca;
	int				y_max;
	int				bpp;
	int				endian;
	int				size_line;
	int				k_ev;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	unsigned int	*data_ptr;
	t_block			**map;
	t_position		cam;
	t_event			ev;
	t_texture		text[6];
}					t_env;

#endif
