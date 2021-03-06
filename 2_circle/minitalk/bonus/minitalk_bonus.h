/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 21:50:27 by dkim2             #+#    #+#             */
/*   Updated: 2022/03/25 04:48:20 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# define TRUE 1
# define FALSE 0
# define TIME 50
/*UTILS*/
int		ft_strlen(char *str);
int		ft_numsize(long num, int radix);
void	ft_putpid(pid_t pid, int radix);
void	ft_putstr(char *str);
int		ft_atoi(char *str, int *err);
/*server*/
int		receive_message_len(int signo, int client_pid);
int		receive_string(int signo, int client_pid, char *str);

#endif
