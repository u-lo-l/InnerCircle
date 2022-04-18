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
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

long	get_ltime(void)
{
	struct timeval	time;
	long			mili_sec;

	gettimeofday(&time, NULL);
	mili_sec = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (mili_sec);
}

int	str_error(char *str, int ret)
{
	if (str != NULL)
		printf("%s\n", str);
	return (ret);
}

long	ft_atou(char *str)
{
	long	num;

	if (str == NULL)
		return (-1);
	num = 0;
	while ((*str <= 13 && *str >= 9) || *str == 32)
		str++;
	if (*str == '+')
		str++;
	while (TRUE)
	{
		if (*str >= '0' && *str <= '9' && num >= 0)
			num = num * 10 + *str - '0';
		else
			break ;
		str++;
		if (*str == 0)
			return (num);
	}
	return (-1);
}

void	clear_table(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->nop)
	{
		pthread_join(table->philos[i].phil_thread, NULL);
		pthread_mutex_destroy(&(table->forks[i]));
	}
	free(table->philos);
	free(table->forks);
}

void	print_log(t_table *table, int philosopher_id, char *message)
{
	long	timestamp_in_ms;

	pthread_mutex_lock(&(table->log));
	timestamp_in_ms = get_ltime() - table->start;
	if (table->die == 0)
		printf("%ld %d %s\n", timestamp_in_ms, philosopher_id, message);
	pthread_mutex_unlock(&(table->log));
}
