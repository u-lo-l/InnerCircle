/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_receiver_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:47:02 by dkim2             #+#    #+#             */
/*   Updated: 2022/04/08 17:47:04 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	receive_message_len(int signo, int client_pid)
{
	static int	i;
	static int	len;

	if (i > 31)
		len = 0;
	if (i < 32)
	{
		len <<= 1;
		if (signo == SIGUSR2)
			len++;
		i++;
	}
	if (kill(client_pid, SIGUSR1) == -1)
		exit(0);
	if (i > 31)
	{
		i = 0;
		return (len);
	}
	return (-1);
}

static int	set_message(char *str, int *idx, char c)
{
	str[*idx] = c;
	(*idx)++;
	if (c)
		return (FALSE);
	*idx = 0;
	return (TRUE);
}

int	receive_string(int signo, int client_pid, char *str)
{
	static char	c;
	static int	i;
	static int	idx;

	if (i > 7)
	{
		i = 0;
		c = 0;
	}
	if (i < 8)
	{
		c <<= 1;
		if (signo == SIGUSR2)
			c++;
		i++;
	}
	if (kill(client_pid, SIGUSR1) == -1)
		exit(0);
	if (i == 8)
		return (set_message(str, &idx, c));
	return (FALSE);
}
