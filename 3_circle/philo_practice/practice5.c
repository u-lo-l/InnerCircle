#include <unistd.h>
#include <stdio.h>
#include <sys/signal.h>
#include <sys/wait.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/time.h>
#include <time.h>
#include <string.h>
#define NUM 4
#define SEMNAME "/semname"
#define ENDSEM "/endsem"
#define LOGSEM "/logsem"

typedef pthread_mutex_t mutex_t;

struct philo;

typedef struct sem_structure
{
	struct philo *philos;
	int			pid[NUM];
	long		start;
	int			die;
	sem_t		*sem_diecheck;
	// sem_t		*sem_mutex;
	sem_t		*sem_log;
}				t_sem;

typedef struct philo
{
	int id;
	int pid;
	pthread_t tid;
	t_sem *table;
}	t_philo;

long	timestamp(void)
{
	struct timeval	tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000 + tv.tv_usec);
}

int	my_print_status(t_philo *philo, const char *str)
{
	sem_wait(philo->table->sem_log);
	if (philo->table->die == 1)
	{
		sem_post(philo->table->sem_log);
		return (0);
	}
	printf("\x1b[38;5;%dm%012ld %d %s\x1b[0m", philo->id + 31, timestamp() - philo->table->start, philo->id, str);
	sem_post(philo->table->sem_log);
	return (1);
}

void	*trigger_thread(void *vargp)
{
	t_philo *philo = vargp;
	while (1)
	{
		if (philo->table->die == 1)
			return (NULL);
		if (timestamp() - philo->table->start >= 10000 * 2 * NUM && philo->id == NUM - 4)
		{
			my_print_status(philo, "READY TO DIE\n");
			break;
		}
	}
	sem_wait(philo->table->sem_log);
	printf("\x1b[38;5;%dm%012ld <><<>>BANG<<>><> %d\x1b[0m\n", philo->id + 31, timestamp() - philo->table->start, getpid());
	int i = 0;
	while (++i <= NUM)
	{
		sem_post(philo->table->sem_diecheck);
		usleep(1);
	}
	usleep(1000);
	sem_post(philo->table->sem_log);
	return (NULL);
}

void	*clear_process(void *vargp)
{
	t_philo	*philo = (t_philo *)vargp;
	t_sem	*table = philo->table;

	int ret;

	sem_wait(table->sem_diecheck);
	table->die = 1;
	printf("\x1b[38;5;%dm[[[[[[[[[[[[[[[[[[[[%d DIE?]]]]]]]]]]]]]]]]]]]]]]]\x1b[0m\n",philo->id + 31 ,getpid());
	return (NULL);
}


void	sub_process(t_sem	*table, int num)
{
	pthread_t	trig_thread;
	pthread_t	term_thread;
	t_philo *philo = table->philos + num;

	sem_wait(philo->table->sem_log);
	printf("\x1b[38;5;%dm%d\x1b[0m\n",31 + num, getpid());
	sem_post(philo->table->sem_log);
	
	pthread_create(&(term_thread), NULL, clear_process, &(table->philos[num]));
	pthread_create(&(trig_thread), NULL, trigger_thread, &(table->philos[philo->id]));
	sem_wait(philo->table->sem_log);
	printf("\x1b[38;5;%dm%012ld %d LOOP\x1b[0m\n", 31 + num, timestamp() - table->start, getpid());
	sem_post(philo->table->sem_log);
	usleep(5000);
	for (int i = 0 ; i < 5 || philo->table->die == 0; i)
	{
		usleep(1000);
		if (my_print_status(philo, "state1\n") == 0) break;
		usleep(30000);
		if (my_print_status(philo, "state2\n") == 0) break;
		usleep(600);
		if (my_print_status(philo, "state3\n") == 0) break;
		usleep(700);
		if (my_print_status(philo, "state4\n") == 0) break;
		usleep(200);
		if (my_print_status(philo, "state5\n") == 0) break;
	}
	pthread_join(term_thread, NULL);
	pthread_join(trig_thread, NULL);
	sem_close(table->sem_diecheck);
	// sem_close(table->sem_mutex);
	sem_close(table->sem_log);
	free(table->philos);
	exit(1) ;
}

int main()
{
	t_sem	table;
	memset(&table, 0, sizeof(t_sem));
	table.die = 0;
	table.philos = malloc(sizeof(t_philo) * NUM);
	memset(table.philos, 0, sizeof(t_philo));
	table.start = timestamp();

	printf("%ld main : %d\n", table.start, getpid());

	sem_unlink(ENDSEM);
	table.sem_diecheck = sem_open(ENDSEM, O_CREAT, S_IRWXU, 0);
	sem_unlink(LOGSEM);
	table.sem_log = sem_open(LOGSEM, O_CREAT, S_IRWXU, 1);
	sem_unlink(SEMNAME);
	// table.sem_mutex = sem_open(SEMNAME, O_CREAT, S_IRWXU, 0);

	for (int i = 0 ; i  < NUM - 2; i++)
	{
		table.philos[i].id = i;
		table.philos[i].pid = fork();
		table.philos[i].table = &table;
		if (table.philos[i].pid < 0)
			return (0);
		if (table.philos[i].pid == 0)
		{
			sub_process(&table, i);
			return (0);
		}
		usleep(10000);
	}
	printf("fork done : %d\n", getpid());
	
	for (int i = 0 ; i < NUM; i++)
	{
		waitpid(table.philos[i].pid, NULL, 0);
		usleep(100);
	}
	printf("sub proc done : %d\n", getpid());

	sem_close(table.sem_diecheck);
	// sem_close(table.sem_mutex);
	sem_close(table.sem_log);
	sem_unlink(ENDSEM);
	sem_unlink(SEMNAME);
	sem_unlink(LOGSEM);
	free(table.philos);
	return (0);
}