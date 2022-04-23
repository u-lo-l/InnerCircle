/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 21:15:47 by dkim2             #+#    #+#             */
/*   Updated: 2022/04/23 21:06:42 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>
#include <sys/wait.h>

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
	while (table->philo_cnt > 0)
	{
		kill(table->philos[table->philo_cnt].philo_pid, SIGTERM);
		watipid(table->philos[table->philo_cnt].philo_pid. NULL, WNOHANG);
		table->philo_cnt--;
	}
	if (table->forks_sem != SEM_FAILED)
	{
		sem_close(table->forks_sem);
		sem_unlink(FORKS_SEM_NAME);
	}
	if (table->die_sem != SEM_FAILED)
	{
		sem_close(table->die_sem);
		sem_unlink(DIE_SEM_NAME);
	}
	if (table->log_sem != SEM_FAILED)
	{
		sem_close(table->log_sem);
		sem_unlink(LOG_SEM_NAME);
	}
	free(table->philos);
}

void	print_log(t_table *table, int philosopher_id, char *message)
{
	long	timestamp;

	sem_wait(table->log_sem);
	timestamp = get_ltime() - table->start;
	if (table->die == 0)
		printf("\x1b[95m%ld\x1b[0m %d %s\n", timestamp, philosopher_id, message);
	sem_post(table->log_sem);
}
