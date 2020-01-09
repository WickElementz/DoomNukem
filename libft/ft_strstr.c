/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: videloff <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 14:14:56 by videloff     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/10 15:14:06 by videloff    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
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
