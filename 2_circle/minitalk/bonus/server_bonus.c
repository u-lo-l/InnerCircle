/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 04:36:00 by dkim2             #+#    #+#             */
/*   Updated: 2022/03/25 05:13:26 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	signal_interference(int *pid1, int pid2, char **message)
{
	if (*pid1 != pid2)
	{
		free(*message);
		*message = NULL;
		usleep(TIME);
		kill(*pid1, SIGUSR2);
		kill(pid2, SIGUSR2);
		*pid1 = 0;
		exit(0);
	}
}

static char	*init_message(int signo, int client_pid)
{
	char	*message;
	int		len;

	len = receive_message_len(signo, client_pid);
	if (len != -1)
	{
		message = malloc(sizeof(char) * (len + 1));
		if (message)
			return (message);
	}
	return (NULL);
}

static void	print_message(char **message, int *client_pid)
{
	ft_putstr(*message);
	ft_putstr("\n");
	*client_pid = 0;
	free(*message);
	*message = NULL;
}

static void	signal_handler(int signo, siginfo_t *info, void *context)
{
	static int	client_pid;
	static char	*message;

	(void)context;
	if (client_pid == 0)
	{
		client_pid = info->si_pid;
		if (kill(client_pid, SIGUSR1) == -1)
			exit(0);
	}
	else
	{
		signal_interference(&client_pid, info->si_pid, &message);
		if (message == NULL)
		{
			message = init_message(signo, client_pid);
			return ;
		}
		else
			if (receive_string(signo, client_pid, message) == TRUE)
				print_message(&message, &client_pid);
	}
}

int	main(void)
{
	struct sigaction	new_act;

	ft_putpid(getpid(), 10);
	new_act.sa_flags = SA_SIGINFO;
	new_act.sa_sigaction = signal_handler;
	sigemptyset(&new_act.sa_mask);
	sigaction(SIGUSR1, &new_act, NULL);
	sigaction(SIGUSR2, &new_act, NULL);
	while (TRUE)
		pause();
}
