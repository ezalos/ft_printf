/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_character.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 19:44:23 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/28 16:52:11 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"
/*
int			get_sizes_precision_minwidth_str(t_printf *print, char **str, t_pre_min *box)
{
	box->len_str = ft_strlen(*str);
	box->neg = 0;
	if ((int)box->len_str >= print->arg->precision)
		box->size_p = 0;
	else
		box->size_p = print->arg->precision - box->len_str;

	if ((int)box->len_str + (int)box->size_p >= print->arg->minimum_width)
		box->size_m = 0;
	else
		box->size_m = print->arg->minimum_width - (box->len_str + box->size_p);
	return (1);
}

int			adjust_string_with_precision_minwidth_str(t_printf *print, char **str, t_pre_min *box)
{
	char		*tmp;


	if (!(tmp = ft_memalloc(box->len_str + box->size_m + box->size_p + box->neg)))
		return (0);
	ft_memset(tmp, (int)' ', box->len_str + box->size_m + box->size_p + box->neg);
	if (print->arg->ajust_left)
	{
		ft_memmove(tmp + box->size_p + box->neg,  *str + box->neg, box->len_str); //add nbr
		ft_memset(tmp + box->len_str + box->size_p + box->neg, (int)print->arg->space_filled, box->size_m); //add minimum_width
		ft_strdel(str);
		*str = tmp;
		return (box->len_str + box->size_m + box->size_p);
	}
	ft_memset(tmp + box->neg, (int)print->arg->space_filled, box->size_m); //add minimum_width
	ft_memmove(tmp + box->size_m + box->size_p + box->neg,  *str + box->neg, box->len_str); //add nbr
	ft_strdel(str);
	*str = tmp;
	return (1);


}

static int	add_precision_minwidth_str(t_printf *print, char **str)
{
	t_pre_min	box;

	if (!print->arg->precision && !print->arg->minimum_width)
		return (-1);
	get_sizes_precision_minwidth_str(print, str, &box);
	adjust_string_with_precision_minwidth_str(print, str, &box);
	return (box.len_str + box.size_m + box.size_p);
}*/

int			print_character(t_printf *print, char str)
{
	paste_char_in_printf(print, str);
	return (0);
}
