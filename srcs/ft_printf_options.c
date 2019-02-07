/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_options.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:55:36 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/07 15:55:39 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

int			printf_minlength_and_precision(t_printf *print, int i)
{
	int			precision;

	precision = 0;
	if (print->format[i] == '.') //precision
		precision++;
	else if (ft_isdigit(print->format[i]) && print->format[i] != '0')
		while (ft_isdigit(print->format[i])) //largeur minimal && precision
		{
			i++;
		}
	return (i);
}

int			printf_flags(t_printf *print, int i)
{
	return (i);
}

int			printf_options(t_printf *print, int i)
{
	while (!ft_char_srch(print->format[++i], "idfeEgGuoxXs%"))
	{
		if (ft_char_srch(print->format[i], "-+#0 "))
			printf_flags(print, i);
		if ((ft_isdigit(print->format[i]) && print->format[i] != '0') || print->format[i] == '.')
			printf_minlength_and_precision(print, i);
	}
	return (i);
}
