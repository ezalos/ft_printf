/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 14:18:43 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/27 18:13:25 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

/*ft_lstadd_end(print->lst_to_print, ft_lstnew(*str, content_size));*/

int			get_printf(t_printf *print, char **str, size_t content_size)
{
	char	*tmp;

	tmp = print->printf;
	(void)content_size;
	if (**str == 0)
	{
		output_string(print);
		write(1, "\0", 1);
		print->size_all++;
//		ft_strdel(&print->printf);
		ft_strdel(str);
		return (1);
	}
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
