/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_garbage.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 20:21:44 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/09 01:14:41 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_clean_garbage(void)
{
	t_list	*garbage;

	garbage = *ft_garbage_collector();
	// ft_putstr("\n\t");
	// ft_putendl(__func__);
	ft_lst_free(&garbage);
	//if (garbage)
	//	free(&garbage);
	ft_memdel((void**)ft_garbage_collector());
	// ft_putendl("\tDONE\n\n");
}
