/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_gestion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 19:44:59 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/11 21:00:07 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

char			*ft_str_place_cursor(size_t line, size_t column)
{
	char		*string;
	char		*tmp;
	char		*nb;

	if (!(nb = ft_nb_to_a(line, 10)))
		return (0);
	if (!(string = ft_strjoin("\033[", nb)))
		return (0);
	ft_strdel(&nb);
	if (!(tmp = ft_strjoin(string, ";")))
		return (0);
	ft_strdel(&string);
	if (!(nb = ft_nb_to_a(column, 10)))
		return (0);
	if (!(string = ft_strjoin(tmp, nb)))
		return (0);
	ft_strdel(&nb);
	ft_strdel(&tmp);
	if (!(tmp = ft_strjoin(string, "H")))
		return (0);
	ft_strdel(&string);
	return (tmp);
}

char			*ft_str_rgbcolor(char background, int red, int green, int blue)
{
	char		*color;
	char		*s_red;
	char		*s_green;
	char		*s_blue;

	if (!(s_red = ft_nb_to_a(red, 10)))
		return (NULL);
	if (!(s_green = ft_nb_to_a(green, 10)))
		return (NULL);
	if (!(s_blue = ft_nb_to_a(blue, 10)))
		return (NULL);
	if (background)
	{
		if (!(color = ft_strjoin_multi(7, "\x1b[48;2;", s_red, ";", s_green, ";", s_blue, "m")))
			return (NULL);
	}
	else
		if (!(color = ft_strjoin_multi(7, "\x1b[38;2;", s_red, ";", s_green, ";", s_blue, "m")))
			return (NULL);
	ft_strdel(&s_green);
	ft_strdel(&s_blue);
	ft_strdel(&s_red);
	return (color);
}

static char	*ft_move_cursor_dir(size_t quantity, const char dir)
{
	char	*nb;
	char	*to_print;

	if (!(nb = ft_nb_to_a(quantity, 10)))
		return (0);
	if (!(to_print = ft_strjoin_multi(3, "\033[", nb, &dir)))
		return (0);
	write(1, to_print, ft_strlen(to_print));
	ft_strdel(&nb);
	return (to_print);
}

char		*ft_move_cursor(size_t up, size_t down, size_t right, size_t left)
{
	char	*str;

	str = NULL;
		if (up)
			if (!(str = ft_move_cursor_dir(up, 'A')))
				return (0);
		if (down)
			if (!(str = ft_move_cursor_dir(up, 'B')))
				return (0);
		if (right)
			if (!(str = ft_move_cursor_dir(up, 'C')))
				return (0);
		if (left)
			if (!(str = ft_move_cursor_dir(up, 'D')))
				return (0);
	return (str);
}

int		we_need_to_move_cursor(t_printf *print, const char **f, int mode)
{
	char	*str;
	int		tmp;

	str = NULL;
	if (**f == '|')
		(*f)++;
	while (**f != '|' && mode--)
	{
		if (**f == '*' || ft_isdigit(**f))
			get_value_of_star_or_nb(print, f, &tmp);
		else
			tmp = 1;
		if (**f == '^')
		{
			if (!(str = ft_move_cursor(tmp, 0, 0, 0)))
				return (-1);
			if (!get_printf(print, &str, ft_strlen(str)))
				return (-1);
		}
		else if (**f == 'v')
		{
			if (!(str = ft_move_cursor(0, tmp, 0, 0)))
				return (-1);
			if (!get_printf(print, &str, ft_strlen(str)))
				return (-1);
		}
		else if (**f == '>')
		{
			if (!(str = ft_move_cursor(0, 0, tmp, 0)))
				return (-1);
			if (!get_printf(print, &str, ft_strlen(str)))
				return (-1);
		}
		else if (**f == '<')
		{
			if (!(str = ft_move_cursor(0, 0, 0, tmp)))
				return (-1);
			if (!get_printf(print, &str, ft_strlen(str)))
				return (-1);
		}
		(*f)++;
	}
	if (**f == '|')
		(*f)++;
	return (0);
}

int		cursor_gestion(t_printf *print, const char **f)
{
	char	*str;

	str = NULL;
	(*f)++;
	if (**f == 's')
		CURSOR_SAVE
	else if (**f == 'l')
		CURSOR_LOAD
	else if (**f == 'r')
		CURSOR_RESET
	else if (**f == '|')
		we_need_to_move_cursor(print, f, -1);
	else if (ft_char_srch(**f, "^v<>"))
		we_need_to_move_cursor(print, f, 1);
	else if (**f == '(')
	{
		(*f)++;
		get_value_of_star_or_nb(print, f, &print->bonus->line);
		while (**f != ';')
			(*f)++;
		(*f)++;
		get_value_of_star_or_nb(print, f, &print->bonus->column);
		while (**f != ')')
			(*f)++;
		(*f)++;
		if (!(str = ft_str_place_cursor(print->bonus->line, print->bonus->column)))
			return (-1);
		if (!get_printf(print, &str, ft_strlen(str)))
			return (-1);
		return (0);
	}
	(*f)++;
	return (0);
}

int		color_gestion(t_printf *print, const char **f)
{
	char	*str;

	str = NULL;
	(*f)++;
	if (**f == 'b')
	{
		print->bonus->background = 1;
		(*f)++;
	}
	if (**f == '}')
	{
		if (!(str = ft_strdup("\x1b[0m")))
			return (-1);
		(*f)++;
		if (!get_printf(print, &str, ft_strlen(str)))
			return (-1);
		return (0);
	}
	if (**f == '?')
	{
		(*f)++;
		if (**f == 's')
		{
			(*f)++;
			get_value_of_star_or_str(print, f, &print->bonus->rand_str);
		}
		else if (**f == '}')
		{
			print->bonus->red = ft_random(0, 255, 0, 0);
			print->bonus->green = ft_random(0, 255, 0, 0);
			print->bonus->blue = ft_random(0, 255, 0, 0);
			if (!(str = ft_str_rgbcolor(print->bonus->background, print->bonus->red, print->bonus->green, print->bonus->blue)))
				return (-1);
			(*f)++;
			if (!get_printf(print, &str, ft_strlen(str)))
				return (-1);
		}
		else
		{
			get_value_of_star_or_nb(print, f, &print->bonus->rand_nb);
			if (!print->bonus->rand_nb)
				print->bonus->rand_nb++;
			print->bonus->red = ft_random(0, 255, (print->bonus->rand_nb * 3), 25);
			print->bonus->green = ft_random(0, 255, (print->bonus->rand_nb * 5), 2);
			print->bonus->blue = ft_random(0, 255, (print->bonus->rand_nb * 7), 5);
			if (!(str = ft_str_rgbcolor(print->bonus->background, print->bonus->red, print->bonus->green, print->bonus->blue)))
				return (-1);
			(*f)++;
			if (!get_printf(print, &str, ft_strlen(str)))
				return (-1);
		}
	}
	else
	{
		get_value_of_star_or_nb(print, f, &print->bonus->red);
		while (**f != ';')
			(*f)++;
		(*f)++;
		get_value_of_star_or_nb(print, f, &print->bonus->green);
		while (**f != ';')
			(*f)++;
		(*f)++;
		get_value_of_star_or_nb(print, f, &print->bonus->blue);
		while (**f != '}')
			(*f)++;
		(*f)++;
		if (!(str = ft_str_rgbcolor(print->bonus->background, print->bonus->red, print->bonus->green, print->bonus->blue)))
			return (-1);
		//printf("\n%s\n", str);
		if (!get_printf(print, &str, ft_strlen(str)))
			return (-1);
		return (0);
	}
	return (0);
}

size_t	ft_strputtab_len(size_t length, size_t separation, size_t n)
{
	size_t		tab;

	if (n == 0)
		n = 1;
	tab = 0;
	while (tab + length < separation * n)
		tab += n;
	return (tab);
}

size_t	ft_strputtab(const char *s, size_t separation)
{
	if (!s)
		return (0);
	return (ft_strputtab_len(ft_strlen(s), separation, 1));
}
char	*get_string_from_str_tab(t_printf *print, char ***str, int longest)
{
	char	*to_print;
	int		i;
	int		j;

	i = (print->bonus->line * print->bonus->column * longest) + print->bonus->line;
	to_print = ft_memalloc(i + 1);
	ft_memset(to_print, ' ', i);
	to_print[i] = 0;
	i = -1;
	while (++i < print->bonus->line)
	{
		j = -1;
		if (str[i])
		{
			while (++j < print->bonus->column)
			{
				if (str[i][j])
				{
					ft_memmove(to_print + (i * print->bonus->column * longest) + (j * longest) + i,
				 	str[i][j], ft_strlen(str[i][j]));
				}
				else
					break;
			}
			to_print[(i * print->bonus->column * longest) + (print->bonus->column * longest) + i] = '\n';
		}
		else
			break;
	}
	to_print[(i * print->bonus->column * longest) + i] = 0;
	return (to_print);
}

int		tab_gestion(t_printf *print, const char **f)
{
	char	*to_print;
	char	***str;
	int		longest;
	int		i;
	int		j;

	str = NULL;
	(*f)++;
	get_value_of_star_or_nb(print, f, &print->bonus->line);
	while (**f != ';')
		(*f)++;
	(*f)++;
	get_value_of_star_or_nb(print, f, &print->bonus->column);
	(*f)++;
	longest = -1;
	if (**f == 's' && print->bonus->line && print->bonus->column)
	{
		str = va_arg(print->ap, char***);
		if (!str)
			return (0);
		i = -1;
		while (++i < print->bonus->line)
		{
			j = -1;
			if (str[i])
				while (++j < print->bonus->column)
				{
					if (str[i][j])
					{
						if (longest <= (int)ft_strlen(str[i][j]))
							longest = ft_strlen(str[i][j]);
					}
					else
						j = print->bonus->column;
				}
			else
				i = print->bonus->line;
		}
		to_print = get_string_from_str_tab(print, str, longest + 1);
		(*f)++;
		if (!get_printf(print, &to_print, ft_strlen(to_print)))
			return (-1);
		return (0);
	}
	(*f)++;
	return (0);

}

int		bonus_gestion(t_printf *print, const char **f)
{
	ft_bzero(print->bonus, sizeof(print->bonus));
	(*f)++;
	print->bonus->exist = **f;
	if (**f == '>')
		cursor_gestion(print, f);
	else if (**f == '{')
		color_gestion(print, f);
	else if (**f == '[')
		tab_gestion(print, f);
	return (0);
}
