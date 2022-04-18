/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 18:10:37 by dkim2             #+#    #+#             */
/*   Updated: 2022/04/18 18:10:38 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	check_args(int argc, char **argv, t_table *table)
{
	if (argc < 5 || argc > 6)
		return (FALSE);
	table->nop = ft_atou(argv[1]);
	table->t2d = ft_atou(argv[2]);
	table->t2e = ft_atou(argv[3]);
	table->t2s = ft_atou(argv[4]);
	if (table->nop < 0 || table->t2d < 0 || table->t2e < 0 || table->t2s < 0)
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
	table->forks = malloc(sizeof(t_mutex) * table->nop);
	if (table->philos != NULL && table->forks != NULL)
	{
		table->die = 0;
		table->start = get_ltime();
		i = -1;
		while (++i < table->nop)
		{
			table->philos[i].id = i + 1;
			table->philos[i].eat_count = 0;
			table->philos[i].tab = table;
			table->philos[i].lfork = &(table->forks[i]);
			table->philos[i].rfork = &(table->forks[(i + 1) % table->nop]);
			if (pthread_mutex_init(&(table->forks[i]), NULL) != 0)
				return (FALSE);
		}
		if (pthread_mutex_init(&(table->log), NULL) == 0 && \
			pthread_mutex_init(&(table->die_check), NULL) == 0)
			return (TRUE);
	}
	return (FALSE);
}

int	init_thread(t_table *table)
{
	int		i;
	t_philo	*phil;

	i = -1;
	phil = table->philos;
	while (++i < table->nop)
	{
		phil[i].last_eat = get_ltime();
		if (pthread_create(&(phil[i].phil_thread), NULL, \
			start_dining, &(phil[i])) != 0)
			return (FALSE);
		usleep(10);
	}
	return (TRUE);
}
