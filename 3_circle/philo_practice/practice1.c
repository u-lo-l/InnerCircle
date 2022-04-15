#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef pthread_mutex_t	t_mutex;

typedef struct	s_philo
{
	int	id;
	int	eat_cnt;
}		t_philo;

typedef struct	s_table
{
	int		num_of_philos;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		num_of_eats;
	t_mutex	*fork_mutex_arr;
	t_mutex	log_mutex;
	t_mutex	eat_mutex;
	t_philo	*philo_arr;
}			t_table;

int	init_philosophers(t_table *table, int argc, char **argv)
{
	if (!table)
		return (FALSE);
	table->num_of_philos = atoi(argv[1]);
	table->time_to_die = atoi(argv[2]);
	table->time_to_eat = atoi(argv[3]);
	table->time_to_sleep = atoi(argv[4]]);
	table->num_of_eats = 0;
	if (argc == 6)
		table->num_of_eats = atoi(argv[5]);
	
}

int	main(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (EXIT_FAILURE);
	
}