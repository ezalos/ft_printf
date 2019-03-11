/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 20:22:07 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/11 21:04:34 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** void		ft_print_address_color(intmax_t nb)
** {
** 	unsigned char		color;
**
** 	color = (unsigned char)nb;
** 	ft_putstr_color("|", 255, 255, 255);
** 	if (!nb)
** 		ft_putstr_color("    0x0     ", 255, 255, 255);
** 	else
** 		ft_putstr_color(ft_nb_to_a(nb, 16), ft_random(0, 255, nb, color), ft_random(0, 255, nb, color / 2), ft_random(0, 255, nb, color / 3));
** 	ft_putstr_color("|", 255, 255, 255);
** }
*/

#include <stdio.h>

size_t			ft_lst_free(t_list **delete_me)
{
	t_list	*tmp;
	t_list	*next;
	t_list	*leaks;
	size_t	i;

	if (!delete_me)
		return (0);
	// ft_putendl(__func__);
	tmp = *delete_me;
	i = 0;
	while (tmp)
	{
		next = tmp->next;
		leaks = tmp->content;
		// C_YELLOW
		// printf("\t\tstruct: %p\n", tmp);
		// C_GREEN
		// printf("\t\tcontent: %p\n", tmp->content);
		ft_strdel((char**)&leaks);
		ft_strdel((char**)&tmp);
		// C_RED
		// printf("\t\t\tstruct: %p\n", tmp);
		// C_CYAN
		// printf("\t\t\tcontent: %p\n", leaks);
		// C_RESET
		// printf("\t\tnext: %p\n\n", next);
		i++;
		tmp = next;
	}
	return (i);
}
