/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 18:06:47 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/09 01:41:45 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

int			paste_format_in_printf(t_printf *print)
{
	char			*tmp;
	char			*tmp2;

	// C_BROWN
	// ft_putstr(__func__);
	// C_YELLOW
	// ft_putstr(": ");
	// ft_putnbr(print->i);
	// ft_putendl("");
	// C_RESET
 	if (print->i <= 0)
		return (1);
	if (!(tmp = ft_strsub(print->format, 0, print->i)))
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

int			ft_printf(const char *format, ...)
{
	static t_printf		print;
	int					r_val;

	if (!(init_struct(&print, format)))
		return (-1);
	va_start(print.ap, format);
	print.i = 0;
	while (print.format[print.i])
	{
		if (ft_char_srch(print.format[print.i], "%"))
		{
			//ft_putchar(print.format[print.i + 1]);
			//ft_putendl("");
			if(!(paste_format_in_printf(&print)))
				return (-1);
			init_struct_arg(&print, format);
			print.format++;
			check_arg(&print.format , print.arg);
			if (print.arg->type != '\0')
				parsing(&print);
		}
		if (print.format[print.i] != '%' && print.format[print.i])
			print.i++;
	}
	if(!(paste_format_in_printf(&print)))
		return (-1);
	//if (print.lets_print)
	output_string(&print);
//	free_all(print);
	r_val = print.size_all;
	// ft_clean_garbage();
	return (r_val);
}
