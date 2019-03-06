/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ajust_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:45:45 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/01 16:49:42 by ldevelle         ###   ########.fr       */
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

// int			get_sizes_precision_minwidth(t_printf *print, char **str, t_pre_min *box)
// {
// 	box->len_str = ft_strlen(*str);
// 	box->neg = 0;

// 	if (*str[0] == '-')
// 		box->neg = 1;
// 	else if (print->arg->sign)
// 		box->neg = 1;


// 	if ((int)box->len_str >= print->arg->precision)
// 		box->size_p = 0;
// 	else
// 		box->size_p = print->arg->precision - box->len_str;
// 	if (print->arg->space && print->arg->space_filled == '0')
// 		box->size_p++;


// 	if ((int)box->len_str + (int)box->size_p >= print->arg->minimum_width)
// 		box->size_m = 0;
// 	else
// 		box->size_m = print->arg->minimum_width - (box->len_str + box->size_p);
// 	return (1);
// }



// int			get_sizes_precision_minwidth_str(t_printf *print, char **str, t_pre_min *box)
// {
// 	box->len_str = ft_strlen(*str);
// 	box->neg = 0;
// 	if ((int)box->len_str >= print->arg->precision)
// 	{
// 		box->size_p = 0;
// 		box->len_str = print->arg->precision;
// 	}
// 	else
// 		box->size_p = print->arg->precision - box->len_str;

// 	if ((int)box->len_str + (int)box->size_p >= print->arg->minimum_width)
// 		box->size_m = 0;
// 	else
// 		box->size_m = print->arg->minimum_width - (box->len_str + box->size_p);
// 	return (1);
// }

// void		add_sign_option_space(t_printf *print, char *tmp, t_pre_min *box)
// {
// 	if (print->arg->space_filled == '0')
// 	{
// 		if (print->arg->space)
// 			tmp[0] = ' ';
// 		if (print->arg->sign)
// 			tmp[print->arg->space] = '+';
// 		else if (box->neg)
// 			tmp[print->arg->space] = '-';
// 	}
// 	else
// 	{
// 		if (print->arg->sign)
// 			tmp[0] = '+';
// 		else if (box->neg)
// 			tmp[0] = '-';
// 	}
// }

// int			adjust_string_with_precision_minwidth(t_printf *print, char **str, t_pre_min *box)
// {
// 	char		*tmp;


// 	if (!(tmp = ft_strnew(box->len_str + box->size_m + box->size_p + box->neg)))
// 		return (0);
// 	ft_memset(tmp, (int)'0', box->len_str + box->size_m + box->size_p + box->neg);
// 	if (print->arg->ajust_left)
// 	{
// 		ft_memmove(tmp + box->size_p + box->neg,  *str + box->neg, box->len_str); //add nbr
// 		ft_memset(tmp + box->len_str + box->size_p + box->neg, (int)print->arg->space_filled, box->size_m); //add minimum_width
// 		add_sign_option_space(print, tmp, box);
// 		ft_strdel(str);
// 		*str = tmp;
// 		return (box->len_str + box->size_m + box->size_p);
// 	}
// 	ft_memset(tmp + box->neg, (int)print->arg->space_filled, box->size_m); //add minimum_width
// 	ft_memmove(tmp + box->size_m + box->size_p + box->neg,  *str + box->neg, box->len_str); //add nbr
// 	add_sign_option_space(print, tmp, box);
// 	ft_strdel(str);
// 	*str = tmp;
// 	return (1);
// }



// int		adjust_htag(t_printf *print, char **str, t_pre_min *box)
// {
// 	if (!print->arg->precision && !print->arg->minimum_width)
// 	{
// 		if (add_htag(print, str) == -1)
// 			return (-1);
// 		return (1);
// 	}
// 	if (print->arg->space_filled == ' ')
// 		if (add_htag(print, str) == -1)
// 			return (-1);
// 	get_sizes_precision_minwidth(print, str, box);
// 	if (print->arg->htag && print->arg->space_filled == '0')
// 	{
// 		if (print->arg->type == 'o')
// 			box->size_m -= 1;
// 		else if (ft_char_srch(print->arg->type, "xX"))
// 			box->size_m -= 2;
// 	}
// 	adjust_string_with_precision_minwidth(print, str, box);
// 	if (print->arg->space_filled == '0')
// 		if (add_htag(print, str) == -1)
// 			return (-1);
// 	return (1);
// }

// int			add_precision_minwidth(t_printf *print, char **str)
// {
// //	char		*tmp;
// 	t_pre_min	box;

// 	ft_bzero(&box, sizeof(box));
// 	if (ft_char_srch(print->arg->type, "ouxX") && print->arg->htag)
// 	{
// 		if ((adjust_htag(print, str, &box) == -1))
// 			return (-1);
// 	}
// 	else if (ft_char_srch(print->arg->type, "dicouxX"))
// 		get_sizes_precision_minwidth(print, str, &box);
// 	else if (ft_char_srch(print->arg->type, "sc"))
// 		adjust_string_with_precision_minwidth(print, str, &box);
// 	return (1);
// }


void	reajust_sign(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '-')
		{
			str[i] = '0';
			str[0] = '-';
		}
		if (str[i] == '+')
		{
			str[i] = '0';
			str[0] = '+';
		}
	}
}

void	reajust_hatg(t_printf *print, char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		if (str[i] == 'x' || str[i] == 'X')
			str[i] = '0';
	if (str[0] == '0')
	{
		if (print->arg->type == 'x')
			str[1] = 'x';
		else if (print->arg->type == 'X')
			str[1] = 'X';
	}
}

int		add_minimum_width(t_printf *print, char **str)
{
	int		len;
	char	*tmp;
	char	*tmp2;

	tmp = NULL;
	tmp2 = *str;
	len = ft_strlen(*str);
	if (print->arg->minimum_width > len)
	{
		if (!(tmp = ft_strnew(print->arg->minimum_width - len)))
			return (-1);
		ft_memset(tmp, print->arg->space_filled, print->arg->minimum_width - len);
	}
	if (print->arg->ajust_left && tmp)
		if (!(*str = ft_strjoin(*str, tmp)))
			return (-1);
	if (!print->arg->ajust_left && tmp)
		if (!(*str = ft_strjoin(tmp, *str)))
			return (-1);
	if (tmp)
	{
		ft_strdel(&tmp);
		ft_strdel(&tmp2);
	}
	return (1);
}

int		add_precison(t_printf *print, char **str)
{
	int		len;
	char	*tmp;
	char	*tmp2;

	tmp2 = *str;
	len = ft_strlen(*str);
	if (*str[0] == '-')
		len--;
	if (print->arg->precision > len)
	{
		if (!(tmp = ft_strnew(print->arg->precision - len)))
			return (-1);
		ft_memset(tmp, '0', print->arg->precision - len);
		if (!(*str = ft_strjoin(tmp, *str)))
			return (-1);
		ft_strdel(&tmp);
		ft_strdel(&tmp2);
	}
	return (1);
}

int		add_htag(t_printf *print, char **str)
{
	char	*tmp;

	if (print->arg->htag)
	{
		tmp = *str;
		if (print->arg->type == 'o')
		{
			if (!(*str = ft_strjoin("0", tmp)))
				return (-1);
		}
		else if (print->arg->type == 'X')
		{
			if (!(*str = ft_strjoin("0X", tmp)))
				return (-1);
		}
		else if (print->arg->type == 'x')
			if (!(*str = ft_strjoin("0x", tmp)))
				return (-1);
		ft_strdel(&tmp);
	}
	return (0);
}

int		add_sign(char **str)
{
	char	*tmp;

	tmp = *str;
	if (!(*str = ft_strjoin("+", *str)))
		return (-1);
	ft_strdel(&tmp);
	return (1);
}

int		add_space(char **str)
{
	char	*tmp;

	tmp = *str;
	if (!(*str = ft_strjoin(" ", *str)))
		return (-1);
	ft_strdel(&tmp);
	return (1);
}

int		type_ouxX(t_printf *print, char **str)
{
	if (!print->arg->precision_exist && !print->arg->minimum_width)
	{
		if (add_htag(print, str) == -1)
				return (-1);
	}
	else 
	{
		if (print->arg->precision_exist)
			if (add_precison(print, str) == -1)
				return (-1);
		if (add_htag(print, str) == -1)
			return (-1);
		if (add_minimum_width(print, str) == -1)
			return (-1);
		if (print->arg->space_filled == '0' && print->arg->htag && ft_char_srch(print->arg->type, "xX"))
			reajust_hatg(print, *str);
	}
	return (1);
}

int		type_dic(t_printf *print, char **str)
{
	if (print->arg->precision_exist)
			if (add_precison(print, str) == -1)
				return (-1);
	if (print->arg->sign && print->arg->type != 'c')
		if (!(add_sign(str)))
			return (-1);
	if (add_minimum_width(print, str) == -1)
			return (-1);
	if (print->arg->space && print->arg->type != 'c' && *str[0] != ' ' && *str[0] != '-')
		if (!(add_space(str)))
			return (-1);
	if (*str[0] == '0')
		reajust_sign(*str);
	return (1);	
}

int		type_empty(t_printf *print, char **str)
{
	char 	*tmp;
	char 	*tmp2;

	tmp2 = *str;
	if (print->arg->minimum_width)
	{
		if (!(tmp = ft_strnew(print->arg->minimum_width)))
			return (-1);
		ft_memset(tmp, print->arg->space_filled, print->arg->minimum_width);
		*str = tmp;
		ft_strdel(&tmp2);
	}
	//printf("\nspace_filled : %c\n", print->arg->space_filled);
	return (1);
}

int		ajust_flags(t_printf *print, char **str)
{
	if (!print->arg->precision && print->arg->precision_exist && *str[0] == '0')
	{
		//ft_putstr_color("coucou", -1, -1, -1);
		if (type_empty(print, str) == -1)
			return (-1);
	}
	else if (ft_char_srch(print->arg->type, "ouxX"))
	{
		if (type_ouxX(print, str) == -1)
			return (-1);
	}
	else if (ft_char_srch(print->arg->type, "dic"))
	{
		if (type_dic(print, str) == -1)
			return (-1);
	}
	return (1);
}
























