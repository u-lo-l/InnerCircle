/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocess_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 21:15:41 by dkim2             #+#    #+#             */
/*   Updated: 2022/04/26 14:55:36 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <semaphore.h>

int	check_args(int argc, char **argv, t_table *table)
{
	if (argc < 5 || argc > 6)
		return (FALSE);
	table->nop = ft_atou(argv[1]);
	table->t2d = ft_atou(argv[2]);
	table->t2e = ft_atou(argv[3]);
	table->t2s = ft_atou(argv[4]);
	if (table->nop <= 0 || table->t2d < 0 || table->t2e < 0 || table->t2s < 0)
		return (FALSE);
	table->noe = -1;
	if (argc == 6)
	{
		table->noe = ft_atou(argv[5]);
		if (table->noe < 0)
			return (FALSE);
	}
	table->philo_pid = malloc(sizeof(pid_t) * table->nop);
	if (table->philo_pid == NULL)
		return (FALSE);
	memset(table->philo_pid, -1, sizeof(pid_t) * table->nop);
	return (TRUE);
}

int	init_table(t_table *table)
{
	table->start = get_ltime();
	table->philo_cnt = 0;
	sem_unlink(FORKS_SEM_NAME);
	sem_unlink(DIE_SEM_NAME);
	sem_unlink(LOG_SEM_NAME);
	sem_unlink(EAT_SEM_NAME);
	table->forks_sem = sem_open(FORKS_SEM_NAME, O_CREAT, S_IRWXU, table->nop);
	table->die_sem = sem_open(DIE_SEM_NAME, O_CREAT, S_IRWXU, 0);
	table->log_sem = sem_open(LOG_SEM_NAME, O_CREAT, S_IRWXU, 1);
	table->eat_sem = sem_open(EAT_SEM_NAME, O_CREAT, S_IRWXU, 0);
	if ((table->forks_sem == SEM_FAILED) || \
		(table->die_sem == SEM_FAILED) || \
		(table->log_sem == SEM_FAILED) || \
		(table->eat_sem == SEM_FAILED))
		return (FALSE);
	return (TRUE);
}

int	init_philosophers(t_table *table)
{
	t_philo	philo;

	if (table->noe == 0)
		return (TRUE);
	philo.die = 0;
	philo.curr_fork = 0;
	philo.eat_count = 0;
	philo.last_eat = table->start;
	philo.tab = table;
	while (table->philo_cnt < table->nop)
	{
		table->philo_pid[table->philo_cnt] = fork();
		if (table->philo_pid[table->philo_cnt] < 0)
			return (FALSE);
		else if (table->philo_pid[table->philo_cnt] == 0)
		{
			philo.id = table->philo_cnt + 1;
			philo_process(&philo);
			exit (TRUE);
		}
		table->philo_cnt++;
		usleep(10);
	}
	return (TRUE);
}

void	*increase_full_philos(void *vargp)
{
	t_philo	*philo;

	philo = (t_philo *)vargp;
	if (philo->tab->noe < 0)
		return (NULL);
	while (philo->tab->full_philos < philo->tab->nop)
	{
		sem_wait(philo->tab->eat_sem);
		if (philo->die == 1)
			return (NULL);
		philo->tab->full_philos++;
		usleep(100);
	}
	return (NULL);
}

void	*count_full_philos(void *vargp)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)vargp;
	if (philo->tab->noe < 0)
		return (NULL);
	while (philo->die == 0)
	{
		if (philo->eat_count != philo->tab->noe)
			continue ;
		i = -1;
		while (++i < philo->tab->nop)
			sem_post(philo->tab->eat_sem);
		usleep(100);
		return (NULL);
	}
	return (NULL);
}
