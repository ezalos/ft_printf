/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_integer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:54:06 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/07 18:26:27 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

static void	ft_putnbr_str(int i, long long n, char *nb)
{
	while (i >= 0 && nb[i] != '-')
	{
		nb[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
}

char		*ft_nb_to_a(long long n)
{
	char	*nb;
	int		size;
	int		neg;
	int		i;

	neg = 1;
	if (n >= 0)
		neg = 0;
	size = ft_nb_len(n);
	if (!(nb = ft_strnew(size)))
		return (NULL);
	if (neg == 1)
	{
		nb[0] = '-';
		n = -n;
	}
	i = size;
	ft_putnbr_str(i - 1, n, nb);
	return (nb);
}

int			print_integer(t_printf *print, long long nb)
{
	char	*tmp;

	tmp = print->printf;
	print->last_type = ft_nb_to_a(nb);
	print->printf = ft_strjoin(print->printf, print->last_type);
	ft_strdel(&print->last_type);
	ft_strdel(&tmp);
	return (0);
}
