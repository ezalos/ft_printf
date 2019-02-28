/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 18:06:36 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/28 12:08:06 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/head.h"

int		main(int ac, char **av)
{
	int		nb;
	float	nd;
	int		r_v;
	int		r_valu;
	char	*str;
	//long double x = 145634135843541100000000000000.01;

	str = ft_memalloc(3);
	str[0] = 'B';
	str[1] = 'A';
	str[2] = 'C';
	//printf("->tstprintf: |%s|%Lf|\n\n\n", str, x);
	ft_strdel(&str);
	if (ac <= 1)
		return (0);
	nb = atoi(av[1]);
	nd = atof(av[1]);
	// r_valu = printf("->truprintf: %d%d\n", nb, nb);
	// r_v = ft_printf("->ft_printf: %d%d\n", nb, nb);
	r_valu = printf("->truprintf: |%c|%d%d|%s|%fcoucou|%c|%p|%c%d\n", '\0', nb, nb, av[1], nd, av[1][0], av, '\0', '\0');
	r_v = ft_printf("->ft_printf: |%c|%d%d|%s|%fcoucou|%c|%p|%c%d\n", '\0', nb, nb, av[1], nd, av[1][0], av, '\0', '\0');

	printf("\n");
	printf("--ft_ r_val: %d\n", r_v);
	printf("--tru r_val: %d\n", r_valu);

	return (0);
}


/*
**	BUGS :
**
**	Termine par %* : size trop petite de 1;
**	avoir %*%* sans rien entre : ecrit litteralement, ou segfault
**
**
**
**
**
**
**
*/
