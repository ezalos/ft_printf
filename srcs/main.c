/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 18:06:36 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/12 19:45:04 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

int		main(int ac, char **av)
{
	int		nb;
	float	nd;
	int		r_v;
	int		r_valu;
	char	*str;

	str = ft_memalloc(3);
	str[0] = 'B';
	str[1] = 'A';
	str[2] = 'C';
	printf("->tstprintf: |%s|\n\n\n", str);
	ft_strdel(&str);
	if (ac <= 1)
		return (0);
	nb = atoi(av[1]);
	nd = atof(av[1]);
	r_valu = printf("->truprintf: |%d|%s|%f|\n", nb, av[1], nd);
	r_v = ft_printf("->ft_printf: |%d|%s|%f|\n", nb, av[1], nd);

	printf("--ft_ r_val: %d\n", r_v);
	printf("--tru r_val: %d\n", r_valu);

	return (0);
}
