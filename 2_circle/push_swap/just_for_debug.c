/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   just_for_debug.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 02:49:33 by dkim2             #+#    #+#             */
/*   Updated: 2022/03/18 02:51:01 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*THIS PART IS JUST FOR DEBUG*/
#include "INC/push_swap.h"
#include <stdio.h>

void	printstack(t_mystack *stack)
{
	int				i;
	int				count;
	int				bot;
	unsigned int	max;

	i = stack->top_idx;
	count = 1;
	bot = stack->bot_idx;
	max = stack->max_size;
	printf("\033[1;33m>>> STACK %c<<<\n", stack->stack_name);
	printf("  MAX : %d\n", stack->max_size);
	printf(" CURR : %d\n", stack->curr);
	printf(" DATA : ");
	if (stack->curr == 0)
	{
		printf("\033[0m\n");
		return ;
	}
	while (1)
	{
		printf("[% 4d]", stack->array[i]);
		if (i == bot)
			break ;
		if (count % 15 == 0)
			printf("\n        ");
		i = convert_index(i - 1, max);
		count++;
	}
	printf("\033[0m\n");
}

void	show_arglst(t_arglst *lst)
{	
	t_arglst_node	*curr;

	curr = lst->head->next;
	while (curr)
	{
		printf("->(%d)", curr->data);
		curr = curr->next;
	}
	printf("\n");
}
