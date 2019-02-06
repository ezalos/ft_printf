/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 18:06:36 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/06 15:25:59 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

int		main(int ac, char **av)
{
	int nb;
	int r_v;
	int r_valu;

	if (ac <= 1)
		return (0);
	nb = atoi(av[1]);
	r_valu = printf("->truprintf: %d\n", nb);
	r_v = ft_printf("->ft_printf: %d\n", nb);

	printf("--tru r_val: %d\n", r_valu);
	printf("--ft_ r_val: %d\n", r_v);


	float lol;

	lol = 1/3;
	r_valu = printf("->truprintf: %f\n", lol);
	r_v = ft_printf("->ft_printf: %f\n", lol);
	return (0);
}
