/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 21:15:47 by dkim2             #+#    #+#             */
/*   Updated: 2022/04/26 14:51:56 by dkim2            ###   ########.fr       */
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
		waitpid(table->philo_pid[table->philo_cnt], NULL, 0);
		usleep(100);
		table->philo_cnt--;
	}
	sem_close(table->forks_sem);
	sem_close(table->die_sem);
	sem_close(table->log_sem);
	sem_close(table->eat_sem);
	sem_unlink(FORKS_SEM_NAME);
	sem_unlink(DIE_SEM_NAME);
	sem_unlink(LOG_SEM_NAME);
	sem_unlink(EAT_SEM_NAME);
	free(table->philo_pid);
}

int	print_log(t_philo *philo, char *message)
{
	long	timestamp;

	sem_wait(philo->tab->log_sem);
	if (philo->die == 1)
	{
		sem_post(philo->tab->log_sem);
		return (FALSE);
	}
	timestamp = get_ltime() - philo->tab->start;
	printf("%ld %d %s\n", timestamp, philo->id, message);
	sem_post(philo->tab->log_sem);
	return (TRUE);
}
