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
