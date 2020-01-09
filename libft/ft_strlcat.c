/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: videloff <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 12:02:38 by videloff     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/19 18:31:34 by videloff    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	len;

	len = 0;
	while (dest[len] && len < n)
		len += 1;
	i = len;
	while (src[len - i] && len + 1 < n)
	{
		dest[len] = src[len - i];
		len += 1;
	}
	if (i < n)
		dest[len] = '\0';
	return (i + ft_strlen(src));
}
