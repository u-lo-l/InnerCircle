/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 02:56:55 by dkim2             #+#    #+#             */
/*   Updated: 2021/12/21 04:42:24 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pft_init_format(t_format *f)
{
	if (f == NULL)
		return ;
	f->nbr = 0;
	f->is_minus = 0;
	f->base = 10;
	f->print_base = 0;
	f->is_digit_upper = 0;
	ft_strlcpy(f->sign_prefix, "\0", 2);
	ft_strlcpy(f->base_prefix, "\0\0", 3);
	f->blank = ' ';
	f->width = 0;
	f->precision = -1;
	f->blank_size = 0;
	f->justify = RIGHT;
}

void	pft_get_flags(char **str, t_format *f)
{
	while (**str)
	{
		if (**str == '#')
			f->print_base = 1;
		else if (**str == ' ')
		{
			if (ft_strncmp(f->sign_prefix, "+", 2))
				ft_strlcpy(f->sign_prefix, " ", 2);
		}
		else if (**str == '0')
			f->blank = '0';
		else if (**str == '-')
		{
			f->justify = LEFT;
			f->blank = ' ';
		}
		else if (**str == '+')
			ft_strlcpy(f->sign_prefix, "+", 2);
		else
			break ;
		(*str)++;
	}
}

int	pft_get_count(char **str)
{
	int	count;

	count = 0;
	while (ft_isdigit(**str))
	{
		count = count * 10 + (**str) - '0';
		(*str)++;
	}
	return (count);
}

int	pft_get_conversion(char **s, t_format *f, va_list ap)
{
	int		size;
	char	*str;

	size = 0;
	if (**s == 'd' || **s == 'i' || **s == 'u'
		|| **s == 'x' || **s == 'X' || **s == 'p')
	{
		if (pft_init_number(f, ap, **s) == 0 && **s == 'p')
			return (pft_print_string("(nil)", f));
		pft_init_base(f, **s);
		size = pft_print_num(f);
	}
	else if (**s == 'c' || **s == '%')
		size = pft_print_char(f, ap, **s);
	else if (**s == 's')
	{
		str = (char *)va_arg(ap, const char *);
		size = pft_print_string(str, f);
	}
	else
		return (-1);
	return (size);
}
