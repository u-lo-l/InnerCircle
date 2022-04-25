/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocess_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 21:15:41 by dkim2             #+#    #+#             */
/*   Updated: 2022/04/25 16:59:34 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <semaphore.h>
#include <stdio.h>
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
	table->philo_pid = malloc(sizeof(pid_t) * table->nop);
	if (table->philo_pid == NULL)
		return (FALSE);
	memset(table->philo_pid, -1, sizeof(pid_t) * table->nop);
	return (TRUE);
}

int	init_table(t_table *table)
{
	table->die = 0;
	table->start = get_ltime();
	table->philo_cnt = 0;
	sem_unlink(FORKS_SEM_NAME);
	sem_unlink(DIE_SEM_NAME);
	sem_unlink(LOG_SEM_NAME);
	table->forks_sem = sem_open(FORKS_SEM_NAME, O_CREAT, S_IRWXU, table->nop);
	table->die_sem = sem_open(DIE_SEM_NAME, O_CREAT, S_IRWXU, 0);
	table->log_sem = sem_open(LOG_SEM_NAME, O_CREAT, S_IRWXU, 1);
	if ((table->forks_sem == SEM_FAILED) || \
		(table->die_sem == SEM_FAILED) || \
		(table->log_sem == SEM_FAILED))
		return (FALSE);
	return (TRUE);
}

int	init_philosophers(t_table *table)
{
	t_philo	philo;

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

void	*thread_trigger(void *vargp)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)vargp;
	while (philo->die == 0)
	{
		if (philo->last_eat + philo->tab->t2d < get_ltime())
		{
			sem_wait(philo->tab->log_sem);
			usleep(10);
			if (philo->die == 1)
				break;
			printf("\x1b[31m%ld %d is died\x1b[0m\n", get_ltime() - philo->tab->start, philo->id);
			i = -1;
			while (++i < philo->tab->nop)
				sem_post(philo->tab->die_sem);
			break;
		}
		usleep(1000);
	}
	usleep(philo->tab->t2e * 1000);
	sem_post(philo->tab->log_sem);
	return (NULL);
}

void	*thread_terminate_process(void *vargp)
{
	t_philo	*philo;

	philo = (t_philo *)vargp;
	sem_wait(philo->tab->die_sem);
	philo->die = 1;
	return (NULL);
}

void	philo_process(t_philo	*philo)
{
	pthread_t	trig_thread;
	pthread_t	end_thread;
	// pthread_t	eat_thread;
	pthread_create(&end_thread, NULL, thread_terminate_process, philo);
	pthread_create(&trig_thread, NULL, thread_trigger, philo);
	while (philo->die == 0)
	{
		usleep(10);
		if (pick_fork_up(philo) == FALSE)
			break;
		if (print_log(philo, "\x1b[33mis eating\x1b[0m") == FALSE)
			break ;
		usleep(philo->tab->t2e * 1000);
		if (print_log(philo, "\x1b[32mis sleeping\x1b[0m") == FALSE)
			break ;
		put_fork_down(philo);
		usleep(philo->tab->t2s * 1000);
		if (print_log(philo, "\x1b[36mis thinking\x1b[0m") == FALSE)
			break ;
	}
	put_fork_down(philo);
	pthread_join(end_thread, NULL);
	pthread_join(trig_thread, NULL);
	sem_close(philo->tab->log_sem);
	sem_close(philo->tab->die_sem);
	sem_close(philo->tab->forks_sem);
	free(philo->tab->philo_pid);
	return ;
}