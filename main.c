/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 18:06:36 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/19 20:23:08 by ldevelle         ###   ########.fr       */
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
** srcs/ajust_flags.c:31:		if (print->arg->space_filled == '0' && print->arg->htag &&
** srcs/ajust_flags.c:43:	if (print->arg->sign && (print->arg->type == 'd' ||
** srcs/ajust_flags.c:49:	if (print->arg->space && print->arg->type != 'c' && *str[0] != ' ' &&
** srcs/get_str_int.c:19:	if (!print->arg->precision && !print->arg->minimum_width &&
** srcs/type_float.c:98:	if (!(int_part = get_int_from_float((intmax_t)ldb, neg)) ||
** srcs/type_unsigned_integer.c:77:	if (print->last_type[0] == '0' && (print->arg->type == 'x' ||
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
int		errors_pr_p_o(void)
{
	ft_putendl("Errors: p");
	ft_printf("ft_: |%-hh50p|\n", INT_MAX);
	printf("tru: |%-hh50p|\n", INT_MAX);
	ft_putendl("");
	ft_printf("ft_: |%#.p|\n", 0);
	printf("tru: |%#.p|\n", 0);
	ft_putendl("");
	ft_putendl("Errors: o");
	ft_printf("ft_: |%-#50.5o|\n", 50);
	printf("tru: |%-#50.5o|\n", 50);
	ft_putendl("");
	ft_printf("ft_: |%#o|\n", 0);
	printf("tru: |%#o|\n", 0);
	ft_putendl("");
}
int		errors_pr_f(void)
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

int		errors_pr_c(void)
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

int		errors_pr_d_i(void)
{
	ft_putendl("Errors: i");
	ft_printf("ft_: |%hh#.2i|\n", 500);
	printf("tru: |%hh#.2i|\n", 500);
	ft_putendl("");
	ft_putendl("Errors: d");
	ft_printf("ft_: |% -0100.50d|\n", 123);
	printf("tru: |% -0100.50d|\n", 123);
	ft_putendl("");
	ft_printf("ft_: |%0100.d|\n", 123);
	printf("tru: |%0100.d|\n", 123);
	ft_putendl("");
}

int		main(void)
{
	int r_v;
	int r_valu;

	errors_pr_c();
	errors_pr_d_i();
	errors_pr_f();
	errors_pr_p_o();
	return (0);
}
