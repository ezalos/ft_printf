/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:26:13 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/11 19:21:44 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

int			output_invisible_char(size_t fd, char *str, size_t size)
{
	size_t		written;
	size_t		i;
	size_t		now;
	char		*character;
	char		backslash;

	i = 0;
	backslash = '\\';
	written = 0;
	character = NULL;
	while (i <= size)
	{
		if (ft_isprint(str[i]))
		{
			now = 1;
			write(fd, str + i, now);
		}
		else
		{
			ft_memdel((void**)&character);
			character = ft_nb_to_a(str[i], 10);
			now = ft_strlen(character);
			write(fd, &backslash, 1);
			write(fd, character, now);
			now++;
		}
		written += now;
		i++;
	}
	return (written);
}

int			output_string(t_printf *print)
{
	
	if (print->printf)
	{
		if (!print->invisible)
			write(print->fd, print->printf, ft_strlen(print->printf));
		else
		{
			print->size_all = output_invisible_char(print->fd,
			print->printf, ft_strlen(print->printf));
		}
	}
	print->lets_print = 0;
	ft_strdel(&print->printf);
	return (0);
}
