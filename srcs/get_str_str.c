/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 16:35:13 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/12 14:53:40 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

int			paste_str_in_printf(t_printf *print, char *str)
{
	int		size;
	size_t	len;

	size = -1;
	len = ft_strlen(str);
	if (print->arg->precision_exist)
		size = print->arg->precision;
	if (size >= 0 && size < (int)len)
		str[size] = '\0';
	get_printf(print, &str);
	return (1);
}
