/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:46:04 by alpelliz          #+#    #+#             */
/*   Updated: 2023/04/21 15:23:26 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	number_5(t_stack_a *a, t_stack_b *b)
{
	int		i;

	(void)b;
	i = 0;
	i = smallest_number(a, b);
	//b->array_int_b = malloc(sizeof(int) * 6);
	pre_pb_5(a, b, i);
	pb(a, b);
	i = 0;
	i = biggest_number(a, b);
	if (i > 2)
		pre_pb_5(a, b, i + 1);
	if (i <= 2)
		pre_pb_5(a, b, i);
	pb(a, b);
	number_3(a, b);
	pa(a, b);
	ra(a);
	pa(a, b);
	array_printer(a, b);
	//free(b->array_int_b);
	return (0);
}

int	pre_pb_5(t_stack_a *a, t_stack_b *b, int x)
{
	(void)b;
	if (x == 0)
		return (0);
	if (x == 1)
	{
		sa(a);
		return (1);
	}
	if (x == 2)
	{
		ra(a);
		sa(a);
		array_printer(a, b);
		return (2);
	}
	return (pre_pb_5_helper(a, b, x));
}

int	pre_pb_5_helper(t_stack_a *a, t_stack_b *b, int x)
{
	(void)b;
	if (x == 3)
	{
		rra(a);
		rra(a);
		return (3);
	}
	if (x == 4)
	{
		rra(a);
		return (4);
	}
	return (0);
}