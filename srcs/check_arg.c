/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 18:57:12 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/11 19:18:00 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

void	check_flags(const char c, t_arg *arg)
{
	if (c == '0')
	{
		if (!arg->ajust_left && !arg->precision_exist)
			arg->space_filled = '0';
	}
	else if (c == '+')
	{
		arg->sign = 1;
		arg->space = 0;
	}
	else if (c == '-')
	{
		arg->ajust_left = 1;
		arg->space_filled = ' ';
	}
	else if (c == '#')
		arg->htag = 1;
	else if (c == ' ' && !arg->sign)
		arg->space = 1;
	if (arg->ajust_left && arg->space_filled == '0')
		arg->space_filled = ' ';
}

int		get_value_of_star_or_nb(t_printf *print, const char **f, int *tmp)
{
	if (**f == '*')
	{
		*tmp = (int)va_arg(print->ap, int);
		(*f)++;
	}
	else if (ft_isdigit(**f))
		while (ft_isdigit(**f))
			*tmp = *tmp * 10 + *(*f)++ - 48;
	if (*tmp < 0)
		*tmp = -*tmp;
	return (*tmp);
}

char	*get_value_of_star_or_str(t_printf *print, const char **f, char **tmp)
{
	size_t		len;

	len = 0;
	if (**f == '*')
	{
		*tmp = va_arg(print->ap, char*);
		(*f)++;
	}
	else
	{
		while ((*f)[len] != '}')
			len++;
		*tmp = ft_memalloc(len + 1);
		ft_memmove(*tmp, (*f), len);
		(*f) += len;
	}
	return (*tmp);
}

void	check_minimum_width_or_precision(t_printf *print, const char **f)
{
	int		*tmp;

	if (**f == '.')
	{
		tmp = &print->arg->precision;
		print->arg->precision_exist = 1;
		(*f)++;
		if (**f == '0')
		{
			(*f)++;
			return ;
		}
	}
	else
		tmp = &print->arg->minimum_width;
	*tmp = 0;
	get_value_of_star_or_nb(print, f, tmp);
	if (print->arg->precision)
		print->arg->space_filled = ' ';
}

void	check_modifier(const char **f, t_arg *arg)
{
	if (**f == 'h')
		arg->modifier_h++;
	else if (**f == 'l')
		arg->modifier_l++;
	else if (**f == 'L')
		arg->modifier_L++;
	(*f)++;
}

void	check_arg(t_printf *print, const char **f)
{
	while (!print->arg->type)
	{
		if (**f == '~')
			if (0 >= bonus_gestion(print, f))
				return ;
		if (**f == '#' || **f == '-' || **f == '+' || **f == '0' || **f == ' ')
			check_flags(*(*f)++, print->arg);
		else if (ft_isdigit(**f) || **f == '.' || **f == '*')
			check_minimum_width_or_precision(print, f);
		else if (**f == 'h' || **f == 'l' || **f == 'L')
			check_modifier(f, print->arg);
		else if (**f == 'j' || **f == 'z')
		{
			print->arg->modifier_l = 2;
			(*f)++;
		}
		else if (**f == 'r')
		{
			print->invisible = 1;
			(*f)++;
			break;
		}
		else if (**f == 'c' || **f == 's' || **f == 'p' || **f == 'd' || **f == 'b' ||
		**f == 'o' || **f == 'u' || **f == 'x' || **f == 'X' || **f == 'f' || **f == 'U')
		{
			print->arg->type = *(*f)++;
			if (print->arg->type == 'U')
			{
				print->arg->modifier_l = 2;
				print->arg->type = 'u';
			}
		}
		else
		{
			print->arg->type = *(*f);
			break;
		}
	}
}
