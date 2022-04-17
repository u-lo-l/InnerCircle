/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:57:02 by dkim2             #+#    #+#             */
/*   Updated: 2022/04/17 15:26:56 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

t_mutex	mut;

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

	i = -1;
	while (++i < table->nop)
	{
		table->philos[i].last_eat = get_ltime();
		if (pthread_create(&(table->philos[i].phil_thread), NULL, \
							start_dining, &(table->philos[i])) != 0)
			return (FALSE);
		usleep(1000);
	}
	return (TRUE);
}

void	*start_dining(void *vargp)
{
	t_philo	*philo;
	long	gap;

	philo = vargp;
	while (philo->tab->die == 0)
	{
		gap = get_ltime() - philo->last_eat;
		printf("%d) gap : %ld\n", philo->id, gap);
		if (gap > philo->tab->t2d)
		{
			philo->tab->die = 1;
			print_log(philo->id, "died", &mut, philo->tab->start);
			return (NULL);
		}
		pthread_mutex_lock(philo->lfork);
		print_log(philo->id, "has taken a lfork", &mut, philo->tab->start);

		pthread_mutex_lock(philo->rfork);
		print_log(philo->id, "has taken a rfork", &mut, philo->tab->start);

		print_log(philo->id, "is eating", &mut, philo->tab->start);
		usleep(philo->tab->t2e * 10000);
		philo->last_eat = get_ltime();
		pthread_mutex_unlock(philo->lfork);
		pthread_mutex_unlock(philo->rfork);

		print_log(philo->id, "is sleeping", &mut, philo->tab->start);
		usleep(philo->tab->t2s * 10000);
		
		print_log(philo->id, "is thinking", &mut, philo->tab->start);
	}
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
	pthread_mutex_init(&mut, NULL);
	if (init_thread(&table) == FALSE)
		return (str_error("Error : Fail to start dining", 1));
	i = -1;
	while (++i < table.nop)
		pthread_join(table.philos[i].phil_thread, NULL);
	clear_table(&table);
	pthread_mutex_destroy(&mut);
}
