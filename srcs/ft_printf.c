/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 18:06:47 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/07 18:24:17 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

int			ft_printf(const char *format, ...)
{
	static t_printf	print;
	int				precision;
	int				i;

//	if (!print)
		if (!(init_struct(format)))
			return (-1);
	va_start(print.ap, format);
	i = -1;
	while (print.format[++i])
	{
		if (ft_char_srch(print.format[i], "%"))
		{
			i = printf_options(&print, i);
			if (ft_char_srch(print.format[i], "di"))
				print_integer(&print, va_arg(print.ap, long long));
			else if (ft_char_srch(print.format[i], "ouxX"))
				print_unsigned_integer(&print, va_arg(print.ap, unsigned long long));
			else if (ft_char_srch(print.format[i], "feEgG"))
				print_float(&print, va_arg(print.ap, long double));
			else if (ft_char_srch(print.format[i], "cs"))
				print_string(&print, va_arg(print.ap, char*));
			else if (ft_char_srch(print.format[i], "p"))
				print_pointer(&print, va_arg(print.ap, void*));
		}
		if (print.lets_print)
			output_string(&print);
	}
//	free_all(print);
	return (i);
}

int			parsing(const char *format, va_list ap)
{
	return (0);
}
