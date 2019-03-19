/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 15:10:06 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/28 16:48:23 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int			paste_float_in_printf(t_printf *print, char *str)
{
	char		*fill_str;
	char		*tmp;
	size_t		fill;
	size_t		len_str;

	len_str = ft_strlen(str);
	if (len_str < (size_t)print->arg->minimum_width)
	{
		fill = (size_t)print->arg->minimum_width - len_str;
		if (!(fill_str = ft_strnew(fill)))
			return (-1);
		ft_memset(fill_str, (int)print->arg->space_filled, fill);
		tmp = str;
		if (print->arg->ajust_left && !(str = ft_strjoin(tmp, fill_str)))
			return (-1);
		else if (!(str = ft_strjoin(fill_str, tmp)))
			return (-1);
		ft_strdel(&fill_str);
		ft_strdel(&tmp);
	}
	if (!(get_printf(print, &str, ft_strlen(str))))
		return (-1);
	return (1);
}
