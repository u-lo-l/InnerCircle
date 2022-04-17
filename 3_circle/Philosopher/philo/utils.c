/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:57:13 by dkim2             #+#    #+#             */
/*   Updated: 2022/04/17 15:28:33 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	str_error(char *str, int ret)
{
	if (str != NULL)
		printf("%s\n", str);
	return (ret);
}

int	ft_atou(char *str)
{
	int	num;

	if (str == NULL)
		return (-1);
	num = 0;
	if (*str >= '0' && *str <= '9')
	{
		while (*str != 0)
		{
			if (*str >= '0' && *str <= '9')
				num = num * 10 + *str - '0';
			else
				return (-1);
			str++;
		}
		return (num);
	}
	return (-1);
}

void	clear_table(t_table *table)
{
	int	i;

	i = -1;
	while(++i < table->nop)
		pthread_mutex_destroy(&(table->forks[i]));
	free(table->philos);
	free(table->forks);
}

void	print_log(int philosopher_id, char *message, t_mutex *mtx, long start)
{
	long	timestamp_in_ms;

	pthread_mutex_lock(mtx);
	timestamp_in_ms = get_ltime() - start;
	printf("%ld %d %s\n", timestamp_in_ms, philosopher_id, message);
	pthread_mutex_unlock(mtx);
}