/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 03:01:17 by dkim2             #+#    #+#             */
/*   Updated: 2022/01/23 00:11:19 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_print_format(char **str, va_list ap)
{
	t_format	format_info;
	int			size;

	size = 0;
	pf_init_format(&format_info);
	pf_get_flags(str, &format_info);
	format_info.width = pf_get_count(str);
	if (**str == '.')
	{
		(*str)++;
		format_info.precision = pf_get_count(str);
	}
	size = pf_get_conversion(str, &format_info, ap);
	(*str)++;
	return (size);
}

int	ft_printf(const char *str, ...)
{
	int		ret;
	char	*temp;
	va_list	ap;

	ret = 0;
	va_start(ap, str);
	temp = (char *)str;
	while (*temp)
	{
		if (*temp == '%')
		{
			temp++;
			ret += pf_print_format(&temp, ap);
		}
		else
			ret += write(1, temp++, 1);
	}
	va_end(ap);
	return (ret);
}
