/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:53:27 by dkim2             #+#    #+#             */
/*   Updated: 2022/04/28 14:51:10 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void	create_thread(pthread_t thread_arr[4], t_philo *philo)
{
	pthread_create(thread_arr, NULL, increase_full_philos, philo);
	pthread_create(thread_arr + 1, NULL, count_full_philos, philo);
	pthread_create(thread_arr + 2, NULL, thread_terminate_process, philo);
	pthread_create(thread_arr + 3, NULL, thread_trigger, philo);
}

static void	exit_process(pthread_t thread_arr[4], t_philo *philo)
{
	pthread_join(thread_arr[0], NULL);
	pthread_join(thread_arr[1], NULL);
	pthread_join(thread_arr[2], NULL);
	pthread_join(thread_arr[3], NULL);
	sem_close(philo->tab->log_sem);
	sem_close(philo->tab->die_sem);
	sem_close(philo->tab->eat_sem);
	sem_close(philo->tab->forks_sem);
	free(philo->tab->philo_pid);
}

void	philo_process(t_philo *philo)
{
	pthread_t	thread_arr[4];
	int			i;

	create_thread(thread_arr, philo);
	while (philo->die == 0)
	{
		if (pick_fork_up(philo) == 0 || print_log(philo, "is eating") == 0)
			break ;
		// usleep(philo->tab->t2e * 1000);
		mili_sleep(philo->tab->t2e);
		put_fork_down(philo);
		if (print_log(philo, "is sleeping") == FALSE)
			break ;
		// usleep(philo->tab->t2s * 1000);
		mili_sleep(philo->tab->t2s);
		philo->eat_count++;
		if (print_log(philo, "is thinking") == FALSE)
			break ;
	}
	put_fork_down(philo);
	i = -1;
	while (++i < philo->tab->nop)
		sem_post(philo->tab->eat_sem);
	exit_process(thread_arr, philo);
	return ;
}
