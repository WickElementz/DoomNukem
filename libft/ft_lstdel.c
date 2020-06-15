/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanne <kanne@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 10:55:48 by videloff          #+#    #+#             */
/*   Updated: 2020/06/15 15:45:22 by kanne            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *l;
	t_list *t;

	l = *alst;
	if (!alst || !del)
		return ;
	while (l)
	{
		t = l->next;
		del(l, l->content_size);
		l = t;
	}
	*alst = NULL;
}
