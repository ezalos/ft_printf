/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:54:32 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/22 17:12:04 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

char	*get_int_from_float(intmax_t ldb, char neg)
{
	char	*int_part;
	char	*tmp;

	if (!(int_part = ft_nb_to_a(ldb, 10)))
		return (NULL);
	tmp = int_part;
	if (neg)
	{
		int_part = ft_strjoin("-", tmp);
		ft_strdel(&tmp);
	}
	return (int_part);
}

char	*get_decimal_from_float(t_arg *arg, long double ldb)
{
	char	*decimal_part;
	int		precision;
	int		i;

	if (arg->precision_exist)
		precision = arg->precision;
	else
		precision = 6;
	if (!(decimal_part = ft_strnew((size_t) precision + 1)))
		return (NULL);
	decimal_part[0] = '.';
	i = 0;
	while (++i <= precision)
	{
		ldb = ldb * 10;
		if (((intmax_t)ldb % 10) >= 0 && ((intmax_t)ldb % 10) <= 9)
			decimal_part[i] = ((intmax_t)ldb % 10) + '0';
		else
			decimal_part[i] = '0';
		ldb -= (intmax_t)ldb;
	}
	return (decimal_part);
}


int			print_float(t_printf *print, long double ldb)
{
	char		neg;
	char		*int_part;
	char		*decimal_part;

	C_GREEN
	printf("%Lf\n", ldb);
	C_RESET
	neg = 0;
	if (ldb < 0)
	{
		neg = 1;
		ldb = -ldb;
	}
	if (!(int_part = get_int_from_float((intmax_t)ldb, neg)) ||
	!(decimal_part = get_decimal_from_float(print->arg, ldb - (intmax_t)ldb)))
		return (-1);
	print->last_type = ft_strjoin(int_part, decimal_part);
	ft_strdel(&int_part);
	ft_strdel(&decimal_part);
	paste_float_in_printf(print, print->last_type);
	return (0);
}
