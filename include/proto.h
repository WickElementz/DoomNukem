/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videloff <videloff@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:42:18 by jominodi          #+#    #+#             */
/*   Updated: 2020/06/23 22:26:31 by videloff         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

/*
**	******
**	 GAME
**	******
*/

int				event_key(t_env *env);
int				hold_key(int key, t_env *env);
int				unhold_key(int key, t_env *env);
int				mouse_move(int x, int y, t_env *env);
int				mouse_hook(int click, int x, int y, t_env *env);
int				check_type(float xy[2], t_block map[50][50], char c);
int				check_key(char *key, char ref);
int				exit_hook(t_env *env);
int				get_spr_id(char c, float a);
int				init_mlx_from_edit(t_env *env);
int				draw_column2(t_env *env, t_ray *ray, int xy[3]);
int				init_mlx(t_env *env);
int				calc_damage(int dist);
void			break_glass(t_env *env, t_ray hor, t_ray ver);
void			check_gunner(t_env *env);
void			setup_door_v(t_env *env, float xy[4], float ang, t_ray **spr);
void			setup_door_h(t_env *env, float xy[4], float ang, t_ray **spr);
void			gunner_fire(t_env *env);
void			walkable_block_x(double n[2], t_block map[50][50], t_pos *cam);
void			walkable_block_z(double n[2], t_block map[50][50], t_pos *cam);
void			load_texture6(t_env *env, int a, int b);
void			parsing(char *filename, t_env *env, int fd);
void			event_mouse(t_env *env);
void			free_env(t_env *env, int set);
void			anglemove(t_pos *cam, int way);
void			free_listr(t_ray *list);
void			ft_move_z(t_block map[50][50], t_pos *cam, int way, int up[2]);
void			ft_move_x(t_block map[50][50], t_pos *cam, int way, int up[2]);
void			init_info(t_env *env);
void			usage();
void			error(int error);
void			draw_li_bu(t_env *env);
void			check_animation(t_env *env);
void			ray_multi_thread(t_env *env);
void			load_texture(t_env *env, int a, int b);
void			load_texture4(t_env *env, int a, int b);
void			load_texture7(t_env *env, int a, int b);
void			put_pxl(t_env *env, int x, int y, t_clr clr);
void			gun(t_env *env, int id);
void			print_hud(t_env *env, int id);
void			print_gun_animation(t_env *env, int id);
void			print_reload_animation(t_env *env, int id);
void			reload(t_env *env);
void			fire(t_env *env);
void			display(t_env *env);
void			check_status(t_env *env);
void			check_map(t_env *env);
void			error_valid_map(int error);
void			loop_mlx(t_env *env);
void			set_spawn(t_env *env, int x, int y);
void			draw_column(t_env *env, t_ray *ray, int xy[3]);
void			open_door(t_env *env);
void			door(t_env *env);
void			jump(t_env *env);
void			crouch_animation(t_env *env);
void			set_wall_h(float ang, t_env *env, float xy[4], t_ray *hor);
void			set_wall_v(float ang, t_env *env, float xy[4], t_ray *ver);
void			corona(t_env *env);
void			print_last_screen(t_env *env, int id);
void			give_xy_value_ver(float (*xy)[2], float ang, t_env *env);
void			set_xy(t_pos cam, float ang, float (*xy)[4], int bol);
void			*raycasting(void	*data);
void			deal_damage(t_env *env);
void			give_xy_value_hor(float (*xy)[2], float ang, t_env *env);
void			display_key(t_env *env);
void			display_trap(t_env *env);
void			display_screen(t_env *env);
float			give_value(float angle, int dif);
float			right_angle(float ang, float fang);
unsigned int	add_color2(t_env *env, t_ray *ray, int xy[3], float (*cs)[2]);
unsigned int	add_color3(t_env *env, t_ray *ray, int xy[3], float (*cs)[2]);
unsigned int	add_sprite2(t_env *env, t_ray *ray, unsigned int color);
t_clr			draw_column3(t_env *env, t_ray *ray, t_clr res, int xy[3]);
t_clr			gclr(unsigned int color, int a);
t_ray			*add_pane(float xy[4], t_env *env, float ang, int bol);
t_ray			*create_spr(float xy[4], t_env *env, float ang);
t_ray			*add_doors_h(float xy[4], t_env *env, float ang);
t_ray			*add_doors_h2(float xy[4], t_env *env, float ang);
t_ray			*add_doors_v(float xy[4], t_env *env, float ang);
t_ray			*add_doors_v2(float xy[4], t_env *env, float ang);
t_clr			add_color(t_env *env, t_ray *ray, int xy[3]);
t_clr			add_sprite(t_env *env, t_ray *ray, int xy[3]);
t_ray			*create_ray(float dist, float mod, float id);
t_ray			*sprite_list(t_ray *hor, t_ray *ver);
t_ray			*find_ver_wall(t_env *env, float ang);
t_ray			*find_hor_wall(t_env *env, float ang);

/*
**	********
**	 EDITOR
**	********
*/

int				exit_hook_editor(t_edit *edit);
int				hold_key_editor(int key, t_edit *edit);
int				mouse_hook_editor(int key, int x, int y, t_edit *edit);
int				init_mlx_editor(t_edit *edit);
int				valid_char_new(char *line);
int				open_file_editor(t_edit *edit, int fd);
void			verif_path(char *file);
void			editor(char *mode, char *file);
void			init_edit_info(t_edit *edit);
void			initialise_tab_editor(t_edit *edit);
void			load_texture_editor(t_edit *edit);
void			print_hud_editor(t_edit *edit);
void			put_pxl_editor(t_edit *edit, int x, int y, t_clr clr);
void			put_pxl_editor2(t_edit *edit, int x, int y, t_clr clr);
void			display_editor(t_edit *edit);
void			parsing_editor(char *file, t_edit *edit);
void			link_door_key_editor(t_edit *edit, int x, int y);
void			check_link_dk_editor(t_edit *edit, int s_x, int s_y, char c);
void			save_map_editor(t_edit *edit);
void			read_tab_editor(t_edit *edit);
void			fill_tab_editor(t_edit *edit);
void			check_map_editor(t_edit *edit);
void			init_verif_value(t_verif *verif);
void			error_editor(t_edit *edit, int error, int fd);
void			remove_block(int o_x, int o_y, t_edit *edit);
void			place_block(int o_x, int o_y, t_edit *edit);
void			choose_block(int x, int y, t_edit *edit);
void			loop_mlx_editor(t_edit *edit);
void			editor_to_game(t_edit *edit);
void			choose_life(t_edit *edit);
void			choose_bullet(t_edit *edit);
t_clr			gclr_editor(t_edit *edit, int x, int y);

#endif
