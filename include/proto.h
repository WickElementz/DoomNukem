/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   proto.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 16:15:16 by videloff     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/11 14:27:43 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

/*
** GAME
*/

int			parsing(char *file, t_env *env);
int			set_line(char *line, int z, t_env *env, int len);
int			set_angle(t_env *env, int x);
int			event_key(t_env *env);
int			hold_key(int key, t_env *env);
int			unhold_key(int key, t_env *env);
int			mouse_move(int x, int y, t_env *env);
int			mouse_hook(int click, int x, int y, t_env *env);
int	    	gun_phase(t_env *env, int (*xy)[6]);
void		event_mouse(t_env *env);
void		free_env(t_env *env, int set);
void		anglemove(t_position *cam, int way);
void		ft_move_z(t_block **map, t_position *cam, int way, int max[2]);
void		free_listr(t_ray *list);
void		free_listc(t_clr *list);
void		ft_move_x(t_block **map, t_position *cam, int way, int max[2]);
void		init_info(t_env *env);
void		usage();
void		error(int error);
void        draw_hud(t_env *env);
void		load_texture(t_env *env);
void		put_pxl(t_env *env, int x, int y, t_clr clr);
void		put_pxl2(t_env *env, int x, int y, t_clr clr);
void		put_pxl3(t_env *env, int x, int y, t_clr clr);
void		gun(t_env *env, int id);
void		print_hud(t_env *env, int id);
void    	add_end_lst(t_ray *base, t_ray *new);
void		print_gun_animation(t_env *env, int id);
void		print_reload_animation(t_env *env, int id);
void        reload(t_env *env);
void        fire(t_env *env);
void        display(t_env *env);
void        check_status(t_env *env);
t_ray       *sprite_list(t_ray *hor, t_ray *ver);
t_clr	    gclr(unsigned int color, int a);
t_clr		add_color(t_env *env, t_ray *ray, int xy[3]);
t_clr		add_sprite(t_env *env, t_ray *ray, int xy[3]);
t_ray       *create_ray(float dist, float mod, float id);
void	    *raycasting(void *data);
void		draw_column(t_env *env, t_ray *ray, int xy[3]);

/*
** EDITOR
*/

int         hold_key_editor(int key, t_edit *edit);
int         mouse_hook_editor(int key, int x, int y, t_edit *edit);
int			init_mlx_editor(t_edit *edit);
void        editor(char *file, int ac);
void	    init_edit_info(t_edit *edit);
void		initialise_tab(t_edit *edit);
void		load_texture_editor(t_edit *edit);
void		print_hud_editor(t_edit *edit);
void        put_pxl_editor(t_edit *edit, int x, int y, t_clr clr);
void        put_pxl_editor2(t_edit *edit, int x, int y, t_clr clr);
void		display_editor(t_edit *edit);
void        parsing_editor(char *file, t_edit *edit);
void	    save_map(t_edit *edit);
t_clr       get_color(t_edit *edit, int x, int y);

#endif
