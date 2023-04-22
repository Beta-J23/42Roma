/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_convenience.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 10:59:32 by alpelliz          #+#    #+#             */
/*   Updated: 2023/04/22 10:59:35 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	moving_convenience(t_stack_a *a, t_stack_b *b, int x)
{
	int		y;

	(void)b;
	y = a->size_of_int - x;
	if (y <= x)
	{
		move_down(a, b, x);
	}
	if (x < y)
	{
		move_up(a, b, x);
	}
	return (0);
}

int	moving_convenience_b(t_stack_a *a, t_stack_b *b, int x)
{
	int		y;

	(void)a;
	y = b->size_of_int - x;
	if (y <= x)
	{
		move_down_b(a, b, x);
	}
	if (x < y)
	{
		move_up_b(a, b, x);
	}
	return (0);
}

int	move_b(t_stack_a *a, t_stack_b *b, int x, int value)
{
	int		y;

	(void)a;
	y = b->size_of_int - x;
	if ((value > b->array_int_b[b->size_of_int - 1])
		&& (biggest_b(a, b, b->array_int_b[b->size_of_int - 1])
			== b->size_of_int - 1))
		rrb(b);
	if (value > b->array_int_b[biggest_number_b(a, b)])
	{
		while (b->array_int_b[0] != b->array_int_b[biggest_number_b(a, b)])
			rrb(b);
	}
	if (y <= x)
		move_down_b(a, b, x);
	if (x < y)
		move_up_b(a, b, x);
	return (0);
}
