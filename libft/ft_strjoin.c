/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: videloff <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/12 15:40:31 by videloff     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/19 18:12:42 by videloff    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;

	join = NULL;
	if (!s1 || !s2)
		return (0);
	if (!(join = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (0);
	join = ft_strcat(join, s1);
	join = ft_strcat(join, s2);
	return (join);
}
