/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structuretest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 09:44:52 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/06 09:45:21 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct tests
{
	int	a;
	int	b;
}	t_test;

t_test	TTT(int a, int b)
{
	t_test T;

	T.a = a;
	T.b = b;
	return (T);
}

#include <stdio.h>
int main()
{
	t_test A = TTT(3, 4);
	printf("a is %d\n", A.a);
	printf("b    %d\n", A.b);
}
