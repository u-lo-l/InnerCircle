/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 21:16:06 by dkim2             #+#    #+#             */
/*   Updated: 2022/04/26 20:45:36 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_BONUS_H
# define PHILOSOPHER_BONUS_H
# include <pthread.h>
# include <semaphore.h>

# define TRUE 1
# define FALSE 0
# define FORKS_SEM_NAME "/philo_bonus_forks"
# define DIE_SEM_NAME "/philo_bonus_die"
# define LOG_SEM_NAME "/philo_bonus_log"
# define EAT_SEM_NAME "/philo_bonus_eat"

typedef pthread_mutex_t	t_mutex;

typedef struct s_table
{
	int		nop;
	int		philo_cnt;
	int		full_philos;
	long	t2d;
	long	t2e;
	long	t2s;
	int		noe;
	long	start;
	pid_t	*philo_pid;
	sem_t	*forks_sem;
	sem_t	*log_sem;
	sem_t	*die_sem;
	sem_t	*eat_sem;
}			t_table;

typedef struct s_philo
{
	int		id;
	int		die;
	int		curr_fork;
	int		eat_count;
	long	last_eat;
	t_table	*tab;
}			t_philo;

/*utils*/
long	ft_atou(char *str);
int		str_error(char *str, int ret);
void	clear_table(t_table *table);
int		print_log(t_philo *philo, char *message);
long	get_ltime(void);

/*preprocess*/
int		check_args(int argc, char **argv, t_table *table);
int		init_philosophers(t_table *table);
int		init_table(t_table *table);

/*philosopher*/
int		put_fork_down(t_philo *philo);
int		pick_fork_up(t_philo *philo);
void	*thread_trigger(void *vargp);
void	*thread_terminate_process(void *vargp);

void	*increase_full_philos(void *vargp);
void	*count_full_philos(void *vargp);
void	philo_process(t_philo	*philo);

#endif
