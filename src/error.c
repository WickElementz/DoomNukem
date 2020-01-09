/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/18 15:41:02 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/18 15:41:27 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

void	usage(void)
{
	ft_putstr("Usage: ./wolf3d [map]\n");
	ft_putstr("You can only use one map which are located in \"./map/\"\n");
	exit(-1);
}

void	free_env(t_env *env)
{
	while (env->map_x_max >= 0)
		free(env->map[env->map_x_max--]);
	free(env->map);
	exit(0);
}

void	error(int error)
{
	if (error == 1)
	{
		ft_putstr("An error occured while trying to open or read the file.\n");
		ft_putstr("Please check the chmod or the existance of the file\n");
		exit(-1);
	}
	if (error == 2)
	{
		ft_putstr("Syntax error in the map file\n");
		exit(-1);
	}
	if (error == 3)
	{
		ft_putstr("A malloc error occured\n");
		exit(-1);
	}
}

void	error2(int error)
{
	if (error == 1)
		ft_putstr("An error occurred. brick.xpm file failed.\n");
	else if (error == 2)
		ft_putstr("An error occurred. brick2.xpm file failed.\n");
	else if (error == 3)
		ft_putstr("An error occurred. concrete.xpm file failed.\n");
	else if (error == 4)
		ft_putstr("An error occurred. wood.xpm file failed.\n");
	ft_putstr("Please check the file validity before retrying.\n");
	exit(-1);
}
