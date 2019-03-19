/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 16:35:13 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/28 16:56:05 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int			paste_str_in_printf(t_printf *print, char *str)
{
	int		len;

	if (!(ajust_flags(print, &str)))
		return (-1);
	len = ft_strlen(str);
	if (len)
		get_printf(print, &str, len);
	return (1);
}
