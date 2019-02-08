/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 16:35:13 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/08 20:02:49 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

int			paste_str_in_printf(t_printf *print, char *str)
{
	char	*tmp;
	char	*tmp2;

	//printf("printf : %s\ntype : %d\n", print->printf, str);
	//if (!(add_precision_minwidth(print, &str)))
	//	return (-1);
	tmp2 = print->printf;
	if (tmp2)
	{
		if (!(print->printf = ft_strjoin(tmp2, str)))
			return (0);
		ft_strdel(&tmp2);
		print->size_all += ft_strlen(str);
		ft_strdel(&str);
	}
	else
		print->printf = str;
	//printf("NOWprintf : %s\n", print->printf);
	return (1);
}
