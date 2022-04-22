/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:04:58 by dkim2             #+#    #+#             */
/*   Updated: 2022/04/22 05:43:35 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	*start_dining(void *vargp)
{
	t_philo	*philo;

	philo = vargp;
	while (philo->tab->die == 0)
	{
		if (pick_fork_up(philo) == NULL)
			return (NULL);
		print_log(philo->tab, philo->id, "\x1b[33mis eating\x1b[0m");
		usleep(philo->tab->t2e * 1000);
		if (philo->tab->die == 1)
			return (put_fork_down(philo->lfork, philo->rfork));
		philo->eat_count++;
		pthread_mutex_lock(&(philo->tab->eat));
		if (philo->tab->noe > 0 && (philo->eat_count == philo->tab->noe))
			philo->tab->full++;
		pthread_mutex_unlock(&(philo->tab->eat));
		print_log(philo->tab, philo->id, "\x1b[32mis sleeping\x1b[0m");
		put_fork_down(philo->lfork, philo->rfork);
		usleep(philo->tab->t2s * 1000);
		print_log(philo->tab, philo->id, "\x1b[36mis thinking\x1b[0m");
	}
	return (NULL);
}

void	check_terminate(t_table	*table)
{
	int	i;

	i = -1;
	pthread_mutex_lock(&(table->die_check));
	if (table->full == table->nop)
		table->die = 1;
	pthread_mutex_unlock(&(table->die_check));
	while (++i < table->nop && table->die == 0)
	{
		usleep(10);
		pthread_mutex_lock(&(table->die_check));
		if (table->philos[i].last_eat + table->t2d <= get_ltime())
		{
			print_log(table, table->philos[i].id, "\x1b[31mdied\x1b[0m");
			table->die = 1;
		}
		pthread_mutex_unlock(&(table->die_check));
	}
}

void	*put_fork_down(t_mutex *lfork, t_mutex *rfork)
{
	if (lfork != NULL)
		pthread_mutex_unlock(lfork);
	if (rfork != NULL)
		pthread_mutex_unlock(rfork);
	return (NULL);
}

void	*pick_fork_up(t_philo *philo)
{
	if (philo->id % 2 == 1)
	{
		pthread_mutex_lock(philo->rfork);
		if (philo->tab->die == 1 || philo->rfork == philo->lfork)
			return (put_fork_down(philo->rfork, NULL));
		print_log(philo->tab, philo->id, "\x1b[93mhas taken a fork\x1b[0m");
		pthread_mutex_lock(philo->lfork);
	}
	else
	{
		pthread_mutex_lock(philo->lfork);
		if (philo->tab->die == 1 || philo->lfork == philo->rfork)
			return (put_fork_down(philo->lfork, NULL));
		print_log(philo->tab, philo->id, "\x1b[93mhas taken a fork\x1b[0m");
		pthread_mutex_lock(philo->rfork);
	}
	if (philo->tab->die == 1)
		return (put_fork_down(philo->rfork, philo->lfork));
	print_log(philo->tab, philo->id, "\x1b[93mhas taken a fork\x1b[0m");
	philo->last_eat = get_ltime();
	return ((void *)philo);
}
