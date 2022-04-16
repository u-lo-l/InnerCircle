/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:57:02 by dkim2             #+#    #+#             */
/*   Updated: 2022/04/16 15:23:36 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

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
		i = -1;
		while (++i < table->nop)
		{
			table->philos[i].id = i + 1;
			if (pthread_mutex_init(&(table->forks[i]), NULL) == 0)
				continue;
			free(table->philos);
			free(table->forks);
			return (FALSE);
		}
		i = -1;
		while (++i < table->nop)
		{
			table->philos[i].lfork = &(table->forks[i]);
			table->philos[i].rfork = &(table->forks[(i + 1) % table->nop]);
		}
		printf("DD\n");
		if (pthread_mutex_init(&(table->log), NULL) == 0)
			return (TRUE);
	}
	free(table->philos);
	free(table->forks);
	return (FALSE);
}

int	init_thread(t_table *table)
{
	int	i;

	table->start = get_ltime();
	i = -1;
	while (++i < table->nop)
	{
		if (pthread_create(&(table->philos[i].phil_thread), \
							NULL, \
							start_dining, \
							(void *)&(table->philos[i])) != 0)
		{
			while (i >= 0)
				pthread_join(table->philos[i--].phil_thread, NULL);
			return (FALSE);
		}
		pthread_detach(table->philos[i].phil_thread);
		usleep(500);
	}

	return (TRUE);
}

void	*start_dining(void *vargp)
{
	t_philo	*philo;

	philo = (t_philo *)vargp;
	printf("%d l : %p r : %p\n", philo->id, philo->lfork, philo->rfork);
	pthread_mutex_lock(philo->lfork);
	printf("\033[0;31m %d get left fork\n\033[0m", philo->id);
	usleep(100);
	pthread_mutex_lock(philo->rfork);
	printf("\033[0;31m %d get right fork\n\033[0m", philo->id);
	usleep(100);
	printf("phil id : %d\n", philo->id);
	for (int k = 0 ; k < 4 ; k++)
	{
		printf("%d->%d\n", philo->id, k + 1);
		usleep(1000000 / 4);
	}
	pthread_mutex_unlock(philo->rfork);
	return (NULL);
}


int	main(int argc, char **argv)
{
	t_table	table;
	int		i;

	if (check_args(argc, argv, &table) == FALSE)
		return (str_error("Error : Invalid Arguments!", 1));
	if (init_philosophers(&table) == FALSE)
		return (str_error("Error : Fail to set table", 1));
	if (init_thread(&table) == FALSE)
		return (str_error("Error : Fail to start dining", 1));
	i = -1;
	while (++i < table.nop)
		pthread_join(table.philos[i].phil_thread, NULL);
	clear_table(&table);
}
