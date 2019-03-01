/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:54:18 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/01 15:44:48 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

int			print_string(t_printf *print, char *str)
{
	if (!str)
	{
		paste_str_in_printf(print, ft_strdup("(null)"));
		return (0);
	}
	add_precision_minwidth(print, &str);
	paste_str_in_printf(print, ft_strdup(str));
	return (0);
}
