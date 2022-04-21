/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 21:15:27 by dkim2             #+#    #+#             */
/*   Updated: 2022/04/21 09:05:42 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	t_table	table;
	int		res;
	memset(&table, 0, sizeof(t_table));
	if (check_args(argc, argv, &table) == FALSE)
		return (str_error("Error : Invalid Arguments!", 1));
	if (init_philosophers(&table) == FALSE)
		return (str_error("Error : Fail to set table", 1));
	if (init_thread(&table) == FALSE)
		return (str_error("Error : Fail to start dining", 1));
	waitpid(-1, &res, 0);
	printf("%d\n", res);
	clear_table(&table);
}
