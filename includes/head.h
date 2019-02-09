/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 18:06:30 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/09 14:44:40 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

# include <stdarg.h>
# include <stdio.h>
# include "../../libft/libft.h"

typedef struct		s_arg
{
	char			type;
	int				minimum_width;
	int				ajust_left;
	char			space_filled;
	int				sign;
	int				htag;
	int				precision;
	int				modifier_h;
	int				modifier_l;
	int				modifier_L;
}					t_arg;

typedef struct			s_printf
{
	const char 			*format;
	char				*start_format;
	va_list 			ap;
	char				*printf;
	char				*last_type;
	char				lets_print;
	int					i;
	size_t				size_all;
	t_arg				arg[1];
}						t_printf;

# define M_PRTC(x) 		if (!x) return (NULL);

# define OFFPTION

# ifdef ONPTION
#  include <stdio.h>
#  define OPTION	1
#  define _RED		"\x1b[31m"
#  define _GREEN	"\x1b[32m"
#  define _YELLOW	"\x1b[33m"
#  define _BLUE		"\x1b[34m"
#  define _MAGENTA	"\x1b[35m"
#  define _CYAN		"\x1b[36m"
#  define _RESET	"\x1b[0m"
# endif

# ifdef OFFPTION
#  define OPTION	0
#  define _RED		""
#  define _GREEN	""
#  define _YELLOW	""
#  define _BLUE		""
#  define _MAGENTA	""
#  define _CYAN		""
#  define _RESET	""
# endif

//PRINTF
int			ft_printf(const char *format, ...);

//INIT
void		init_struct_arg(t_printf *print, const char *format);
int			init_struct(t_printf *print, const char *format);

//OPTIONS
int			printf_minlength_and_precision(t_printf *print, int i);
int			printf_flags(t_printf *print, int i);
int			printf_options(t_printf *print, int i);

//PARSING
int			parsing(t_printf *print, va_list ap);

//TYPES
int			print_unsigned_integer(t_printf *print, uintmax_t nb);
int			print_pointer(t_printf *print, void* ptr);
int			print_float(t_printf *print, long double nb);
int			print_string(t_printf *print, char *str);
int			print_integer(t_printf *print, intmax_t nb);
int			print_character(t_printf *print, char *str);
int			print_others(t_printf *print, void *str);

//MALLOC AND MOVE
int			paste_format_in_printf(t_printf *print);
int			paste_int_in_printf(t_printf *print, char *str);
int			paste_str_in_printf(t_printf *print, char *str);

//CHEACK_ARGS
void		check_flags(const char c, t_arg *arg);
void		check_minimum_width_or_precision(const char **f, t_arg *arg);
void		check_modifier(const char **f, t_arg *arg);
void		check_arg(const char **f, t_arg *arg);

//OUTPUT
int			output_string(t_printf *print);

#endif
