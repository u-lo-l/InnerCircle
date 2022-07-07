/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 05:32:17 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/07 19:27:29 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	free_strset(char **strset)
{
	int	i;

	i = 0;
	while (strset[i])
		free(strset[i++]);
	free(strset);
}

static double	fractional_part(char *str)
{
	int		p;
	int		i;
	double	res;

	p = 10;
	while (ft_isspace(*str))
		str++;
	res = 0.0;
	if (ft_strlen(str) > 7)
		str[7] = '\0';
	i = 0;
	while (ft_isdigit(str[i]))
	{
		res += (double)(str[i++] - '0') / p;
		p *= 10;
	}
	if (str[i] != '\0')
		return (-1.0);
	return (res);
}

int	ft_strtod(const char *str, double *res)
{
	char	**num;
	int		int_part;
	double	frac_part;

	num = ft_split(str, ".");
	if (!num)
		return (0);
	if (num[0] == NULL || ft_strtoi(num[0], &int_part) == 0)
	{
		free_strset(num);
		return (0);
	}
	*res = (double)int_part;
	if (num[1] != NULL && num[2] == NULL)
	{
		frac_part = fractional_part(num[1]);
		if (frac_part < 0)
			return (0);
		if (*res < 0)
			*res -= frac_part;
		else
			*res += frac_part;
	}
	free_strset(num);
	return (1);
}
