/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 18:06:36 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/19 20:35:02 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "head.h"
#include "math.h"
#include "stdio.h"

/*
** while 1; do leaks a.out; sleep 1; clear; done
*/

/*
** grep -n "[&|+-]$" srcs
*/

/*
** ft_printf("ft_: |%-3c|\n", 0);
** ft_printf("ft_: |%-#50.5o|\n", 50);
** ft_printf("ft_: |%#o|\n", 0);
** ft_printf("ft_: |%hh#.2i|\n", 500);
** ft_printf("ft_: |%-hh50p|\n", INT_MAX);
** ft_printf("ft_: |%#.p|\n", 0);
** ft_printf("ft_: |%.f|\n", 0.5);
** ft_printf("ft_: |%.1f|\n", 0.5);
** ft_printf("ft_: |%-12.5f|\n", 0.5);
** ft_printf("ft_: |%+12.5f|\n", 0.5);
** ft_printf("ft_: |%012.5f|\n", 0.5);
** ft_printf("ft_: |%5.2%|\n");
** ft_printf("ft_: |%05.2%|\n");
** ft_printf("ft_: |%+-05.2%|\n");
** ft_printf("ft_: |% -0100.50d|\n", 123);
** ft_printf("ft_: |%0100.d|\n", 123);
*/

void	errors_pr_p_o(void)
{
	ft_putendl("Errors: p");
	ft_printf("ft_: |%-hh.10p|\n", INT_MAX);
	printf("tru: |%-hh.10p|\n", INT_MAX);
	ft_putendl("");
	ft_printf("{% 03d}\n", 0);
	printf("{% 03d}\n", 0);
	ft_printf("{% 03d}\n", 10);
	printf("{% 03d}\n", 10);
	ft_putendl("");
	ft_putendl("Errors: o");
	ft_printf("ft_: |%-#50.5o|\n", 50);
	printf("tru: |%-#50.5o|\n", 50);
	ft_putendl("");
	ft_printf("ft_: |%#o|\n", 0);
	printf("tru: |%#o|\n", 0);
	ft_putendl("");
}

void		errors_pr_f(void)
{
	ft_putendl("Errors: f");
	ft_printf("ft_: |%.f|\n", 0.5);
	printf("tru: |%.f|\n", 0.5);
	ft_putendl("");
	ft_printf("ft_: |%.1f|\n", 0.5);
	printf("tru: |%.1f|\n", 0.5);
	ft_putendl("");
	ft_printf("ft_: |%-12.5f|\n", 0.5);
	printf("tru: |%-12.5f|\n", 0.5);
	ft_putendl("");
	ft_printf("ft_: |%+12.5f|\n", 0.5);
	printf("tru: |%+12.5f|\n", 0.5);
	ft_putendl("");
	ft_printf("ft_: |%012.5f|\n", 0.5);
	printf("tru: |%012.5f|\n", 0.5);
	ft_putendl("");
}

void	errors_pr_c(void)
{
	ft_putendl("Errors: c");
	ft_printf("ft_: |%-3c|\n", 0);
	printf("tru: |%-3c|\n", 0);
	ft_putendl("");
	ft_printf("ft_: |%5.2%|\n");
	printf("tru: |%5.2%|\n");
	ft_putendl("");
	ft_printf("ft_: |%05.2%|\n");
	printf("tru: |%05.2%|\n");
	ft_putendl("");
	ft_printf("ft_: |%+-05.2%|\n");
	printf("tru: |%+-05.2%|\n");
	ft_putendl("");
}

void		errors_pr_d_i(void)
{
	ft_putendl("Errors: i");
	ft_printf("ft_: |%hh#.2i|\n", 500);
	printf("tru: |%hh#.2i|\n", 500);
	ft_putendl("");
	ft_putendl("Errors: d");
	ft_printf("ft_: |% -011.10d|\n", 123);
	printf("tru: |% -011.10d|\n", 123);
	ft_putendl("");
	ft_printf("ft_: |%0100.d|\n", 123);
	printf("tru: |%0100.d|\n", 123);
	ft_putendl("");
	ft_putendl("MOLITEST");
	ft_putendl("");
	ft_printf("{%.*s}\n", -1, "42");
	printf("{%.*s}\n", -1, "42");
	ft_putendl("");
	ft_printf("{%05.*d}\n", -15, 42);
	printf("{%05.*d}\n", -15, 42);
	ft_putendl("");
	ft_printf("{%*d}\n", -5, 42);
	printf("{%*d}\n", -5, 42);
	ft_putendl("");
	ft_putendl("");
}

int		main(void)
{
	errors_pr_c();
	errors_pr_d_i();
	errors_pr_f();
	errors_pr_p_o();
	return (0);
}
