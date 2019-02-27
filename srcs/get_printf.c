/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 14:18:43 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/27 17:22:48 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

/*ft_lstadd_end(print->lst_to_print, ft_lstnew(*str, content_size));*/

int			get_printf(t_printf *print, char **str, size_t content_size)
{
	char	*tmp;

	tmp = print->printf;
	(void)content_size;
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
