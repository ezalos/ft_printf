/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 18:57:12 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/07 21:55:09 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

void	check_flags(const char c, t_arg *arg)
{
	printf("%s\n", __func__);
	if (c == '0')
		arg->space_filled = '0';
	else if (c == '+')
		arg->sign = 1;
	else if (c == '-')
		arg->ajust_left = 1;
	else if (c == '#')
		arg->htag = 1;
}

void	check_minimum_width_or_precision(const char **f, t_arg *arg)
{
	printf("%s\n", __func__);
	int		*tmp;
	if (**f == '.')
	{
		tmp = &arg->precision;
		(*f)++;
		if (**f == '0')
			return ;
	}
	else
		tmp = &arg->minimum_width;
	while (**f >= '0' && **f<= '9')
		*tmp = *tmp * 10 + *(*f)++ - 48;
}

void	check_modifier(const char **f, t_arg *arg)
{
	printf("%s\n", __func__);
	if (**f == 'h')
		arg->modifier_h++;
	else if (**f == 'l')
		arg->modifier_l++;
	else if (**f == 'L')
		arg->modifier_L++;
	(*f)++;
}

void	check_arg(const char **f, t_arg *arg)
{
	printf("%s\n", __func__);
	printf("%s\n", *f);
	while (!arg->type)
	{
		if (**f == '#' || **f == '-' || **f == '+' || **f == '0')
			check_flags(*(*f)++, arg);
		else if (ft_isdigit(**f) || **f == '.')
			check_minimum_width_or_precision(f, arg);
		else if (**f == 'h' || **f == 'l' || **f == 'L')
			check_modifier(f, arg);
		else if (**f == 'c' || **f == 's' || **f == 'p' || **f == 'd' ||
		**f == 'o' || **f == 'u' || **f == 'x' || **f == 'X' || **f == 'f')
			arg->type = *(*f)++;
		else
			break;
	}
}
