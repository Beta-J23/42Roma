/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_filters_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 11:01:42 by alpelliz          #+#    #+#             */
/*   Updated: 2023/04/22 11:01:44 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	biggest_number(t_stack_a *a, t_stack_b *b)
{
	int		i;
	int		j;
	int		tmp;

	(void)b;
	i = 0;
	j = 0;
	tmp = a->array_int_a[0];
	i = biggest_number_helper(a, i, j, tmp);
	return (i);
}

int	biggest_number_helper(t_stack_a *a, int i, int j, int tmp)
{
	int		z;

	z = 0;
	while (i < a->size_of_int)
	{
		j = 0;
		z = 0;
		while (j < a->size_of_int)
		{
			tmp = a->array_int_a[i];
			if (tmp >= a->array_int_a[j])
				z++;
			if (z == a->size_of_int)
				break ;
			j++;
		}
		if (z == a->size_of_int)
			break ;
		i++;
	}
	return (i);
}

int	biggest_number_b(t_stack_a *a, t_stack_b *b)
{
	int		i;
	int		j;
	int		tmp;

	(void)a;
	i = 0;
	j = 0;
	tmp = b->array_int_b[0];
	i = biggest_number_b_helper(b, i, j, tmp);
	return (i);
}

int	biggest_number_b_helper(t_stack_b *b, int i, int j, int tmp)
{
	int		z;

	z = 0;
	while (i < b->size_of_int)
	{
		j = 0;
		z = 0;
		while (j < b->size_of_int)
		{
			tmp = b->array_int_b[i];
			if (tmp >= b->array_int_b[j])
				z++;
			if (z == b->size_of_int)
				break ;
			j++;
		}
		if (z == b->size_of_int)
			break ;
		i++;
	}
	return (i);
}
