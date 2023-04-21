/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 09:33:07 by alpelliz          #+#    #+#             */
/*   Updated: 2023/04/21 16:52:01 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sa : Swap the first 2 elements at the top of stack a. 
int	sa(t_stack_a *a)
{
	ft_swap(&a->array_int_a[0], &a->array_int_a[1]);
	ft_printf("sa\n");
	a->counter++;
	return (0);
}

// sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements
int	sb(t_stack_b *b)
{
	ft_swap(&b->array_int_b[0], &b->array_int_b[1]);
	ft_printf("sb\n");
	return (0);
}

//ss : sa and sb at the same time.
int	ss(t_stack_a *a, t_stack_b *b)
{
	ft_swap(&a->array_int_a[0], &a->array_int_a[1]);
	ft_swap(&b->array_int_b[0], &b->array_int_b[1]);
	ft_printf("ss\n");
	return (0);
}

