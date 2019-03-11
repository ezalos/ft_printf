/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:10:47 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/11 20:37:47 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
static void	ft_lstfind_and_free(void **ap)
{
	t_list		*tmp;

	// ft_putendl(__func__);
	// ft_putendl("ft_memdel");
	// printf("%zu|%zu|%zu\n", sizeof(void*), sizeof(t_list*), sizeof(char*));
	tmp = *ft_garbage_collector();
	while (tmp)
	{
		if (*ap == tmp->content)
		{
			// ft_putendl("FOUND");
			free(tmp->content);
			tmp->content = NULL;
			return ;
		}
		// else
		// 	ft_putendl("NOT FOUND");
		tmp = tmp->next;
	}
}

void	ft_memdel(void **ap)
{
	// ft_putendl(__func__);
	if (!ap)
		if (!*ap)
		{
			if (NREE)
			{
				// ft_putendl("SOMETHING ft_memdel\n");
				ft_lstfind_and_free(ap);
				*ap = NULL;
			}
			else
			{
				free(*ap);
				*ap = NULL;
			}
		}
}
