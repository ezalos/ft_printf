/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_garbage_collector.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 20:22:41 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/09 00:53:08 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			**ft_garbage_collector(void)
{
	static t_list	*garbage;

	// C_RED
	// ft_putendl(__func__);
	// C_RESET
	return (&garbage);
}
