/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 02:02:25 by dkim2             #+#    #+#             */
/*   Updated: 2022/04/08 14:10:08 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# define TRUE 1
# define FLASE 0
# define TIME 100
/*UTILS*/
int		ft_strlen(char *str);
int		ft_numsize(long num, int radix);
void	ft_putpid(pid_t pid, int radix);
void	ft_putstr(char *str);
int		ft_atoi(char *str, int *err);

/*SERVER*/
void	receive_str_by_signal(int signo);
/*CLIENT*/
void	send_char_by_signal(pid_t server_pid, char c);
void	send_str_by_signal(pid_t server_pid, char *str);

#endif
