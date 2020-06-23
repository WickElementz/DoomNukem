/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videloff <videloff@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:41:02 by yalabidi          #+#    #+#             */
/*   Updated: 2020/06/22 14:29:22 by videloff         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	usage(void)
{
	ft_putstr("Usage: ./doom_nukem [map]\n");
	ft_putstr("Usage: ./doom_nukem edit [map]\n");
	ft_putstr("Usage: ./doom_nukem create [map]\n");
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
		ft_putstr("An error occured while the Minilibix initialization\n");
		exit(-1);
	}
}

void	error_valid_map(int error)
{
	if (error == 1)
		ft_putstr_fd(ERR_VALID_DOOR, 2);
	else if (error == 2)
		ft_putstr_fd(ERR_NUM_DK, 2);
	else if (error == 3)
		ft_putstr_fd(ERR_LINK_DK, 2);
	else if (error == 4)
		ft_putstr_fd(ERR_START, 2);
	else if (error == 5)
		ft_putstr_fd(ERR_END, 2);
	else if (error == 6)
	{
		ft_putstr_fd(ERR_WALL, 2);
		ft_putstr_fd(ERR_WALL2, 2);
	}
	else if (error == 7)
		ft_putstr_fd(ERR_SUP_DK, 2);
	ft_putchar_fd('\n', 2);
	exit(-1);
}

t_ray	*create_ray(float dist, float mod, float id)
{
	t_ray	*ray;

	if (!(ray = (t_ray*)malloc(sizeof(t_ray))))
		return (NULL);
	ray->dist = dist;
	ray->type = -1;
	ray->ang = -1;
	ray->wall = -1;
	ray->mrg = -1;
	ray->cmpt = -1;
	ray->mod = mod;
	ray->id = id;
	ray->mapy = -1;
	ray->mapx = -1;
	ray->door = -1;
	ray->next = NULL;
	return (ray);
}
