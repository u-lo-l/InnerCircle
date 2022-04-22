/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 21:16:06 by dkim2             #+#    #+#             */
/*   Updated: 2022/04/21 17:57:16 by dkim2            ###   ########.fr       */
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

typedef pthread_mutex_t	t_mutex;

struct					s_table;

typedef struct s_philo
{
	int				id;
	int				curr_fork;
	int				eat_count;
	long			last_eat;
	struct s_table	*tab;
	pid_t			philo_pid;
	t_mutex			die_mut;
	sem_t			philo_die;
}					t_philo;

typedef struct s_table
{
	int			nop;
	int			philo_cnt;
	long		t2d;
	long		t2e;
	long		t2s;
	int			noe;
	int			die;
	long		start;
	t_philo		*philos;
	sem_t		*forks_sem;
	sem_t		*log_sem;
	sem_t		*die_sem;
	sem_t		*eat_sem;
	t_mutex		die_check;
}				t_table;

/*utils*/
long	ft_atou(char *str);
int		str_error(char *str, int ret);
void	clear_table(t_table *table);
void	print_log(t_table *table, int philosopher_id, char *message);
long	get_ltime(void);

/*preprocess*/
int		check_args(int argc, char **argv, t_table *table);
int		init_philosophers(t_table *table);
int		init_thread(t_table *table);

/*philosopher*/
int		start_dining(t_philo *philo);
void	*check_terminate(void *vargp);
int		put_fork_down(t_philo *philo);
int		pick_fork_up(t_philo *philo);

#endif
