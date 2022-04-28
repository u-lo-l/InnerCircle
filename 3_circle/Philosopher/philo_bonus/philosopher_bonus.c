/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 21:15:34 by dkim2             #+#    #+#             */
/*   Updated: 2022/04/28 15:50:20 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

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
		if (philo->curr_fork >= philo->tab->nop)
			return (FALSE);
		sem_wait(philo->tab->forks_sem);
		philo->curr_fork++;
		if (philo->die == 1)
			return (put_fork_down(philo));
		print_log(philo, "has taken a fork");
	}
	philo->last_eat = get_ltime();
	return (TRUE);
}

void	*thread_trigger(void *vargp)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)vargp;
	while (philo->die == 0)
	{
		if (philo->last_eat + philo->tab->t2d * 1000< get_ltime() || \
			philo->tab->full_philos == philo->tab->nop)
		{
			sem_wait(philo->tab->log_sem);
			if (philo->die == 1)
				break ;
			if (philo->tab->full_philos != philo->tab->nop)
				printf("%ld %d is died\n", (get_ltime() - \
				philo->tab->start) / 1000, philo->id);
			i = -1;
			while (++i < philo->tab->nop)
				sem_post(philo->tab->die_sem);
			break ;
		}
		usleep(10);
	}
	// usleep(philo->tab->t2e * 1000);
	mili_sleep(philo->tab->t2e);
	sem_post(philo->tab->log_sem);
	return (NULL);
}

void	*thread_terminate_process(void *vargp)
{
	t_philo	*philo;

	philo = (t_philo *)vargp;
	sem_wait(philo->tab->die_sem);
	philo->die = 1;
	put_fork_down(philo);
	return (NULL);
}
