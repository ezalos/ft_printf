/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 18:06:36 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/09 18:04:50 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

int		main(int ac, char **av)
{
	int		nb;
	float	nd;
	int		r_v;
	int		r_valu;

	printf("->tstprintf: |%-.10d\n\n\n", 100);
	if (ac <= 1)
		return (0);
	nb = atoi(av[1]);
	nd = atof(av[1]);
	r_valu = printf("->truprintf: |%d|%f|\n", nb, nd);
	r_v = ft_printf("->ft_printf: |%d|%f|\n", nb, nd);

	printf("--ft_ r_val: %d\n", r_v);
	printf("--tru r_val: %d\n", r_valu);

	return (0);
}
