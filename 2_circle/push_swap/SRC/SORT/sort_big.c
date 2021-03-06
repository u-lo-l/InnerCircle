/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 02:54:03 by dkim2             #+#    #+#             */
/*   Updated: 2022/03/18 03:07:01 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INC/push_swap.h"

void	prepare_a_and_b(t_mystack *A, t_mystack *B, t_actions *acts)
{
	int	count_rr;
	int	count_rrr;
	int	count_else;
	int	i;

	count_rr = my_max(acts->ra, acts->rb);
	count_rrr = my_max(acts->rra, acts->rrb);
	count_else = my_min(acts->ra, acts->rra) + my_min(acts->rb, acts->rrb);
	i = 0;
	if (acts->total == count_rr)
		case_rr(A, B, acts);
	else if (acts->total == count_rrr)
		case_rrr(A, B, acts);
	else
		case_else(A, B, acts);
}

void	make_b_decsending(t_mystack *B)
{
	int	count_rb;
	int	count_rrb;

	if (B->stack_name != 'b')
		return ;
	count_rb = count_b2a_actions(B);
	count_rrb = 0;
	if (B->curr > 0)
		count_rrb = (B->curr - count_rb) % B->curr;
	if (count_rb >= count_rrb)
	{
		while (count_rrb > 0)
		{
			act_rrot(B, NULL);
			count_rrb--;
		}
	}
	else
	{
		while (count_rb > 0)
		{
			act_rot(B, NULL);
			count_rb--;
		}
	}
}

void	get_big_three(t_mystack *stack, int big3[3])
{
	int	i;
	int	idx;

	i = -1;
	while (++i < stack->curr)
	{
		idx = convert_index(stack->top_idx - i, stack->max_size);
		if (big3[0] < stack->array[i])
			big3[0] = stack->array[i];
	}
	i = -1;
	while (++i < stack->curr)
	{
		idx = convert_index(stack->top_idx - i, stack->max_size);
		if ((big3[1] < stack->array[i]) && (stack->array[i] < big3[0]))
			big3[1] = stack->array[i];
	}
	i = -1;
	while (++i < stack->curr)
	{
		idx = convert_index(stack->top_idx - i, stack->max_size);
		if (big3[2] < stack->array[i] && stack->array[i] < big3[1])
			big3[2] = stack->array[i];
	}
}

void	get_least_actions(t_mystack *A,	t_mystack *B,
						t_actions *actions,	int big3[3])
{
	int			a_idx;
	t_actions	temp_actions;

	a_idx = A->top_idx;
	while (TRUE)
	{
		if (A->array[a_idx] != big3[0] \
			&& A->array[a_idx] != big3[1] \
			&& A->array[a_idx] != big3[2])
		{
			count_a2b_actions(A, a_idx, B, &temp_actions);
			if (actions->total > temp_actions.total)
				(*actions) = temp_actions;
		}
		if (a_idx == A->bot_idx)
			break ;
		a_idx = convert_index(a_idx - 1, A->max_size);
	}
}

void	sort_big(t_mystack *A, t_mystack *B)
{
	t_actions	actions;
	int			big_three[3];

	big_three[0] = -2147483648;
	big_three[1] = -2147483648;
	big_three[2] = -2147483648;
	get_big_three(A, big_three);
	while (A->curr > 3)
	{
		actions.total = 2147483647;
		get_least_actions(A, B, &actions, big_three);
		prepare_a_and_b(A, B, &actions);
		act_push(A, B);
	}
	sort_mini(A);
	make_b_decsending(B);
	while (B->curr)
		act_push(B, A);
}
