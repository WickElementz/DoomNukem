/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanne <kanne@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 16:16:38 by videloff          #+#    #+#             */
/*   Updated: 2020/06/15 15:43:43 by kanne            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	iswp(char c)
{
	if (c == ' ' || c == ',' || c == '\n' ||
			c == '\t')
		return (1);
	else
		return (0);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	while (iswp(s[i]) != 0 && s[i])
		i++;
	s = &s[i];
	i = -1;
	len = ft_strlen(s);
	while (iswp(s[len - 1]) != 0 && len - 1 >= 0)
		len--;
	if (!(str = ft_strnew(len)))
		return (0);
	while (++i < len)
		str[i] = s[i];
	str[i] = '\0';
	return (str);
}
