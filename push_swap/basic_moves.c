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

// sa : Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
int		sa(t_stack_a *a)
{
	ft_swap(&a->array_int_a[0], &a->array_int_a[1]);
	ft_printf("sa\n");
	a->counter++;
	return (0);
}

// sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements
int		sb(t_stack_b *b)
{
	ft_swap(&b->array_int_b[0], &b->array_int_b[1]);
	ft_printf("sb\n");
	return (0);
}

//ss : sa and sb at the same time.
int		ss(t_stack_a *a, t_stack_b *b)
{
	//sa copy
	ft_swap(&a->array_int_a[0], &a->array_int_a[1]);
	//sb copy
	ft_swap(&b->array_int_b[0], &b->array_int_b[1]);
	ft_printf("ss\n");
	return (0);
}

// pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
int		pa(t_stack_a *a, t_stack_b *b)
{
	if (b->size_of_int <= 0)
		return (0);
	//rra(a);
	//rra copy
	int		i;
	int		tmp;
	
	tmp = a->array_int_a[a->size_of_int - 1];
	i = a->size_of_int;
	while (i > 0)
	{
		ft_swap (&a->array_int_a[i - 1], &a->array_int_a[i]);
		i--;
	}
	a->counter++;
	a->array_int_a[0] = tmp;
	//end of rra
	a->size_of_int++;
	a->array_int_a[0] = b->array_int_b[0];
	//rb(b);
	//rb copy
	tmp = b->array_int_b[0];
	i = 0;
	while (i < b->size_of_int)
	{
		ft_swap (&b->array_int_b[i], &b->array_int_b[i + 1]);
		i++;
	}
	b->array_int_b[b->size_of_int - 1] = tmp;
	//end of rb
	b->size_of_int--;
	//a->counter++;
	ft_printf("pa\n");
	return (0);
}

//pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
int		pb(t_stack_a *a, t_stack_b *b)
{
	if (a->size_of_int <= 0)
		return (0);
	//rrb(b);
	//rrb copy
	int		i;
	int		tmp;
	
	tmp = b->array_int_b[b->size_of_int - 1];
	i = b->size_of_int;
	while (i > 0)
	{
		ft_swap (&b->array_int_b[i - 1], &b->array_int_b[i]);
		i--;
	}
	b->array_int_b[0] = tmp;
	//end of rrb
	b->size_of_int++;
	b->array_int_b[0] = a->array_int_a[0];
	//ra(a);
	//ra copy
	tmp = a->array_int_a[0];
	i = 0;
	while (i < a->size_of_int)
	{
		ft_swap (&a->array_int_a[i], &a->array_int_a[i + 1]);
		i++;
	}
	a->array_int_a[a->size_of_int - 1] = tmp;
	// end of ra
	a->size_of_int--;
	ft_printf("pb\n");
	return (0);
}

// ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
int		ra(t_stack_a *a)
{
	int		i;
	int		tmp;
	
	tmp = a->array_int_a[0];
	i = 0;
	while (i < a->size_of_int)
	{
		ft_swap (&a->array_int_a[i], &a->array_int_a[i + 1]);
		i++;
	}
	a->counter++;
	a->array_int_a[a->size_of_int - 1] = tmp;
	ft_printf("ra\n");
	return (0);
}

// rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
int		rb(t_stack_b *b)
{
	int		i;
	int		tmp;
	
	tmp = b->array_int_b[0];
	i = 0;
	while (i < b->size_of_int)
	{
		ft_swap (&b->array_int_b[i], &b->array_int_b[i + 1]);
		i++;
	}
	b->array_int_b[b->size_of_int - 1] = tmp;
	ft_printf("rb\n");
	return (0);
}

// rr : ra and rb at the same time.
int		rr(t_stack_a *a, t_stack_b *b)
{
	//ra(a);
	//ra copy
	int		i;
	int		tmp;
	
	tmp = a->array_int_a[0];
	i = 0;
	while (i < a->size_of_int)
	{
		ft_swap (&a->array_int_a[i], &a->array_int_a[i + 1]);
		i++;
	}
	a->counter++;
	a->array_int_a[a->size_of_int - 1] = tmp;
	//end of ra
	//rb(b);
	//rb copy
	tmp = b->array_int_b[0];
	i = 0;
	while (i < b->size_of_int)
	{
		ft_swap (&b->array_int_b[i], &b->array_int_b[i + 1]);
		i++;
	}
	b->array_int_b[b->size_of_int - 1] = tmp;
	ft_printf("rr\n");
	return (0);
}

// rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
int		rra(t_stack_a *a)
{
	int		i;
	int		tmp;
	
	tmp = a->array_int_a[a->size_of_int - 1];
	i = a->size_of_int - 1;
	while (i >= 0)
	{
		ft_swap (&a->array_int_a[i - 1], &a->array_int_a[i]);
		i--;
	}
	a->counter++;
	a->array_int_a[0] = tmp;
	ft_printf("rra\n");
	return (0);
}

// rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
int		rrb(t_stack_b *b)
{
	int		i;
	int		tmp;
	
	tmp = b->array_int_b[b->size_of_int - 1];
	i = b->size_of_int - 1;
	while (i >= 0)
	{
		ft_swap (&b->array_int_b[i - 1], &b->array_int_b[i]);
		i--;
	}
	b->array_int_b[0] = tmp;
	ft_printf("rrb\n");
	return (0);
}

// rrr : rra and rrb at the same time.
int		rrr(t_stack_a *a, t_stack_b *b)
{
	//rra(a);
	//rra copy
	int		i;
	int		tmp;
	
	tmp = a->array_int_a[a->size_of_int - 1];
	i = a->size_of_int;
	while (i > 0)
	{
		ft_swap (&a->array_int_a[i - 1], &a->array_int_a[i]);
		i--;
	}
	a->counter++;
	a->array_int_a[0] = tmp;
	//end of rra
	//rrb(b);
	//rrb copy
	tmp = b->array_int_b[b->size_of_int - 1];
	i = b->size_of_int;
	while (i > 0)
	{
		ft_swap (&b->array_int_b[i - 1], &b->array_int_b[i]);
		i--;
	}
	b->array_int_b[0] = tmp;
	//end of rrb
	ft_printf("rrr\n");
	return (0);
}

