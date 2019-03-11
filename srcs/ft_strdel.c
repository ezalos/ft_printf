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
// #include <stdio.h>

static void	ft_lstfind_and_free(void **ap)
{
	t_list		*tmp;

	// ft_putendl(__func__);
	// ft_putendl("ft_strdel");
	// printf("%zu|%zu|%zu\n", sizeof(void*), sizeof(t_list*), sizeof(char*));
	tmp = *ft_garbage_collector();
	while (tmp)
	{
		//if (ft_memcmp(*ap, tmp->content, sizeof(void*)))
		// printf("%p\n%p\n", *ap, tmp->content);
		if (*ap == tmp->content)
		{
			// ft_putendl("FOUND");
			free(tmp->content);
			tmp->content = NULL;
			return ;
		}
		// else
			// ft_putendl("NOT FOUND");
		tmp = tmp->next;
	}
}

void	ft_strdel(char **as)
{
	// ft_putendl(__func__);
	if (as && *as)
	{
		if (NREE)
		{
			// ft_putendl("SOMET HING ft_strdel\n");
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
