/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_minwidth.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:45:45 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/28 19:15:49 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

/*
**	t_pre_min 	box;
**
**	size_t				len_str;
**	size_t				size_m;
**	size_t				size_p;
**	int					neg;
*/

int			get_sizes_precision_minwidth(t_printf *print, char **str, t_pre_min *box)
{
	box->len_str = ft_strlen(*str);
	box->neg = 0;
	if (*str[0] == '-')
	{
//		box->len_str--;
		box->neg = 1;
	}
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



int			get_sizes_precision_minwidth_str(t_printf *print, char **str, t_pre_min *box)
{
	box->len_str = ft_strlen(*str);
	box->neg = 0;
	if ((int)box->len_str >= print->arg->precision)
	{
		box->size_p = 0;
		box->len_str = print->arg->precision;
	}
	else
		box->size_p = print->arg->precision - box->len_str;

	if ((int)box->len_str + (int)box->size_p >= print->arg->minimum_width)
		box->size_m = 0;
	else
		box->size_m = print->arg->minimum_width - (box->len_str + box->size_p);
	return (1);
}

int			adjust_string_with_precision_minwidth(t_printf *print, char **str, t_pre_min *box)
{
	char		*tmp;


	if (!(tmp = ft_strnew(box->len_str + box->size_m + box->size_p + box->neg)))
		return (0);
	ft_memset(tmp, (int)'0', box->len_str + box->size_m + box->size_p + box->neg);
	//printf("~->%s\n", tmp);
	if (print->arg->ajust_left)
	{
		//printf("%d\n", box->neg);
		//printf("~->%s\n", tmp);
		ft_memmove(tmp + box->size_p + box->neg,  *str + box->neg, box->len_str); //add nbr
		//printf("~->%s\n", tmp);
		ft_memset(tmp + box->len_str + box->size_p + box->neg, (int)print->arg->space_filled, box->size_m); //add minimum_width
		//printf("~->%s\n", tmp);
		if (box->neg)
			tmp[0] = '-';
		ft_strdel(str);
		*str = tmp;
		//printf("~->%s\n", tmp);
		return (box->len_str + box->size_m + box->size_p);
	}
	ft_memset(tmp + box->neg, (int)print->arg->space_filled, box->size_m); //add minimum_width
	ft_memmove(tmp + box->size_m + box->size_p + box->neg,  *str + box->neg, box->len_str); //add nbr
	if (box->neg)
		tmp[0] = '-';
	ft_strdel(str);
	*str = tmp;
	return (1);


}
int		adjust_htag(t_printf *print, char **str)
{
	char	*tmp;

	if (print->arg->htag)
	{
		tmp = *str;

		if (print->arg->type == 'o')
			*str = ft_strjoin("0", tmp);
		else if (print->arg->type == 'X')
			*str = ft_strjoin("0X", tmp);
		else if (print->arg->type == 'x')
			*str = ft_strjoin("0x", tmp);
		ft_strdel(&tmp);
	}
	return (0);
}

int			add_precision_minwidth(t_printf *print, char **str, int type)
{
	t_pre_min	box;

	if (!print->arg->precision && !print->arg->minimum_width)
	{
		adjust_htag(print, str);
		return (-1);
	}
	if (!type)
	{
		if (print->arg->space_filled == '0')
		{
			get_sizes_precision_minwidth(print, str, &box);
			if (print->arg->htag)
			{
				if (print->arg->type == 'o')
					box.size_m -= 1;
				else if (print->arg->type == 'x')
					box.size_m -= 2;
				else if (print->arg->type == 'X')
					box.size_m -= 2;
			}
			adjust_string_with_precision_minwidth(print, str, &box);
			adjust_htag(print, str);
			return (1);
		}
		else if (print->arg->space_filled == ' ')
		{
			adjust_htag(print, str);
			get_sizes_precision_minwidth(print, str, &box);
			adjust_string_with_precision_minwidth(print, str, &box);
			return (1);
		}
	}
	else if (type == 1)
		get_sizes_precision_minwidth(print, str, &box);
	else if (type == -1)
		return (1);
	adjust_string_with_precision_minwidth(print, str, &box);
	return (box.len_str + box.size_m + box.size_p);
}
