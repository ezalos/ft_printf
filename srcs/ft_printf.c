/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 18:06:47 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/08 18:35:50 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

int			ft_printf(const char *format, ...)
{
	static t_printf	print;
	char			*tmp;
	int				precision;

	if (!(init_struct(&print, format)))
		return (-1);
	va_start(print.ap, format);
	print.i = 0;
	while (print.format[print.i])
	{
		if (ft_char_srch(print.format[print.i], "%"))
		{
			if(!(paste_format_in_printf(&print)))
				return (-1);
			init_struct_arg(&print, format);
			print.format += print.i + 1;
			check_arg(&print.format , print.arg);
			parsing(&print, print.ap);
		}
		print.i++;
	}
	if(!(paste_format_in_printf(&print)))
		return (-1);
	//if (print.lets_print)
		output_string(&print);
//	free_all(print);
	return (print.size_all);
}
