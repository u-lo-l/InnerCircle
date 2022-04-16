/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:57:32 by dkim2             #+#    #+#             */
/*   Updated: 2022/04/16 15:13:10 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# define TRUE 1
# define FALSE 0

typedef pthread_mutex_t	t_mutex;

typedef struct s_philo
{
	int			id;
	t_mutex		*lfork;
	t_mutex		*rfork;
	pthread_t	phil_thread;
}				t_philo;

typedef struct s_table
{
	int			nop;
	int			t2d;
	int			t2e;
	int			t2s;
	int			noe;
	long		start;
	t_philo		*philos;
	t_mutex		*forks;
	t_mutex		dining;
	t_mutex		log;
}				t_table;

/*utils*/
int		ft_atou(char *str);
int		str_error(char *str, int ret);
void	clear_table(t_table *table);

/*time*/
long	get_ltime(void);

/*main*/
int		check_args(int argc, char **argv, t_table *table);
int		init_philosophers(t_table *table);
int		init_thread(t_table *table);
void 	*start_dining(void *vargp);

#endif