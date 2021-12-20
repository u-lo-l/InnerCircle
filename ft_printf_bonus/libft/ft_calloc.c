/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:21:36 by dkim2             #+#    #+#             */
/*   Updated: 2021/12/07 20:26:06 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*temp;

	temp = malloc(size * count);
	if (size * count == 0)
		((char *)temp)[0] = 0;
	else
	{
		if (!temp)
			return (NULL);
		ft_bzero(temp, count * size);
	}
	return (temp);
}
