#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define NOP 5
#define NOE 3

int	die = 0;

typedef pthread_mutex_t	t_mutex;

typedef struct	s_philo
{
	int			id;
	int			eat_count;
	t_mutex		*left;
	t_mutex		*right;
	t_mutex		*eat_mutex;
	t_mutex		*putlog_mutex;
	pthread_t	philo_thread;
}		t_philo;

typedef struct	s_table
{
	int		num_of_philos;
	int		num_of_eats;
	t_mutex	*fork_mutex_arr;
	t_mutex	eat_mutex;
	t_mutex	putlog_mutex;
	t_philo	*philo_arr;
}			t_table;

int	init_philos(t_table *table)
{
	int	i;

	table->philo_arr = malloc(sizeof(t_philo) * table->num_of_philos);
	table->fork_mutex_arr = malloc(sizeof(t_mutex) * table->num_of_philos);
	i = -1;
	while (++i < table->num_of_philos)
	{
		table->philo_arr[i].id = i + 1;
		table->philo_arr[i].eat_count = table->num_of_eats;
		if (pthread_mutex_init(&(table->fork_mutex_arr[i]), NULL) != 0)
			return (FALSE);
	}
	pthread_mutex_init(&(table->eat_mutex), NULL);
	pthread_mutex_init(&(table->putlog_mutex), NULL);
	i = -1;
	while (++i < table->num_of_philos)
	{
		table->philo_arr[i].left = &(table->fork_mutex_arr[i]);
		table->philo_arr[i].right = &(table->fork_mutex_arr[(i + 1) % table->num_of_philos]);
		table->philo_arr[i].eat_mutex = &(table->eat_mutex);
		table->philo_arr[i].putlog_mutex = &(table->putlog_mutex);
	}
	return (TRUE);
}

void	*start(void *vargp)
{
	int		i;
	t_philo	*philo;

	philo = vargp;
	i = 0;
	while (!die)
	{
		printf("id %d left<%p> right<%p>\n", philo->id, philo->left, philo->right);
		pthread_mutex_lock(philo->left);
		printf("%d get left fork\n", philo->id);
		usleep(100);
		pthread_mutex_lock(philo->right);
		printf("%d get right fork\n", philo->id);
		usleep(100);
		printf("%d starts eating : %d eats left\n", philo->id, philo->eat_count);
		sleep(2);
		printf("%d finished eating : %d eats left\n", philo->id, philo->eat_count);
		philo->eat_count--;
		if (philo->eat_count == 0)
			die = 1;
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(philo->right);
	}
	return (NULL);
}

int	init_thread(t_table *table)
{
	int i;

	i = -1;
	while (++i < table->num_of_philos)
	{
		if (pthread_create(&(table->philo_arr[i].philo_thread), \
							NULL, start, (void *)&(table->philo_arr[i])) != 0)
			return (FALSE);
		pthread_detach(table->philo_arr[i].philo_thread);
		usleep(300);
	}
	return (TRUE);
}

int	end_thread(t_table *table)
{
	int	i;
	i = -1;
	while (++i < table->num_of_philos)
		pthread_join(table->philo_arr[i].philo_thread, NULL);
	return (TRUE);
}

int	clean_table(t_table *table)
{
	int i;
	i = -1;
	while (++i < table->num_of_philos)
		pthread_mutex_destroy(&(table->fork_mutex_arr[i]));
	free(table->philo_arr);
	free(table->fork_mutex_arr);
	return (TRUE);
}

int main()
{
	t_table table;
	table.num_of_philos = NOP;
	table.num_of_eats = NOE;

	if (init_philos(&table) == FALSE)	return (FALSE);
	if (init_thread(&table) == FALSE)	return (FALSE);
	end_thread(&table);
	return (clean_table(&table));
}