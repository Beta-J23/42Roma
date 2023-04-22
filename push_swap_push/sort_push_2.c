/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_push_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 13:22:28 by alpelliz          #+#    #+#             */
/*   Updated: 2023/04/22 13:22:57 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	smallest_usable(int *tmp, int size)
{
	int		i;
	int		j;
	int		z;

	i = 0;
	j = 0;
	z = 0;
	while (i < size)
	{
		j = 0;
		z = 0;
		while (j < size)
		{
			if (tmp[i] <= tmp[j])
				z++;
			if (z == size)
				break ;
			j++;
		}
		if (z == size)
			break ;
		i++;
	}
	return (i);
}

int	biggest_b(t_stack_a *a, t_stack_b *b, int num)
{
	int		i;

	(void)a;
	i = 0;
	while (i < b->size_of_int)
	{
		if (num < b->array_int_b[i])
			break ;
		i++;
	}
	return (i - 1);
}
