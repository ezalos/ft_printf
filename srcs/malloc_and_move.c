/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_and_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 16:35:13 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/08 18:22:44 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

int			paste_format_in_printf(t_printf *print)
{
	char	*tmp;
	char	*tmp2;

	if (print->i <= 0 || !(tmp = ft_strsub(print->format, 0, print->i)))
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


int			add_precision_minwidth(t_printf *print, char **str)
{
	size_t		size_m;
	size_t		size_p;
	size_t		len_str;
	int			neg;
	char		*tmp;

	if (!print->arg->precision && !print->arg->minimum_width)
		return (-1);




	len_str = ft_strlen(*str);
	neg = 0;
	if (*str[0] == '-')
	{
		len_str--;
		neg = 1;
	}
	if (len_str >= print->arg->precision)
		size_p = 0;
	else
		size_p = print->arg->precision - len_str;

	if (len_str + size_p >= print->arg->minimum_width)
		size_m = 0;
	else
		size_m = print->arg->minimum_width - (len_str + size_p);




	if (!(tmp = ft_memalloc(len_str + size_m + size_p + neg)))
		return (0);
	ft_memset(tmp, (int)'0', len_str + size_m + size_p + neg);




	if (print->arg->ajust_left)
	{
		//ft_strcpy(tmp + size_p + neg, *str + neg); //add nbr
		ft_memmove(tmp + size_p + neg,  *str + neg, len_str); //add nbr
		ft_memset(tmp + len_str + size_p + neg, (int)print->arg->space_filled, size_m); //add minimum_width
		if (neg)
			tmp[0] = '-';
		ft_strdel(str);
		*str = tmp;
		return (len_str + size_m + size_p);
	}
	ft_memset(tmp + neg, (int)print->arg->space_filled, size_m); //add minimum_width
	ft_memmove(tmp + size_m + size_p + neg,  *str + neg, len_str); //add nbr
	//ft_strcpy(tmp + size_m + size_p + neg, *str + neg)
	if (neg)
		tmp[0] = '-';
	ft_strdel(str);
	*str = tmp;




	return (len_str + size_m + size_p);
}

int			paste_type_in_printf(t_printf *print, char *str)
{
	char	*tmp;
	char	*tmp2;

	//printf("printf : %s\ntype : %d\n", print->printf, str);
	if (!(add_precision_minwidth(print, &str)))
		return (-1);
	tmp2 = print->printf;
	if (tmp2)
	{
		if (!(print->printf = ft_strjoin(tmp2, str)))
			return (0);
		ft_strdel(&tmp2);
		print->size_all += ft_strlen(str);
		ft_strdel(&str);
	}
	else
		print->printf = str;
	//printf("NOWprintf : %s\n", print->printf);
	return (1);
}
