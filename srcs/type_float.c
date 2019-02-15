/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:54:32 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/15 16:46:22 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

unsigned char	*s_to_bin(unsigned char *str, int length)
{
	unsigned char	*binary;
	int		actual_char;
	int		power;

	if (!(binary = (unsigned char*)ft_strnew(length * 8)))
		return (NULL);
	actual_char = -1;
	while (++actual_char < length)
	{
		power = -1;
		while (++power < 8)
			if (str[actual_char] & (unsigned char)ft_power(2, power))
				binary[(actual_char * 8) + (power)] = '1';
			else
				binary[(actual_char * 8) + (power)] = '0';
	}
	return (binary);
}

unsigned char	*ft_strrev(unsigned char *str, size_t size)
{
	unsigned char	tmp;
	int		i;
	int		j;

	i = 0;
	if (size != 0)
		j = size - 1;
	else
		j = ft_strlen((char*)str) - 1;
	while (i < j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		j--;
		i++;
	}
	return (str);
}

void	*void_to_str(const void *myst, size_t size)
{
	char	*str;

	str = ft_strnew(size);
	ft_memmove((void*)str, (char*)myst, size);
	return (str);
}

void	print_string_to_u_char(unsigned char* converter, size_t size_thing)
{
	int			i;
	char		*tmp;

	i = size_thing;
	while (--i > -1)
	{
		tmp = ft_nb_to_a((int)converter[i], 0);
		ft_puttab(tmp, 8);
		ft_putnbr((int)converter[i]);
		ft_strdel(&tmp);
		ft_putstr(" ");
	}
}

void	print_string_to_binary(unsigned char* converter, size_t size_thing)
{
	int			i;

	converter = s_to_bin(converter, size_thing);
	ft_strrev(converter, (size_thing * 8));
	i = -1;
	while (++i < (int)size_thing)
	{
		ft_putnstr((const char*)converter + i * 8, 8);
		ft_putstr(" ");
	}
	ft_strdel((char**)&converter);
}

void	print_thing_to_binary_and_unsigned_char(void* thing, size_t size_thing)
{
	ft_putstr("\n");
	print_string_to_u_char((unsigned char*)thing, size_thing);
	ft_putstr("\n");
	print_string_to_binary((unsigned char*)thing, size_thing);
	ft_putstr("\n");
}

int			print_float(t_printf *print, double nb)
{
	float conv;

	conv = nb;
	print_thing_to_binary_and_unsigned_char((void*)&conv, sizeof(conv));
	paste_int_in_printf(print, ft_strjoin(ft_strjoin(ft_nb_to_a((int)nb, 10), "."), ft_nb_to_a((long long)((nb - (int)nb) * 1000000), 10)));
	return (0);

}
