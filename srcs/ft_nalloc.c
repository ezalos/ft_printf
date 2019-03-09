/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nalloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 20:18:57 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/09 02:09:06 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static t_list	*ft_nalloc_lstnew_ptr(void const *content, size_t content_size)
{
	t_list	*new;

	if (!(new = malloc(sizeof(t_list))))
		return (NULL);
	printf("\tt_lst: %p\n", new);
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		new->content_size = content_size;
		if (!content_size || !(new->content = malloc(content_size)))
		{
			ft_memdel((void**)&new);
			return (NULL);
		}
		printf("\t\tc_ptr: %p\n", new->content);
		ft_memmove(new->content, (void*)content, content_size);
	}
	new->next = NULL;
	return (new);
}

void			*nalloc(size_t size_content)
{
	void	*new_malloc;
	t_list	*garbage;

	return (malloc(size_content));
	if (!size_content)
		return (NULL);
	if (!*ft_garbage_collector()
	&& !((*ft_garbage_collector()) = ft_nalloc_lstnew_ptr(NULL, 0)))
			ft_burn_garbage(NULL);
	if (!(new_malloc = malloc(size_content)))
		ft_burn_garbage(NULL);
	printf("maloc: %p\n", new_malloc);
	if (!(garbage = ft_nalloc_lstnew_ptr(new_malloc, sizeof(*new_malloc))))
	{
		ft_memdel((void**)&new_malloc);
		ft_burn_garbage(NULL);
	}
	ft_lstadd_end(*ft_garbage_collector(), garbage);
	return (new_malloc);
}
