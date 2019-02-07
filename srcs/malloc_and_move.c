/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_and_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 16:35:13 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/07 21:25:44 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

int			paste_format_in_printf(t_printf *print)
{
	char	*tmp;
	char	*tmp2;

	if (print->i - 1 <= 0 || !(tmp = ft_strsub(print->format, 0, print->i - 1)))
		return (0);
	tmp2 = print->printf;
	if (tmp2)
	{
		if (!(print->printf = ft_strjoin(tmp2, tmp)))
			return (0);
		ft_strdel(&tmp2);
		ft_strdel(&tmp);
	}
	else
		print->printf = tmp;
	print->format += print->i;
	print->size_all += print->i;
	print->i = 0;
	return (1);
}

int			paste_type_in_printf(t_printf *print, char *str)
{
	char	*tmp;
	char	*tmp2;

	tmp2 = print->printf;
	if (!tmp2)
	{
		if (!(print->printf = ft_strjoin(tmp2, str)))
			return (0);
		ft_strdel(&tmp2);
		print->size_all += ft_strlen(str);
		ft_strdel(&str);
	}
	else
		print->printf = str;
	return (1);
}
