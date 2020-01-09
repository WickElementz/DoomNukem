/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: videloff <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 13:44:04 by videloff     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/10 14:12:57 by videloff    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			j = i;
		i++;
	}
	if (c == '\0')
		j = i;
	if ((s[j] == c || c == '\0') && (!s[i]))
		return (&((char *)s)[j]);
	return (NULL);
}
