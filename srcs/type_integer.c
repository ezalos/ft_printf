/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_integer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:54:06 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/07 21:28:10 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

size_t		ft_nb_len(long long n)
{
	size_t size;

	if (n == 0)
		return (1);
	size = 0;
	if (n < 0)
		size++;
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

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
	print->last_type = ft_nb_to_a(nb);
	paste_type_in_printf(print, print->last_type);
	print->lets_print = 1;
	return (0);
}
