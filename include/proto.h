/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   proto.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: videloff <videloff@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 16:15:16 by videloff     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/23 14:55:33 by videloff    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

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
void		ft_move_x(t_block **map, t_position *cam, int way, int max[2]);
void		init_info(t_env *env);
void		usage();
void		error(int error);
void        draw_hud(t_env *env);
void		load_texture(t_env *env);
void	    load_texture5(t_env *env, int a, int b);
void		put_pxl(t_env *env, int x, int y, t_clr clr);
void		print_bullet(t_env *env, int xy[6], int id, int tmp);
void		bullet(t_env *env, int xy[6], int id);
void		gun(t_env *env, int id, int xy[6]);
t_spr       *sprite_list(t_ray *hor, t_ray *ver);
t_spr   	*create_spr(float dist, float mod, int mapy, int mapx);
t_clr	    gclr(unsigned int color);
t_clr	    gclra(unsigned int color);
t_ray       *create_ray(float dist, float mod, float id);
void		raycasting(t_env *env);
void		draw_column(t_env *env, t_ray *ray, int xy[3]);

#endif
