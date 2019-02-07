/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:01:45 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/07 16:26:04 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

int			init_all_types(t_all_types *all)
{
	all->my_int = 0;
	all->my_short = 0;
	all->my_long = 0;
	all->my_double = 0;
	all->my_long_double = 0;
	all->my_float = 0;
	all->my_u_int = 0;
	all->my_u_short = 0;
	all->my_u_long = 0;
	all->my_char = 0;
	all->my_str = NULL;
	all->my_ptr = NULL;
	return (0);
}

int			init_for_new_turn(t_printf *print, int i)
{
	return (0);
}

t_printf	*init_struct(const char *format)
{
	t_printf	*print;

	if (!(print = (t_printf*)malloc(sizeof(t_printf))))
		return (NULL);
	if (!(print->format = ft_strdup(format)))
		return (NULL);
	if (!(print->backup_format = ft_strdup(format)))
		return (NULL);
	if (!(print->all = (t_all_types*)malloc(sizeof(t_all_types))))
		return (NULL);
	print->printf = NULL;
	print->size_all = 0;
	print->last_type = NULL;
	print->size_type = 0;
	print->lets_print = 0;
	print->complete = 0;
	init_all_types(print->all);
	return (print);
}
