/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:27:50 by alpelliz          #+#    #+#             */
/*   Updated: 2023/04/17 18:43:13 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		number_3(t_stack_a *a, t_stack_b *b)
{
	(void)b;
	int		i;
	int		x;
	
	i = 0;
	x = 0;

	if (sorting_check(a, b) == 0)
				return (0);
	if ((a->array_int_a[0] > a->array_int_a[1]) && (a->array_int_a[1] < a->array_int_a[2])
		&& (a->array_int_a[2] > a->array_int_a[0]))
	{
		ft_printf("\nCase 1\n");
		sa(a);
		if (sorting_check(a, b) == 0)
				return (0);
	}
	if ((a->array_int_a[0] > a->array_int_a[1]) && (a->array_int_a[1] > a->array_int_a[2])
		&& (a->array_int_a[2] < a->array_int_a[0]))
	{
		ft_printf("\nCase 2\n");
		sa(a);
		rra(a);
		if (sorting_check(a, b) == 0)
				return (0);	
	}
	if ((a->array_int_a[0] > a->array_int_a[1]) && (a->array_int_a[1] < a->array_int_a[2])
		&& (a->array_int_a[2] < a->array_int_a[0]))
	{
		ft_printf("\nCase 3\n");
		ra(a);
		if (sorting_check(a, b) == 0)
				return (0);	
	}
	if ((a->array_int_a[0] < a->array_int_a[1]) && (a->array_int_a[1] > a->array_int_a[2])
		&& (a->array_int_a[2] > a->array_int_a[0]))
	{
		ft_printf("\nCase 4\n");
		sa(a);
		ra(a);
		if (sorting_check(a, b) == 0)
				return (0);	
	}
	if ((a->array_int_a[0] < a->array_int_a[1]) && (a->array_int_a[1] > a->array_int_a[2])
		&& (a->array_int_a[2] < a->array_int_a[1]))
	{
		ft_printf("\nCase 5\n");
		rra(a);
		if (sorting_check(a, b) == 0)
				return (0);	
	}
return (0);
}


/*
int		number_3(t_stack_a *a, t_stack_b *b)
{
	(void)b;
	int		i;
	int		x;
	
	i = 0;
	x = 0;

	if (sorting_check(a, b) == 0)
				return (0);
	while (i < a->size_of_int - 1)
	{
		if (a->array_int_a[i] > a->array_int_a[i + 1])
		{
			ft_printf("array[i] = %d\n", a->array_int_a[i]);
			ft_printf("array[i + 1] = %d\n", a->array_int_a[i + 1]);
			sa(a);
			if (sorting_check(a, b) == 0)
				break;
			if (a->array_int_a[(a->size_of_int - 1) / 2] > a->array_int_a[a->size_of_int - 1])
			{
				rra(a);
				ft_printf("TEST\n");
				return (0);
			}
			if (a->array_int_a[(a->size_of_int - 1) / 2] < a->array_int_a[a->size_of_int - 1])
			{
				ra(a);
				ft_printf("TEST2\n");
				return (0);
			}
		}
		if (sorting_check(a, b) == 0)
				break;
		//if (a->array_int_a[i] > a->array_int_a[a->size_of_int + 1])
		i++;
	}
	return(0);
}*/

