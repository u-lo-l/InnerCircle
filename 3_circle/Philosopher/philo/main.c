/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:57:02 by dkim2             #+#    #+#             */
/*   Updated: 2022/04/17 15:26:56 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

#include <stdio.h>
#include <string.h>

int	main(int argc, char **argv)
{
	t_table	table;

	memset(&table, 0, sizeof(t_table));
	if (check_args(argc, argv, &table) == FALSE)
		return (str_error("Error : Invalid Arguments!", 1));
	if (init_philosophers(&table) == FALSE)
		return (str_error("Error : Fail to set table", 1));
	if (init_thread(&table) == FALSE)
		return (str_error("Error : Fail to start dining", 1));
	while (table.die == 0)
		check_terminate(&table);
	clear_table(&table);
}
