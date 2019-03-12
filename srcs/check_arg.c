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

void	add_type(const char **f, t_printf *print)
{
	if (**f == 'j' || **f == 'z')
	{
		print->arg->modifier_l = 2;
		(*f)++;
		return ;
	}
	print->arg->type = *(*f)++;
	if (print->arg->type == 'U')
	{
		print->arg->modifier_l = 2;
		print->arg->type = 'u';
	}
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
		else if (**f == 'r')
		{
			print->invisible = 1;
			(*f)++;
			break ;
		}
		else if (ft_char_srch(**f, "cspdbouxXfUzj"))
			add_type(f, print);
		else
		{
			print->arg->type = *(*f);
			break ;
		}
	}
}
