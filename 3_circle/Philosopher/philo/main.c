/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:57:02 by dkim2             #+#    #+#             */
/*   Updated: 2022/04/26 21:43:42 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include <string.h>

int	main(int argc, char **argv)
{
	t_table		table;
	pthread_t	die_check;

	memset(&table, 0, sizeof(t_table));
	if (check_args(argc, argv, &table) == FALSE)
		return (str_error("Error : Invalid Arguments!", 1));
	if (init_philosophers(&table) == FALSE)
		return (str_error("Error : Fail to set table", 1));
	if (!pthread_create(&die_check, NULL, check_terminate, &table))
	{
		if (init_thread(&table) == FALSE)
			return (str_error("Error : Fail to start dining", 1));
		pthread_join(die_check, NULL);
	}
	clear_table(&table);
}
