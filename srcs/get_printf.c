/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 14:18:43 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/12 14:21:09 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

int			get_printf(t_printf *print, char **str)
{
	char	*tmp;

	tmp = print->printf;
	if (tmp)
	{
		if (!(print->printf = ft_strjoin(tmp, *str)))
			return (0);
		ft_strdel(&tmp);
		print->size_all += ft_strlen(*str);
		ft_strdel(str);
	}
	else
		print->printf = *str;
	return (1);
}
