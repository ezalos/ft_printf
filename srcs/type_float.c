/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:54:32 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/12 19:11:31 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

char	*s_to_bin(char *str, int length)
{
	char	*binary;
	int		actual_char;
	int		power;

	if (!(binary = ft_strnew(length * 8)))
		return (NULL);
	actual_char = -1;
	while (++actual_char < length)
	{
		power = -1;
		while (++power < 8)
			if (str[actual_char] & (unsigned char)ft_power(2, power))
				binary[(actual_char * 8) + (7 - power)] = '1';
			else
				binary[(actual_char * 8) + (7 - power)] = '0';
	}
	return (binary);
}

void	*void_to_str(const void *myst, size_t size)
{
	char	*str;

	str = ft_strnew(size);
	ft_memmove((void*)str, (char*)myst, size);
	return (str);
}

int			print_float(t_printf *print, double nb)
{/*
	char	*str;
	char	*bin;
	int		size;
	int		i;
	int		j;
	long double  ip = 256.256;
	long double  pi = 256.256;
	long double  pp;

	i = -1;
	while (++i <= 10)
	{
		ip *= 2;
	}
	i = -1;
	while (++i <= 20)
	{
		pi /= 3.0;
		pi *= 2.5;
	}
	ip = -ip;
	printf("IP : %Lf\n", ip);
	printf("PI : %Lf\n", pi);
	pp = 0.1;
	printf("PP : %Lf\n", pp);
	//printf("IP : %lld\n", (long long)ip);
	size = sizeof(ip);
	str = void_to_str(&pp, size);
	bin = s_to_bin(str, size);
	printf("size= %d\n", size);
	i = -1;
	while (++i < size)
	{
		//printf("%d|%u|", i, str[i]);
		ft_putnbr(i);
		ft_putstr("\t");
		ft_putnbr(str[i]);
		ft_putstr("\t");
		j = -1;
		while (++j < 8)
		{
			ft_putchar(bin[((i * 8) + j)]);
		}
		ft_putstr("\n");
	}
	printf("BINARY->%.*s\n", (int)(size * 8), bin);*/
	//ft_putstr("\n");
	paste_int_in_printf(print, ft_strjoin(ft_strjoin(ft_nb_to_a((int)nb, 10), "."), ft_nb_to_a((long long)((nb - (int)nb) * 1000000), 10)));
	return (0);
}
