/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 18:06:47 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/06 17:04:44 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

int			ft_printf(const char *format, ...)
{
	t_printf	*print;
//	va_list		ap;
	int			i;

	if (!(print = init_struct(format)))
		return (-1);
	va_start(print->ap, format);
	i = -1;
	while (print->format[++i])
	{
		if (ft_char_src(print->format[i], "%"))
			while (!ft_char_src(print->format[++i], "idfeEgGuoxXs%")
			{
				if (ft_char_src(print->format[i], "-+#0 ")
					return ;
				if else (ft_isdigit(format[i]) && print->format[i] != '0') //largeur minimal
					return ;
				if else (print->format[i] == '.') //precision
				{
					if (ft_isdigit(format[i]) && print->format[i] != '0')
						return ;
				}

			}
		ptr_nb = va_arg(print->ap, int);
	}
	va_end(print->ap);
//	free_all(print);
	return (1);
}

int			parsing(const char *format, va_list ap)
{

}
