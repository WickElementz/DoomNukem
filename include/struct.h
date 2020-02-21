/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jominodi <jominodi@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 11:09:49 by videloff          #+#    #+#             */
/*   Updated: 2020/02/21 13:01:52 by jominodi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <pthread.h>

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
	char			id;
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
	double			z;
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
	int				end;
	int				sl;
}					t_texture;

typedef struct		s_sprite
{
	void			*img;
	char			*data;
	int				bpp;
	int				end;
	int				sl;
}					t_sprite;

typedef struct		s_clr
{
	int				r;
	int				g;
	int				b;
	int				a;
}					t_clr;

typedef struct		s_gun
{
	int				obj;
	int				time;
	int				id;
	t_sprite		spr[8];
}					t_gun;

typedef struct		s_reload
{
	int				time;
	int				id;
	t_sprite		spr[6];
}					t_reload;

typedef struct		s_verif
{
	int				beginning;
	int				ending;
	int				door;
	int				key;
	int				ver_door;
	int				err;
}					t_verif;

typedef struct		s_player
{
	int				life;
	int				ammo;
	int				r_ammo;
	int				keyid;
	char			*key;
}					t_player;


typedef	struct		s_env
{
	int				up;
	int				bpp;
	int				endian;
	int				size_line;
	int				size_x;
	int				sick;
	int				p_health;
	int				num_key;
	int				num_door;
	int				link_dk;
	int				ammo;
	int				r_ammo;
	int				win;
	int				clock;
	int				editor;
	unsigned long	t;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	void			*img_ptr2;
	void			*img_ptr3;
	char			*data_ptr;
	char			*data_ptr2;
	char			*data_ptr3;
	char			*filename;
	t_player		player;
	t_reload		reload;
	t_gun			gun;
	t_verif			verif;
	t_block			map[50][50];
	t_position		cam;
	t_event			ev;
	t_texture		text[8];
	t_sprite		sprite[5];
}					t_env;

typedef struct 		s_thread
{
	pthread_t		t;
	short			start;	
	short			end;
	t_env			*env;
}					t_thread;

typedef struct 		s_edit
{
	int				bpp;
	int				end;
	int				sl;
	int				tmpx;
	int				tmpy;
	int				mapx;
	int				mapy;
	int				zoom;
	int				size_x;
	int				size_y;
	int				num_key;
	int				num_door;
	int				link_door;
	int				link_dk;
	int				write;
	unsigned int	color;
	char			id;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img;
	char			*data;
	void			*img_ptr;
	void			*img_ptr2;
	char			*data_ptr;
	char			*data_ptr2;
	char			*filename;
	t_block			map[50][50];
	t_verif			verif;
	t_sprite		spr[1];
}					t_edit;


#endif
