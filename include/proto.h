/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   proto.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 16:15:16 by videloff     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/18 15:40:37 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

int			valid_char(char *str, int x, t_env *env);
int			parsing(char *file, t_env *env);
int			valid_map(t_block **map, int z, int x);
int			second_open(char *name, t_env *env);
int			first_open(char *name, t_env *env, int x, int fd);
int     	set_line(char *line, int z, t_env *env, int len);
int 	    set_angle(t_env *env, int x);
int		    event_key(t_env *env);
int		    hold_key(int key, t_env *env);
int		    unhold_key(int key, t_env *env);
void		anglemove(t_position *cam, int way);
void		ft_move_z(t_block **map, t_position *cam, int way, int max[2]);
void		ft_move_x(t_block **map, t_position *cam, int way, int max[2]);
void		set_map_null(t_env *env);
void    	free_env(t_env *env);
void		init_info(t_env *env);
void		usage();
void		error(int error);
void    	load_texture(t_env *env);
void	    put_pxl(t_env *env, int x, int y, unsigned int color);
void	    window_clear(t_env *env);
void        raycasting(t_env *env);
void		draw_floor_and_sky(t_env *env, float view[WIN_WIDTH][3], int xy[2]);
#endif
