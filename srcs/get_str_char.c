/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 16:06:10 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/27 17:22:09 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

int			paste_char_in_printf(t_printf *print, char str)
{
	char	*my_char;

	if (!(my_char = ft_strnew(1)))
		return (0);
	my_char[0] = str;
	get_printf(print, &my_char, 1);
	return (1);
}