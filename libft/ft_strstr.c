/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanne <kanne@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 14:14:56 by videloff          #+#    #+#             */
/*   Updated: 2020/06/15 15:43:43 by kanne            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *ndl)
{
	unsigned int i;
	unsigned int o;
	unsigned int len;

	i = 0;
	o = 0;
	len = 0;
	while (ndl[len])
		len++;
	if (len == 0)
		return (&((char *)str)[i]);
	while (str[i])
	{
		while (str[i + o] == ndl[o])
		{
			if (o == len - 1)
				return (&((char *)str)[i]);
			o++;
		}
		o = 0;
		i++;
	}
	return (NULL);
}
