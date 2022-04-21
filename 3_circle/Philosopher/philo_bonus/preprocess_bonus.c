/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocess_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 21:15:41 by dkim2             #+#    #+#             */
/*   Updated: 2022/04/21 09:13:54 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"
#include <stdlib.h>
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
	table->noe = 0;
	if (argc == 6)
	{
		table->noe = ft_atou(argv[5]);
		if (table->noe < 0)
			return (FALSE);
	}
	return (TRUE);
}

int	init_philosophers(t_table *table)
{
	int	i;

	table->philos = malloc(sizeof(t_philo) * table->nop);
	if (table->philos == NULL)
		return (FALSE);
	table->die = 0;
	table->start = get_ltime();
	table->philo_cnt = 0;
	i = -1;
	while (++i < table->nop)
	{
		table->philos[i].id = i + 1;
		table->philos[i].eat_count = 0;
		table->philos[i].tab = table;
	}
	sem_unlink(FORKS_SEM_NAME);
	sem_unlink(DIE_SEM_NAME);
	sem_unlink(LOG_SEM_NAME);
	table->forks_sem = sem_open(FORKS_SEM_NAME, O_CREAT, S_IRWXU, table->nop);
	table->die_sem = sem_open(DIE_SEM_NAME, O_CREAT, S_IRWXU, 1);
	table->log_sem = sem_open(LOG_SEM_NAME, O_CREAT, S_IRWXU, 1);
	if ((table->forks_sem == SEM_FAILED) || \
		(table->die_sem == SEM_FAILED) || \
		(table->log_sem == SEM_FAILED))
		return (FALSE);
	return (TRUE);
}

int	init_thread(t_table *table)
{
	t_philo		*philo;

	philo = table->philos;
	while (table->philo_cnt < table->nop)
	{
		philo[table->philo_cnt].last_eat = table->start;
		philo[table->philo_cnt].philo_pid = fork();
		if (philo[table->philo_cnt].philo_pid == -1)
			return (FALSE);
		if (philo[table->philo_cnt].philo_pid == 0)
			start_dining(&philo[table->philo_cnt]);
		table->philo_cnt++;
		usleep(100);
	}
	return (TRUE);
}
