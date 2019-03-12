/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:18:40 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/11 20:37:33 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lstfind_and_free(void **ap)
{
	t_list		*tmp;

	tmp = *ft_garbage_collector();
	while (tmp)
	{
		if (*ap == tmp->content)
		{
			free(tmp->content);
			tmp->content = NULL;
			return ;
		}
		tmp = tmp->next;
	}
}

void	ft_strdel(char **as)
{
	if (as && *as)
	{
		if (NREE)
		{
			ft_lstfind_and_free((void**)as);
			*as = NULL;
		}
		else
		{
			free(*as);
			*as = NULL;
		}
	}
}
