/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:26:13 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/27 18:11:42 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

int			output_string(t_printf *print)
{
	// t_list	*thomtolebg;
	//
	// thomtolebg = print->lst_to_print;
	// while (thomtolebg)
	// {
	// 	write(1, thomtolebg->content, thomtolebg->content_size);
	// 	thomtolebg = thomtolebg->next;
	// }
	//printf("%s\n", __func__);
	//printf("%s\n", print->printf);
	write(1, print->printf, print->size_all);
	print->lets_print = 0;
	ft_strdel(&print->printf);
	return (0);
}
