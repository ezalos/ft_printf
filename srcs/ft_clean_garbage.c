/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_garbage.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 20:21:44 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/11 20:03:16 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_clean_garbage(void)
{
	t_list	*garbage;

	garbage = *ft_garbage_collector();
	ft_lst_free(&garbage);
}
