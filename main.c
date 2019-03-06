/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 18:06:36 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/01 16:00:39 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/head.h"

void	ft_erur(int r_v, int r_valu)
{
	if (r_valu != r_v)
	{
		C_RED
		//ft_rgb_bcolor(255, 255, 255);
		ft_putendl("");
		ft_putstr(" ____    ____     ____     ____     ____ \n");
		ft_putstr("|       |    |   |    |   |    |   |    |\n");
		ft_putstr("|____   |____|   |____|   |    |   |____|\n");
		ft_putstr("|       | }      | }      |    |   | }   \n");
		ft_putstr("|       |  }     |  }     |    |   |  }  \n");
		ft_putstr("|____   |   }    |   }    |____|   |   } \n");
		C_RESET
	}
}

void test0(int nb)
{
	int		r_v;
	int		r_valu;

	r_valu = printf("->truprintf: %03.2d", -1);
	printf("\n");
	r_v = ft_printf("->ft_printf: %03.2d", -1);
	printf("\n");

	printf("\n");
	printf("--ft_ r_val: %d\n", r_v);
	printf("--tru r_val: %d\n", r_valu);
	printf("\n");
	printf("\n");
	ft_erur(r_v, r_valu);
}

void test1(char **av)
{
	int		r_v;
	int		r_valu;
	int		nb;
	float	nd;

	nb = atoi(av[1]);
	nd = atof(av[1]);
	r_valu = printf("->truprintf: |%c|%d%d|%s|%fcoucou|%c|%p|%c%d\n", '\0', nb,
	nb, av[1], nd, av[1][0], av, '\0', '\0');
	r_v = ft_printf("->ft_printf: |%c|%d%d|%s|%fcoucou|%c|%p|%c%d\n", '\0', nb,
	nb, av[1], nd, av[1][0], av, '\0', '\0');

	printf("\n");
	printf("--ft_ r_val: %d\n", r_v);
	printf("--tru r_val: %d\n", r_valu);
	printf("\n");
	printf("\n");
	ft_erur(r_v, r_valu);
}


void test2(char **av)
{
	int		r_v;
	int		r_valu;
	int		nb;
	float	nd;

	nb = atoi(av[1]);
	nd = atof(av[1]);
	r_valu = printf("->truprintf: |%c|%d%d|%s|%fcoucou|%c|%p|%c%c%c", '\0', nb,
	nb, av[1], nd, av[1][0], av, '\0', '\0', '\0');
	printf("\n");
	r_v = ft_printf("->ft_printf: |%c|%d%d|%s|%fcoucou|%c|%p|%c%c%c", '\0', nb,
	nb, av[1], nd, av[1][0], av, '\0', '\0', '\0');
	printf("\n");

	printf("\n");
	printf("--ft_ r_val: %d\n", r_v);
	printf("--tru r_val: %d\n", r_valu);
	printf("\n");
	printf("\n");
	ft_erur(r_v, r_valu);
}

void test3(char **av)
{
	int		r_v;
	int		r_valu;
	int		nb;
	size_t	lol;
	float	nd;

	nb = atoi(av[1]);
	nd = atof(av[1]);
	lol = atoi(av[1]);
	r_valu = printf("->truprintf: |%%|%%");
	printf("\n");
	r_v = ft_printf("->ft_printf: |%%|%%");
	printf("\n");

	printf("\n");
	printf("--ft_ r_val: %d\n", r_v);
	printf("--tru r_val: %d\n", r_valu);
	printf("\n");
	printf("\n");
	ft_erur(r_v, r_valu);
}

void test4(char **av)
{
	int		r_v;
	int		r_valu;
	int		nb;
	size_t	lol;
	float	nd;

	nb = atoi(av[1]);
	nd = atof(av[1]);
	lol = atoi(av[1]);
	r_valu = printf("->truprintf: |%10c|%%|%c", av[1][0], '\0');
	printf("\n");
	r_v = ft_printf("->ft_printf: |%10c|%%|%c", av[1][0], '\0');
	printf("\n");

	printf("\n");
	printf("--ft_ r_val: %d\n", r_v);
	printf("--tru r_val: %d\n", r_valu);
	printf("\n");
	printf("\n");
	ft_erur(r_v, r_valu);
}

void test5(char **av)
{
	int		r_v;
	int		r_valu;
	int		nb;
	size_t	lol;
	float	nd;

	nb = atoi(av[1]);
	nd = atof(av[1]);
	lol = atoi(av[1]);
	r_valu = printf("->truprintf: |%.25s|%%", av[1]);
	printf("\n");
	r_v = ft_printf("->ft_printf: |%.25s|%%", av[1]);
	printf("\n");

	printf("\n");
	printf("--ft_ r_val: %d\n", r_v);
	printf("--tru r_val: %d\n", r_valu);
	printf("\n");
	printf("\n");
	ft_erur(r_v, r_valu);
}

void test6(void)
{
	ft_printf("%   %", "test");
	ft_putendl("");
	ft_printf("%-15x", 542);
	ft_putendl("");
	ft_printf("%#x", 42);
	ft_putendl("");
	ft_printf("%#llx", 9223372036854775807);
	ft_putendl("");
	ft_printf("%#x", 42);
	ft_putendl("");
	ft_printf("%#X", 42);
	ft_putendl("");
	ft_printf("%#8x", 42);
	ft_putendl("");
	ft_printf("plop\n");
	ft_printf("%#08x", 42);
	ft_putendl("");
	ft_printf("%#-08x", 42);
	ft_putendl("");
	ft_printf("@moulitest: %#.x %#.0x", 0, 0);
	ft_putendl("");
	ft_printf("@moulitest: %.x %.0x", 0, 0);
	ft_putendl("");
	ft_printf("@moulitest: %5.x %5.0x", 0, 0);
	ft_putendl("");
	ft_printf("%10s is a string", "this");
	ft_putendl("");
	ft_printf("%.2s is a string", "this");
	ft_putendl("");
	ft_printf("%5.2s is a string", "this");
	ft_putendl("");
	ft_printf("%10s is a string", "");
	ft_putendl("");
	ft_printf("%.2s is a string", "");
	ft_putendl("");
	ft_printf("%5.2s is a string", "");
	ft_putendl("");
	ft_printf("%-10s is a string", "this");
	ft_putendl("");
	ft_printf("%-.2s is a string", "this");
	ft_putendl("");
	ft_printf("%-5.2s is a string", "this");
	ft_putendl("");
	ft_printf("%-10s is a string", "");
	ft_putendl("");
	ft_printf("%-.2s is a string", "");
	ft_putendl("");
	ft_printf("%-5.2s is a string", "");
	ft_putendl("");
	ft_printf("@moulitest: %s", NULL);
	ft_putendl("");
	ft_printf("%s %s", NULL, "string");
	ft_putendl("");
	ft_printf("%2c", 0);
	ft_putendl("");
	ft_printf("% c", 0);
	ft_putendl("");
	ft_printf("%#6o", 2500);
	ft_putendl("");
	ft_printf("%-#6o", 2500);
	ft_putendl("vlobk,gmfy6bhds5zvgwyahvhyahyvy");
	ft_printf("------------------@moulitest: %#.o %#.0o", 0, 0);
	ft_putendl("");
	ft_printf("@moulitest: %.o %.0o", 0, 0);
	ft_putendl("");
	ft_printf("@moulitest: %5.o %5.0o", 0, 0);
	ft_putendl("");
	ft_printf("% d", 42);
	ft_putendl("");
	ft_printf("% d", -42);
	ft_putendl("");
	ft_printf("%+d", 42);
	ft_putendl("");
	ft_printf("%+d", 0);
	ft_putendl("");
	ft_printf("% +d", 42);
	ft_putendl("");
	ft_printf("% +d", -42);
	ft_putendl("");
	ft_printf("%+ d", 42);
	ft_putendl("");
	ft_printf("%+ d", -42);
	ft_putendl("");
	ft_printf("%  +d", 42);
	ft_putendl("");
	ft_printf("%  +d", -42);
	ft_putendl("");
	ft_printf("%+  d", 42);
	ft_putendl("");
	ft_printf("%+  d", -42);
	ft_putendl("");
	ft_printf("% ++d", 42);
	ft_putendl("");
	ft_printf("% ++d", -42);
	ft_putendl("");
	ft_printf("%++ d", 42);
	ft_putendl("");
	ft_printf("%++ d", -42);
	ft_putendl("");
	ft_printf("%0+5d", 42);
	ft_putendl("");
	ft_printf("%5d", -42);
	ft_putendl("");
	ft_printf("%05d", -42);
	ft_putendl("");
	ft_printf("%0+5d", -42);
	ft_putendl("");
	ft_printf("%-5d", -42);
	ft_putendl("");
	ft_printf("%-05d", -42);
	ft_putendl("");
	ft_printf("%4.15d", 42);
	ft_putendl("");
	ft_printf("% 10.5d", 4242);
	ft_putendl("");
	ft_printf("%+10.5d", 4242);
	ft_putendl("");
	ft_printf("%-+10.5d", 4242);
	ft_putendl("");
	ft_printf("%03.2d", -1);
	ft_putendl("");
	ft_printf("@moulitest: %.d %.0d", 0, 0);
	ft_putendl("");
	ft_printf("@moulitest: %5.d %5.0d", 0, 0);
	ft_putendl("");
	ft_printf("%15u", 4294967295);
	ft_putendl("");
	ft_printf("%-15u", 4294967295);
	ft_putendl("");
	ft_printf("%015u", 4294967295);
	ft_putendl("");
	ft_printf("% u", 4294967295);
	ft_putendl("");
	ft_printf("%U", 4294967295);
	ft_putendl("");
	ft_printf("%hU", 4294967296);
	ft_putendl("");
	ft_printf("%U", 4294967296);
	ft_putendl("");
}




void test7(char **av)
{
	int		r_v;
	int		r_valu;
	int		nb;
	size_t	lol;
	float	nd;

	nb = atoi(av[1]);
	nd = atof(av[1]);
	lol = atoi(av[1]);
	r_valu = printf("->truprintf: %-15x|", 542);
	printf("\n");
	r_v = ft_printf("->ft_printf: %-15x|", 542);
	printf("\n");

	printf("\n");
	printf("--ft_ r_val: %d\n", r_v);
	printf("--tru r_val: %d\n", r_valu);
	printf("\n");
	printf("\n");
	ft_erur(r_v, r_valu);
}




void test8(char **av)
{
	int		r_v;
	int		r_valu;
	int		nb;
	size_t	lol;
	float	nd;

	nb = atoi(av[1]);
	nd = atof(av[1]);
	lol = atoi(av[1]);
	r_valu = printf("->truprintf: %#015x|", 542);
	printf("\n");
	r_v = ft_printf("->ft_printf: %#015x|", 542);
	printf("\n");

	printf("\n");
	printf("--ft_ r_val: %d\n", r_v);
	printf("--tru r_val: %d\n", r_valu);
	printf("\n");
	printf("\n");
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
	//test = -1;
	nb = atoi(av[1]);
	nd = atof(av[1]);

	printf("\n");
	printf("\n");






	printf("|% 020.5d|\n", 5);


	ft_rgb_color(ft_random(200, 255, test + 10, nb + 5), ft_random(200, 255, test + 1, (nb + 1) / 2), ft_random(200, 255, (test + 1) * 2, (nb + 3)));
	if (test == 0)
		test0(nb);
	else if (test == 1)
		test1(av);
	else if (test == 2)
		test2(av);
	else if (test == 3)
		test3(av);
	else if (test == 4)
		test4(av);
	else if (test == 5)
		test5(av);
	else if (test == 6)
		test7(av);
	else if (test == 7)
		test6();
	else if (test == 8)
		test8(av);
	C_RESET
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
