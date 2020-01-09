/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_countword.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: videloff <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/22 15:11:21 by videloff     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/22 15:32:02 by videloff    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_countword(const char *str, char c)
{
	int word;
	int i;

	word = 0;
	i = 0;
	while (str[i] == c && str[i])
		i++;
	while (str[i])
	{
		while (str[i] != c && str[i])
			i++;
		word++;
		while (str[i] == c && str[i])
			i++;
	}
	return (word);
}
