/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 15:10:06 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/27 17:18:32 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

// static int			add_precision_minwidth_float(t_printf *print, char **str)
// {
// 	size_t		size_m;
// 	size_t		size_p;
// 	size_t		len_str;
// 	int			neg;
// 	char		*tmp;
//
// 	if (!print->arg->precision && !print->arg->minimum_width)
// 		return (-1);
//
//
//
//
// 	len_str = ft_strlen(*str);
// 	neg = 0;
// 	if (*str[0] == '-')
// 	{
// 		len_str--;
// 		neg = 1;
// 	}
// 	if ((int)len_str >= print->arg->precision)
// 		size_p = 0;
// 	else
// 		size_p = print->arg->precision - len_str;
//
// 	if ((int)len_str + (int)size_p >= print->arg->minimum_width)
// 		size_m = 0;
// 	else
// 		size_m = print->arg->minimum_width - (len_str + size_p);
//
//
//
//
// 	if (!(tmp = ft_memalloc(len_str + size_m + size_p + neg)))
// 		return (0);
// 	ft_memset(tmp, (int)'0', len_str + size_m + size_p + neg);
//
//
//
//
// 	if (print->arg->ajust_left)
// 	{
// 		//ft_strcpy(tmp + size_p + neg, *str + neg); //add nbr
// 		ft_memmove(tmp + size_p + neg,  *str + neg, len_str); //add nbr
// 		ft_memset(tmp + len_str + size_p + neg, (int)print->arg->space_filled, size_m); //add minimum_width
// 		if (neg)
// 			tmp[0] = '-';
// 		ft_strdel(str);
// 		*str = tmp;
// 		return (len_str + size_m + size_p);
// 	}
// 	ft_memset(tmp + neg, (int)print->arg->space_filled, size_m); //add minimum_width
// 	ft_memmove(tmp + size_m + size_p + neg,  *str + neg, len_str); //add nbr
// 	//ft_strcpy(tmp + size_m + size_p + neg, *str + neg)
// 	if (neg)
// 		tmp[0] = '-';
// 	ft_strdel(str);
// 	*str = tmp;
//
//
//
//
// 	return (len_str + size_m + size_p);
// }

int			paste_float_in_printf(t_printf *print, char *str)
{
	char		*fill_str;
	char		*tmp;
	size_t		fill;
	size_t		len_str;

	len_str = ft_strlen(str);
	if (len_str < (size_t)print->arg->minimum_width)
	{
		fill = (size_t)print->arg->minimum_width - len_str;
		if (!(fill_str = ft_strnew(fill)))
			return (-1);
		ft_memset(fill_str, (int) print->arg->space_filled, fill);
		printf("%s\n", fill_str);
		tmp = str;
		if (print->arg->ajust_left)
		{
			if (!(str = ft_strjoin(tmp, fill_str)))
				return (-1);
		}
		else
			if (!(str = ft_strjoin(fill_str, tmp)))
				return (-1);
		ft_strdel(&fill_str);
		ft_strdel(&tmp);
	}
	//if (!(add_precision_minwidth_float(print, &str)))
	//	return (-1);
	if (!(get_printf(print, &str, ft_strlen(str))))
		return (-1);
	return (1);
}
