/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 18:06:36 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/08 19:38:34 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

int		main(int ac, char **av)
{
	int nb;
	int r_v;
	int r_valu;

	printf("->tstprintf: |%-.10d\n\n\n", 100);
	if (ac <= 1)
		return (0);
	nb = atoi(av[1]);
	r_valu = printf("->truprintf: |%X|\n", nb);
	r_v = ft_printf("->ft_printf: |%X|\n", nb);

	printf("--ft_ r_val: %d\n", r_v);
	printf("--tru r_val: %d\n", r_valu);


//	float lol;

//	lol = 1/3;
//	r_valu = printf("->truprintf: %f\n", lol);
//	r_v = ft_printf("->ft_printf: %f\n", lol);
//	return (0);
}
