/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: videloff <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 17:40:09 by videloff     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 17:59:54 by videloff    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *bs1;
	unsigned char *bs2;

	bs1 = (unsigned char *)s1;
	bs2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*bs1 != *bs2)
			return (*bs1 - *bs2);
		bs1++;
		bs2++;
		n--;
	}
	return (0);
}
