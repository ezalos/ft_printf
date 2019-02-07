/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 18:06:47 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/07 21:55:34 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

int			parsing(t_printf *print, va_list ap)
{
	if (ft_char_srch(print->arg->type, "di"))
		print_integer(print, va_arg(print->ap, long long));
	else if (ft_char_srch(print->arg->type, "ouxX"))
		print_unsigned_integer(print, va_arg(print->ap, unsigned long long));
	else if (ft_char_srch(print->arg->type, "feEgG"))
		print_float(print, va_arg(print->ap, long double));
	else if (print->arg->type == 's')
		print_string(print, va_arg(print->ap, char*));
//	else if (print->arg->type == 'c')
//		print_string(print, va_arg(print->ap, char));
	else if (print->arg->type == 'p')
		print_pointer(print, va_arg(print->ap, void*));
//	else if (print->arg->type == '%')
			//a faire
	return (0);
}

int			ft_printf(const char *format, ...)
{
	static t_printf	print;
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
			printf("%s\n", (print.format + (sizeof(char) * (print.i + 1))));
			check_arg(&print.format + (sizeof(char) * (print.i + 1)), print.arg);
			parsing(&print, print.ap);
		}
		if (print.lets_print)
			output_string(&print);
		print.i++;
	}
		if (print.lets_print)
			output_string(&print);
//	free_all(print);
	return (print.size_all);
}
