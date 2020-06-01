/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jominodi <jominodi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 11:09:49 by videloff          #+#    #+#             */
/*   Updated: 2020/06/01 12:03:03 by jominodi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <pthread.h>

/*
**	*********
**	 TOUCHES
**	*********
*/

typedef struct		s_event
{
	short			forward;
	short			back;
	short			s_left;
	short			s_right;
	short			left;
	short			right;
	short			m_left;
	short			m_right;
	short			m_up;
	short			m_down;
	short			hp_down;
	short			uparrow;
	short			downarrow;
	short			walk;
	short			run;
	short			escape;
	short			space;
}					t_event;

/*
**	********
**	 CAMERA
**	********
*/

typedef struct		s_position
{
	double			x;
	double			y;
	int				speed;
	double			angle;
	double			z;
}					t_pos;

typedef struct		s_ray
{
	int				type;
	float			dist;
	float			mod;
	float			id;
	float			ang;
	int				wall;
	int				door;
	int				cmpt;
	int				mrg;
	int				mapy;
	int				mapx;
	struct s_ray	*next;
}					t_ray;

/*
**	************
**	 RESSOURCES
**	************
*/

typedef struct		s_block
{
	char			type;
	char			id;
}					t_block;

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

/*
**	****************
**	 EDITEUR DE MAP
**	****************
*/

typedef struct		s_verif
{
	short			beginning;
	short			ending;
	short			door;
	short			key;
	short			ver_p_we;
	short			ver_p_sn;
	short			ver_door;
	short			err;
}					t_verif;

typedef struct		s_edit
{
	int				bpp;
	int				end;
	int				sl;
	short			test_kd;
	short			state;
	short			tmpx;
	short			tmpy;
	short			mapx;
	short			mapy;
	short			zoom;
	short			size_x;
	short			size_y;
	short			num_key;
	short			num_door;
	short			link_door;
	short			save_dx;
	short			save_dy;
	unsigned int	color;
	char			id;
	char			link_dk;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img;
	char			*data;
	void			*img_ptr;
	char			*data_ptr;
	char			*filename;
	t_block			map[50][50];
	t_verif			verif;
	t_sprite		spr[1];
}					t_edit;

/*
**	*****
**	 JEU
**	*****
*/

typedef struct		s_player
{
	short			life;
	short			ammo;
	short			stock;
	short			keyid;
	short			corona;
	char			key[10];
}					t_player;

typedef struct		s_clr
{
	int				r;
	int				g;
	int				b;
	int				a;
}					t_clr;

typedef struct		s_gun
{
	short			obj;
	int				time;
	short			id;
	t_sprite		spr[8];
}					t_gun;

typedef struct		s_reload
{
	int				time;
	short			id;
	t_sprite		spr[6];
}					t_reload;

typedef	struct		s_env
{
	int				up;
	int				bpp;
	int				endian;
	int				size_line;
	int				size_x;
	short			num_key;
	short			num_door;
	short			door_x;
	short			door_y;
	short			sick;
	short			link_dk;
	short			door_id;
	short			jump;
	short			crouch_id;
	short			clock;
	short			coro_clock;
	short			win;
	short			gunner_id;
	short			after_coro;
	float			cone;
	float			xa;
	float			ya;
	float			xa2;
	float			ya2;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*data_ptr;
	clock_t			t;
	clock_t			t2;
	clock_t			t3;
	t_player		player;
	t_reload		reload;
	t_gun			gun;
	t_verif			verif;
	t_block			map[50][50];
	t_pos			cam;
	t_event			ev;
	t_texture		text[13];
	t_sprite		sprite[4];
}					t_env;

/*
**	****************
**	 MULTITHREADING
**	****************
*/

typedef struct		s_thread
{
	pthread_t		t;
	short			start;
	short			end;
	t_env			*env;
}					t_thread;

#endif
