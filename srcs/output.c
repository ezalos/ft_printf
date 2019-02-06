/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:26:13 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/06 16:26:42 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

int			start_output(int true)
{
	if (true)
		ft_putstr("->ft_printf: ");
	else
		ft_putstr("->truprintf: ");
	return (0);
}
