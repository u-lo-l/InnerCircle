/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 21:15:34 by dkim2             #+#    #+#             */
/*   Updated: 2022/04/21 17:58:31 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


int	start_dining(t_philo *philo)
{
	pthread_t	die_check_thread;

	printf("[%d entered the table : %d]\n", philo->id, getpid());
	pthread_create(&(die_check_thread), NULL, check_terminate, philo);
	pthread_detach(die_check_thread);
	while (philo->tab->die == 0)
	{
		if (pick_fork_up(philo) == FALSE)
			exit (2);
		print_log(philo->tab, philo->id, "\x1b[3;33mis eating\x1b[0m");
		usleep(philo->tab->t2e * 1000);
		if (philo->tab->die == 1)
		{
			put_fork_down(philo);
			exit (2);
		}
		philo->eat_count++;
		if (philo->tab->noe > 0 && (philo->eat_count == philo->tab->noe))
		{
			printf("%d enough\n", philo->id);
			philo->tab->die = 1;
			put_fork_down(philo);
			exit (2);
		}
		put_fork_down(philo);
		print_log(philo->tab, philo->id, "\x1b[32mis sleeping\x1b[0m");
		usleep(philo->tab->t2s * 1000);
		print_log(philo->tab, philo->id, "\x1b[36mis thinking\x1b[0m");
	}
	exit (1);
}

void	*check_terminate(void *vargp)
{
	t_philo	*philo;

	philo = (t_philo *)vargp;
	while (philo->tab->die == 0)
	{
		sem_wait(philo->tab->die_sem);
		// printf("check term %d\n", getpid());
		if (philo->last_eat + philo->tab->t2d <= get_ltime() || philo->tab->die == 1)
		{
			print_log(philo->tab, philo->id, "\x1b[31mdied\x1b[0m");
			philo->tab->die = 1;
			sem_post(philo->tab->die_sem);
			return (0);
		}
		sem_post(philo->tab->die_sem);
		usleep(10);
	}
	return (0);
}

int	put_fork_down(t_philo *philo)
{
	while (philo->curr_fork > 0)
	{
		sem_post(philo->tab->forks_sem);
		philo->curr_fork--;
	}
	return (FALSE);
}

int	pick_fork_up(t_philo *philo)
{
	while (philo->curr_fork < 2)
	{
		sem_wait(philo->tab->forks_sem);
		philo->curr_fork++;
		if (philo->tab->die == 1)
			return (put_fork_down(philo));
		print_log(philo->tab, philo->id, "\x1b[93mhas taken a fork\x1b[0m");
	}
	philo->last_eat = get_ltime();
	return (TRUE);
}
