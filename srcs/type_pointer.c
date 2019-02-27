/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_pointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:54:50 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/27 18:04:16 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

int			print_pointer(t_printf *print, void* ptr)
{
	char		*tmp1;
	char		*tmp2;
	// int			i;

	if (!(tmp1 = ft_nb_to_a((intmax_t)ptr, 16)))
		return (-1);
	// i = -1;
	// while (tmp1[++i])
	// 	if (ft_islower((int) tmp1[i]))
	// 		tmp1[i] += 'A' - 'a';
	if (!(tmp2 = ft_strjoin("0x", tmp1)))
		return (-1);
	ft_strdel(&tmp1);
	get_printf(print, &tmp2, ft_strlen(tmp2));
	return (0);
}
