/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:27:50 by alpelliz          #+#    #+#             */
/*   Updated: 2023/04/21 15:21:48 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	number_3(t_stack_a *a, t_stack_b *b)
{
	(void)b;

	if (sorting_check(a, b) == 0)
		return (0);
	if (a->size_of_int == 2)
	{
		sa(a);
		return (0);
	}
	if ((a->array_int_a[0] > a->array_int_a[1])
		&& (a->array_int_a[1] < a->array_int_a[2])
		&& (a->array_int_a[2] > a->array_int_a[0]))
	{
		sa(a);
		if (sorting_check(a, b) == 0)
			return (0);
	}
	if (number_3_helper_1(a, b) == 1)
		return (0);
	if (number_3_helper_2(a, b) == 1)
		return (0);
	return (0);
}

int	number_3_helper_1(t_stack_a *a, t_stack_b *b)
{
	if ((a->array_int_a[0] > a->array_int_a[1])
		&& (a->array_int_a[1] > a->array_int_a[2])
		&& (a->array_int_a[2] < a->array_int_a[0]))
	{
		sa(a);
		rra(a);
		if (sorting_check(a, b) == 0)
			return (1);	
	}
	if ((a->array_int_a[0] > a->array_int_a[1])
		&& (a->array_int_a[1] < a->array_int_a[2])
		&& (a->array_int_a[2] < a->array_int_a[0]))
	{
		ra(a);
		if (sorting_check(a, b) == 0)
			return (1);	
	}
	return (0);
}

int	number_3_helper_2(t_stack_a *a, t_stack_b *b)
{
	if ((a->array_int_a[0] < a->array_int_a[1])
		&& (a->array_int_a[1] > a->array_int_a[2])
		&& (a->array_int_a[2] > a->array_int_a[0]))
	{
		sa(a);
		ra(a);
		if (sorting_check(a, b) == 0)
			return (1);	
	}
	if ((a->array_int_a[0] < a->array_int_a[1])
		&& (a->array_int_a[1] > a->array_int_a[2])
		&& (a->array_int_a[2] < a->array_int_a[1]))
	{
		rra(a);
		if (sorting_check(a, b) == 0)
			return (1);	
	}
	return (0);
}