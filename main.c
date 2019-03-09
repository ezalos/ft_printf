/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 18:06:36 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/09 02:24:16 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/head.h"

void	ft_erur(int r_v, int r_valu)
{
	if (r_valu != r_v)
	{
		C_RED
		//ft_rgb_bcolor(255, 255, 255);
		ft_putstr(" ____    ____     ____     ____     ____ \n");
		ft_putstr("|       |    |   |    |   |    |   |    |\n");
		ft_putstr("|____   |____|   |____|   |    |   |____|\n");
		ft_putstr("|       | }      | }      |    |   | }   \n");
		ft_putstr("|       |  }     |  }     |    |   |  }  \n");
		ft_putstr("|____   |   }    |   }    |____|   |   } \n");
		C_RESET
		ft_putendl("");
		ft_putendl("");
	}
}

void test0(float nd)
{
	int		r_v;
	int		r_valu;

	r_valu = printf("tru: %f", nd);
	printf("\n");
	r_v = ft_printf("ft_: %f", nd);
	ft_putendl("");
	ft_putendl("");
	printf("--ft_ r_val: %d\n", r_v);
	printf("--tru r_val: %d\n", r_valu);
	ft_putendl("");
	ft_putendl("");
	ft_erur(r_v, r_valu);
}

void test1(float nd)
{
	int		r_v;
	int		r_valu;

	r_valu = printf("tru: %.f", nd);
	printf("\n");
	r_v = ft_printf("ft_: %.f", nd);
	ft_putendl("");
	ft_putendl("");
	printf("--ft_ r_val: %d\n", r_v);
	printf("--tru r_val: %d\n", r_valu);
	ft_putendl("");
	ft_putendl("");
	ft_erur(r_v, r_valu);
}


void test2(float nd)
{
	int		r_v;
	int		r_valu;

	r_valu = printf("tru: %#.f", nd);
	printf("\n");
	r_v = ft_printf("ft_: %#.f", nd);
	ft_putendl("");
	ft_putendl("");
	printf("--ft_ r_val: %d\n", r_v);
	printf("--tru r_val: %d\n", r_valu);
	ft_putendl("");
	ft_putendl("");
	ft_erur(r_v, r_valu);
}

void test3(float nd)
{
	int		r_v;
	int		r_valu;

	r_valu = printf("tru: %#f", nd);
	printf("\n");
	r_v = ft_printf("ft_: %#f", nd);
	ft_putendl("");
	ft_putendl("");
	printf("--ft_ r_val: %d\n", r_v);
	printf("--tru r_val: %d\n", r_valu);
	ft_putendl("");
	ft_putendl("");
	ft_erur(r_v, r_valu);
}

void test4(float nd)
{
	int		r_v;
	int		r_valu;

	r_valu = printf("tru: %.5f", nd);
	printf("\n");
	r_v = ft_printf("ft_: %.5f", nd);
	ft_putendl("");
	ft_putendl("");
	printf("--ft_ r_val: %d\n", r_v);
	printf("--tru r_val: %d\n", r_valu);
	ft_putendl("");
	ft_putendl("");
	ft_erur(r_v, r_valu);
}

void test5(float nd)
{
	int		r_v;
	int		r_valu;

	r_valu = printf("tru: %.7f", nd);
	printf("\n");
	r_v = ft_printf("ft_: %.7f", nd);
	ft_putendl("");
	ft_putendl("");
	printf("--ft_ r_val: %d\n", r_v);
	printf("--tru r_val: %d\n", r_valu);
	ft_putendl("");
	ft_putendl("");
	ft_erur(r_v, r_valu);
}

void test6(float nd)
{
	int		r_v;
	int		r_valu;

	r_valu = printf("tru: %.25f", nd);
	printf("\n");
	r_v = ft_printf("ft_: %.25f", nd);
	ft_putendl("");
	ft_putendl("");
	printf("--ft_ r_val: %d\n", r_v);
	printf("--tru r_val: %d\n", r_valu);
	ft_putendl("");
	ft_putendl("");
	ft_erur(r_v, r_valu);
}




void test7(float nd)
{
	int		r_v;
	int		r_valu;

	r_valu = printf("tru: %10.20f", nd);
	printf("\n");
	r_v = ft_printf("ft_: %10.20f", nd);
	ft_putendl("");
	ft_putendl("");
	printf("--ft_ r_val: %d\n", r_v);
	printf("--tru r_val: %d\n", r_valu);
	ft_putendl("");
	ft_putendl("");
	ft_erur(r_v, r_valu);
}




void test8(float nd)
{
	int		r_v;
	int		r_valu;

	r_valu = printf("tru: %20.10f", nd);
	printf("\n");
	r_v = ft_printf("ft_: %20.10f", nd);
	ft_putendl("");
	ft_putendl("");
	printf("--ft_ r_val: %d\n", r_v);
	printf("--tru r_val: %d\n", r_valu);
	ft_putendl("");
	ft_putendl("");
	ft_erur(r_v, r_valu);
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

	ft_rgb_color(ft_random(200, 255, test + 10, nb + 5), ft_random(200, 255, test + 1, (nb + 1) / 2), ft_random(200, 255, (test + 1) * 2, (nb + 3)));
	if (test == 0)
		test0(nd);
	else if (test == 1)
		test1(nd);
	else if (test == 2)
		test2(nd);
	else if (test == 3)
		test3(nd);
	else if (test == 4)
		test4(nd);
	else if (test == 5)
		test5(nd);
	else if (test == 6)
		test7(nd);
	else if (test == 7)
		test6(nd);
	else if (test == 8)
		test8(nd);
	C_RESET
	ft_clean_garbage();
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
