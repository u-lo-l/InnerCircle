/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 21:15:47 by dkim2             #+#    #+#             */
/*   Updated: 2022/04/28 14:47:31 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>

long	get_ltime(void)
{
	struct timeval	time;
	long			mili_sec;

	gettimeofday(&time, NULL);
	mili_sec = time.tv_sec * 1000000 + time.tv_usec;
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

void	mili_sleep(long msec)
{
	long	start;

	start = get_ltime();
	while (get_ltime()< start + msec * 1000)
		usleep(20);
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
	printf("%ld %d %s\n", timestamp / 1000, philo->id, message);
	sem_post(philo->tab->log_sem);
	return (TRUE);
}
