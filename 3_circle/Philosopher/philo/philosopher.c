/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:04:58 by dkim2             #+#    #+#             */
/*   Updated: 2022/04/18 14:05:00 by dkim2            ###   ########.fr       */
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
		print_log(philo->tab, philo->id, "is eating");
		usleep(philo->tab->t2e * 1000);
		if (philo->tab->die == 1)
			return (put_fork_down(philo->lfork, philo->rfork));
		philo->eat_count++;
		if (philo->tab->noe > 0 && (philo->eat_count == philo->tab->noe))
		{
			philo->tab->die = 1;
			return (put_fork_down(philo->lfork, philo->rfork));
		}
		put_fork_down(philo->lfork, philo->rfork);
		print_log(philo->tab, philo->id, "is sleeping");
		usleep(philo->tab->t2s * 1000);
		print_log(philo->tab, philo->id, "is thinking");
	}
	return (NULL);
}

void	check_terminate(t_table	*table)
{
	int	i;

	i = -1;
	while (++i < table->nop)
	{
		pthread_mutex_lock(&(table->die_check));
		if (table->philos[i].last_eat + table->t2d <= get_ltime())
		{
			print_log(table, table->philos[i].id, "died");
			table->die = 1;
			pthread_mutex_unlock(&(table->die_check));
			break ;
		}
		pthread_mutex_unlock(&(table->die_check));
		usleep(10);
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
		print_log(philo->tab, philo->id, "has taken a fork");
		if (philo->tab->die == 1 || philo->rfork == philo->lfork)
			return (put_fork_down(philo->rfork, NULL));
		pthread_mutex_lock(philo->lfork);
	}
	else
	{
		pthread_mutex_lock(philo->lfork);
		print_log(philo->tab, philo->id, "has taken a fork");
		if (philo->tab->die == 1 || philo->lfork == philo->rfork)
			return (put_fork_down(philo->lfork, NULL));
		pthread_mutex_lock(philo->rfork);
	}
	print_log(philo->tab, philo->id, "has taken a fork");
	if (philo->tab->die == 1)
		return (put_fork_down(philo->rfork, philo->lfork));
	philo->last_eat = get_ltime();
	return ((void *)philo);
}
