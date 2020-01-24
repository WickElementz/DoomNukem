/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/01 11:09:49 by videloff     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/24 15:17:07 by jominodi    ###    #+. /#+    ###.fr     */
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
	int				m_left;
	int				m_right;
	int				m_up;
	int				m_down;
	int				hp_down;
	int				uparrow;
	int				downarrow;
	int				walk;
	int				run;
	int				escape;
	int				win;
	int				space;
}					t_event;

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

typedef struct		s_ray
{
	int				type;
	float			dist;
	float			mod;
	float			id;
	float			ang;
	int				wall;
	int				cmpt;
	int				mrg;
	int				mapy;
	int				mapx;
	struct s_ray	*next;
}					t_ray;

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

typedef struct		s_sprite
{
	void			*img;
	char			*data;
	int				bpp;
	int				endian;
	int				size_line;
}					t_sprite;

typedef struct		s_clr
{
	int				r;
	int				g;
	int				b;
	int				a;
}					t_clr;

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
	int				y;
	int				up;
	int				y_max;
	int				bpp;
	int				sick;
	int				endian;
	int				size_line;
	int				k_ev;
	int				p_health;
	int				ammo;
	int				r_ammo;
	int				phase;
	int				win;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*data_ptr;
	void			*img_ptr2;
	char			*data_ptr2;
	void			*img_ptr3;
	char			*data_ptr3;
	t_block			**map;
	t_position		cam;
	t_event			ev;
	t_texture		text[7];
	t_sprite		sprite[13];
}					t_env;

#endif
