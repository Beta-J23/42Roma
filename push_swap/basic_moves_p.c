/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_moves_p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 11:01:09 by alpelliz          #+#    #+#             */
/*   Updated: 2023/04/22 11:01:11 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// pa Take the first element at the top of b and put it at the top of a.
int	pa(t_stack_a *a, t_stack_b *b)
{
	int		i;
	int		tmp;

	if (b->size_of_int <= 0)
		return (0);
	tmp = a->array_int_a[a->size_of_int - 1];
	i = a->size_of_int;
	while (i > 0)
	{
		ft_swap (&a->array_int_a[i - 1], &a->array_int_a[i]);
		i--;
	}
	pa_helper(a, b, i, tmp);
	return (0);
}

int	pa_helper(t_stack_a *a, t_stack_b *b, int i, int tmp)
{
	a->array_int_a[0] = tmp;
	a->size_of_int++;
	a->array_int_a[0] = b->array_int_b[0];
	tmp = b->array_int_b[0];
	i = 0;
	while (i < b->size_of_int)
	{
		ft_swap (&b->array_int_b[i], &b->array_int_b[i + 1]);
		i++;
	}
	b->array_int_b[b->size_of_int - 1] = tmp;
	b->size_of_int--;
	ft_printf("pa\n");
	return (0);
}

//pb Take the first element at the top of a and put it at the top of b.
int	pb(t_stack_a *a, t_stack_b *b)
{
	int		i;
	int		tmp;

	if (a->size_of_int <= 0)
		return (0);
	tmp = b->array_int_b[b->size_of_int - 1];
	i = b->size_of_int;
	while (i > 0)
	{
		ft_swap (&b->array_int_b[i - 1], &b->array_int_b[i]);
		i--;
	}
	pb_helper(a, b, i, tmp);
	return (0);
}

int	pb_helper(t_stack_a *a, t_stack_b *b, int i, int tmp)
{
	b->array_int_b[0] = tmp;
	b->size_of_int++;
	b->array_int_b[0] = a->array_int_a[0];
	tmp = a->array_int_a[0];
	i = 0;
	while (i < a->size_of_int)
	{
		ft_swap (&a->array_int_a[i], &a->array_int_a[i + 1]);
		i++;
	}
	a->array_int_a[a->size_of_int - 1] = tmp;
	a->size_of_int--;
	ft_printf("pb\n");
	return (0);
}
