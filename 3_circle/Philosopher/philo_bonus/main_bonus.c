/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 21:15:27 by dkim2             #+#    #+#             */
/*   Updated: 2022/04/25 16:10:40 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_table	table;
	
	memset(&table, 0, sizeof(t_table));
	if (check_args(argc, argv, &table) == FALSE)
		return (str_error("Error : Invalid Arguments!", 1));
	if (init_table(&table) == FALSE)
		return (str_error("Error : Fail to set table", 1));
	if (init_philosophers(&table) == FALSE)
		return (str_error("Error : Fail to set Philos", 1));
	clear_table(&table);
	return (0);
}
