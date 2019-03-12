/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:26:13 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/12 17:12:14 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

int			output_invisible_char(size_t fd, char *str, size_t size)
{
	char		*character;
	size_t		written;
	size_t		now;
	int			i;

	i = -1;
	written = 0;
	character = NULL;
	while (++i <= (int)size)
	{
		if (ft_isprint(str[i]))
			write(fd, str + i, now = 1);
		else
		{
			ft_memdel((void**)&character);
			character = ft_nb_to_a(str[i], 10);
			write(fd, "\\", 1);
			write(fd, character, now = ft_strlen(character));
			now++;
		}
		written += now;
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
