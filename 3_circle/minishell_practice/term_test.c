/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 04:28:07 by dkim2             #+#    #+#             */
/*   Updated: 2022/06/08 04:47:25 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <termios.h>

void echoctl_off(void);
void echoctl_on(void);
void sigctl(int signo)
{
	static int toggle = 0;
	if (signo == SIGINT)
	{
		toggle ^= 0b1;
		printf("haha! sig INT (Ctrl + C)!\n");
		if (toggle == 1)
		{
			printf("echoctl off\n");
			echoctl_off();
		}
		else
		{
			printf("echoctl on\n");
			echoctl_on();
		}
	}
	else
	{
		printf("sigstop (Ctrl + \\)\n");
		exit(127 + 4);
	}
}


int main()
{
	signal(SIGQUIT, sigctl);
	signal(SIGINT, sigctl);

	while (1);
}

#define TRUE 1
#define FALSE 0

void echoctl_off(void)
{
	struct termios attr;

	if (isatty(STDIN_FILENO) == TRUE)
	{
		tcgetattr(STDIN_FILENO, &attr);
		attr.c_lflag &= ~ECHOCTL;
		tcsetattr(STDIN_FILENO, TCSANOW, &attr);
	}
}

void echoctl_on(void)
{
	struct termios attr;

	if (isatty(STDIN_FILENO) == TRUE)
	{
		tcgetattr(STDIN_FILENO, &attr);
		attr.c_lflag |= ECHOCTL;
		tcsetattr(STDIN_FILENO, TCSANOW, &attr);
	}
}