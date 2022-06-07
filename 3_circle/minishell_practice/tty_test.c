/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tty_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 04:14:53 by dkim2             #+#    #+#             */
/*   Updated: 2022/06/08 04:27:50 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
/*
test for functions :	isatty,(unistd.h)
						ttyname,
						ttyslot,
						tcsetattr,
						tcgetattr
*/

int main()
{
	// isatty
	printf("%d, %d\n", isatty(1), isatty(0));
	char * tty_name = ttyname(1);
	printf("%s\n", tty_name);
	printf("%d\n", ttyslot());
	printf("<<<mix ttyslot(), isatty(), ttyname>>>\n");
	int fd;
	fd = ttyslot();
	if (isatty(fd))
	{
		printf("%d is a tty\n", fd);
		char * tty = ttyname(0);
		printf("tty name : %s\n", tty);
	}
	else
		printf("%d is not a tty\n", fd);
}