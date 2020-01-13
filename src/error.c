/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/18 15:41:02 by yalabidi     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/13 12:54:36 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "doom_nukem.h"

void	usage(void)
{
	ft_putstr("Usage: ./wolf3d [map]\n");
	ft_putstr("You can only use one map which are located in \"./map/\"\n");
	exit(-1);
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
	if (error == 4)
	{
		ft_putstr("An error occured while the Mnilibix initialization\n");
		exit(-1);
	}
}
