/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanne <kanne@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 15:15:08 by videloff          #+#    #+#             */
/*   Updated: 2020/06/15 15:43:43 by kanne            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *ndl, size_t n)
{
	unsigned int i;
	unsigned int o;

	if (ndl[0] == '\0')
		return ((char*)str);
	i = 0;
	while (((char*)str)[i])
	{
		if (str[i] == ndl[0])
		{
			o = 1;
			while (ndl[o] && str[i + o] == ndl[o])
				o++;
			if (ndl[o] == '\0')
			{
				if (i + o > n)
					return (NULL);
				else
					return (&((char*)str)[i]);
			}
		}
		i++;
	}
	return (NULL);
}
