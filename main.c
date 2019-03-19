/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 18:06:36 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/19 16:30:37 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "head.h"
#include "math.h"

/*
** grep -n "[&|+-]$" srcs
** srcs/ajust_flags.c:31:		if (print->arg->space_filled == '0' && print->arg->htag &&
** srcs/ajust_flags.c:43:	if (print->arg->sign && (print->arg->type == 'd' ||
** srcs/ajust_flags.c:49:	if (print->arg->space && print->arg->type != 'c' && *str[0] != ' ' &&
** srcs/get_str_int.c:19:	if (!print->arg->precision && !print->arg->minimum_width &&
** srcs/type_float.c:98:	if (!(int_part = get_int_from_float((intmax_t)ldb, neg)) ||
** srcs/type_unsigned_integer.c:77:	if (print->last_type[0] == '0' && (print->arg->type == 'x' ||
*/

//ft_printf("ft_: |%-3c|\n", 0);
//ft_printf("ft_: |%-#50.5o|\n", 50);
//ft_printf("ft_: |%#o|\n", 0);
//ft_printf("ft_: |%hh#.2i|\n", 500);
//ft_printf("ft_: |%-hh50p|\n", INT_MAX);
//ft_printf("ft_: |%#.p|\n", 0);
//ft_printf("ft_: |%.f|\n", 0.5);
//ft_printf("ft_: |%.1f|\n", 0.5);
//ft_printf("ft_: |%-12.5f|\n", 0.5);
//ft_printf("ft_: |%+12.5f|\n", 0.5);
//ft_printf("ft_: |%012.5f|\n", 0.5);
//ft_printf("ft_: |%5.2%|\n");
//ft_printf("ft_: |%05.2%|\n");
//ft_printf("ft_: |%+-05.2%|\n");
//ft_printf("ft_: |% -0100.50d|\n", 123);
//ft_printf("ft_: |%0100.d|\n", 123);

int		main(void)
{
	int r_v;
	int r_valu;
	r_v = ft_printf("ft_: |%0100.d|\n", 123);
	//r_valu = printf("tru: |%0100.d|\n", 123);
	//printf("printf: = %d, ft_printf = %d\n", r_valu, r_v);
	while (1);
	C_RESET
	return (0);
}
