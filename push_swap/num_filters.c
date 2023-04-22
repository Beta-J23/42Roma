/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_filters.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:57:38 by alpelliz          #+#    #+#             */
/*   Updated: 2023/04/21 18:03:25 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	case_redirection(t_stack_a *a, t_stack_b *b)
{
	if (a->size_of_int <= 3)
	{
		number_3(a, b);
		return (0);
	}
	if (a->size_of_int == 5)
	{
		number_5(a, b);
		return (0);
	}
	if (a->size_of_int > 5)
	{
		number_100(a, b);
		return (0);
	}
	return (0);
}

int	smallest_number(t_stack_a *a, t_stack_b *b)
{
	int		i;
	int		j;
	int		tmp;

	(void)b;
	i = 0;
	j = 0;
	tmp = a->array_int_a[0];
	i = (smallest_number_helper(a, i, j, tmp));
	return (i);
}

int	smallest_number_helper(t_stack_a *a, int i, int j, int tmp)
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
			if (tmp <= a->array_int_a[j])
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
