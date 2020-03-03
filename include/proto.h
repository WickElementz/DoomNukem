/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videloff <videloff@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:42:18 by jominodi          #+#    #+#             */
/*   Updated: 2020/03/02 15:07:08 by videloff         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

/*	
**	******
**	 GAME
**	******
*/

int			set_line(char *line, int z, t_env *env, int len);
void		ray_multi_thread(t_env *env);
int			set_angle(t_env *env, int x);
int			event_key(t_env *env);
int			hold_key(int key, t_env *env);
int			unhold_key(int key, t_env *env);
int			mouse_move(int x, int y, t_env *env);
int			mouse_hook(int click, int x, int y, t_env *env);
int			gun_phase(t_env *env, int (*xy)[6]);
int         exit_hook(t_env *env);
void   		walkable_block_x(double n[2], t_block map[50][50], t_position *cam);
void		walkable_block_z(double n[2], t_block map[50][50], t_position *cam);
void		parsing(char *filename, t_env *env, int fd);
void		event_mouse(t_env *env);
void		free_env(t_env *env, int set);
void		anglemove(t_position *cam, int way);
void		free_listr(t_ray *list);
void		free_listc(t_clr *list);
void		ft_move_z(t_block map[50][50], t_position *cam, int way, int up[2]);
void		ft_move_x(t_block map[50][50], t_position *cam, int way, int up[2]);
void		init_info(t_env *env);
void		usage();
void		error(int error);
void		draw_hud(t_env *env);
void		load_texture(t_env *env);
void		put_pxl(t_env *env, int x, int y, t_clr clr);
void		put_pxl2(t_env *env, int x, int y, t_clr clr);
void		put_pxl3(t_env *env, int x, int y, t_clr clr);
void		gun(t_env *env, int id);
void		print_hud(t_env *env, int id);
void		add_end_lst(t_ray *base, t_ray *new);
void		print_gun_animation(t_env *env, int id);
void		print_reload_animation(t_env *env, int id);
void		reload(t_env *env);
void		fire(t_env *env);
void		display(t_env *env);
void		check_status(t_env *env);
void		check_map(t_env *env);
void        error_valid_map(t_env *env, int error);
void		loop_mlx(t_env *env);
void		set_spawn(t_env *env, int x, int y);
void	    game_to_editor(t_env *env);
void		draw_column(t_env *env, t_ray *ray, int xy[3]);
void		open_door(t_env *env);
void    	door(t_env *env);
void        jump(t_env *env);
void	    crouch_animation(t_env *env);
void	    corona(t_env *env);
void	    z_after_coro(t_env *env);
void		print_last_screen(t_env *env, int id);
float		give_value(float angle, int dif);
void    	deal_damage(t_env *env);
int		    init_mlx(t_env *env);
void        *raycasting(void	*data);
t_ray       *sprite_list(t_ray *hor, t_ray *ver);
t_clr	    gclr(unsigned int color, int a);
t_clr		add_color(t_env *env, t_ray *ray, int xy[3]);
t_clr		add_sprite(t_env *env, t_ray *ray, int xy[3]);
t_ray		*create_ray(float dist, float mod, float id);

/*
**	********
**	 EDITOR
**	********
*/

int         exit_hook_editor(t_edit *edit);
int			hold_key_editor(int key, t_edit *edit);
int			mouse_hook_editor(int key, int x, int y, t_edit *edit);
int			init_mlx_editor(t_edit *edit);
int			valid_char_new(char *line);
int			open_file_editor(t_edit *edit, int fd);
void		editor(char *mode, char *file);
void		init_edit_info(t_edit *edit);
void		initialise_tab_editor(t_edit *edit);
void		load_texture_editor(t_edit *edit);
void		print_hud_editor(t_edit *edit);
void		put_pxl_editor(t_edit *edit, int x, int y, t_clr clr);
void		put_pxl_editor2(t_edit *edit, int x, int y, t_clr clr);
void		display_editor(t_edit *edit);
void		parsing_editor(char *file, t_edit *edit);
void		link_door_key_editor(t_edit *edit, int x, int y);
void		check_link_dk_editor(t_edit *edit, int save_x, int save_y, char c);
void		save_map_editor(t_edit *edit);
void		read_tab_editor(t_edit *edit);
void		fill_tab_editor(t_edit *edit);
void		check_map_editor(t_edit *edit);
void		init_verif_value(t_verif *verif);
void		error_editor(t_edit *edit, int error);
void		remove_block(int o_x, int o_y, t_edit *edit);
void		place_block(int o_x, int o_y, t_edit *edit);
void		choose_block(int x, int y, t_edit *edit);
void        loop_mlx_editor(t_edit *edit);
void	    editor_to_game(t_edit *edit);

t_clr		gclr_editor(t_edit *edit, int x, int y);

#endif
