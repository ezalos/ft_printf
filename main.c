/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 18:06:36 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/28 12:47:35 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/head.h"

void test0(int nb)
{
	int		r_v;
	int		r_valu;

	r_valu = printf("->truprintf: %d%c%d", nb, '\0', nb);
	r_v = ft_printf("->ft_printf: %d%c%d", nb, '\0', nb);
	printf("\n");
	printf("--ft_ r_val: %d\n", r_v);
	printf("--tru r_val: %d\n", r_valu);
	printf("\n");
	printf("\n");
}

void test1(char **av)
{
	int		r_v;
	int		r_valu;
	int		nb;
	float	nd;

	nb = atoi(av[1]);
	nd = atof(av[1]);
	r_valu = printf("->truprintf: |%c|%d%d|%s|%fcoucou|%c|%p|%c%d\n", '\0', nb, nb, av[1], nd, av[1][0], av, '\0', '\0');
	r_v = ft_printf("->ft_printf: |%c|%d%d|%s|%fcoucou|%c|%p|%c%d\n", '\0', nb, nb, av[1], nd, av[1][0], av, '\0', '\0');

	printf("\n");
	printf("--ft_ r_val: %d\n", r_v);
	printf("--tru r_val: %d\n", r_valu);
	printf("\n");
	printf("\n");
}


void test2(char **av)
{
	int		r_v;
	int		r_valu;
	int		nb;
	float	nd;

	nb = atoi(av[1]);
	nd = atof(av[1]);
	r_valu = printf("->truprintf: |%c|%d%d|%s|%fcoucou|%c|%p|%c%c%c", '\0', nb, nb, av[1], nd, av[1][0], av, '\0', '\0', '\0');
	printf("\n");
	r_v = ft_printf("->ft_printf: |%c|%d%d|%s|%fcoucou|%c|%p|%c%c%c", '\0', nb, nb, av[1], nd, av[1][0], av, '\0', '\0', '\0');
	printf("\n");

	printf("--ft_ r_val: %d\n", r_v);
	printf("--tru r_val: %d\n", r_valu);
	printf("\n");
	printf("\n");
}

int		main(int ac, char **av)
{
	int		test;
	int		nb;
	float	nd;

	if (ac <= 1)
		return (0);
	test = atoi(av[2]);
	nb = atoi(av[1]);
	nd = atof(av[1]);

	if (test == 0)
		test0(nb);
	else if (test == 1)
		test1(av);
	else if (test == 2)
		test2(av);

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
