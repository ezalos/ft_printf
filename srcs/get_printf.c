/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 14:18:43 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/28 12:28:25 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

void		add_minimum_width_0(t_printf *print)
{
	if (print->arg->minimum_width > 1)
	{
		write(1, &print->arg->space_filled, print->arg->minimum_width - 1);
		print->size_all += print->arg->minimum_width - 1;
	}
}

int			get_printf(t_printf *print, char **str, size_t content_size)
{
	char	*tmp;

	tmp = print->printf;
	print->size_all += content_size;
	if (**str == 0)
	{
		output_string(print);
		if (print->arg->ajust_left)
		{
			write(1, "\0", 1);
			add_minimum_width_0(print);
		}
		else
		{
			add_minimum_width_0(print);
			write(1, "\0", 1);
		}
		ft_strdel(str);
		return (1);
	}
	if (tmp)
	{
		if (!(print->printf = ft_strjoin(tmp, *str)))
			return (0);
		ft_strdel(&tmp);
		ft_strdel(str);
	}
	else
	{
		print->printf = *str;
	}
	return (1);
}
