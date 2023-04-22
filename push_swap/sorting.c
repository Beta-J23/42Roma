/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:54:18 by alpelliz          #+#    #+#             */
/*   Updated: 2023/04/19 16:36:19 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorting_check(t_stack_a *a, t_stack_b *b)
{
	int		i;

	(void)b;
	i = 0;
	while (i < a->size_of_int - 1)
	{
		if (a->array_int_a[i] > a->array_int_a[i + 1])
			break ;
		i++;
	}
	if (i != a->size_of_int - 1)
		return (1);
	else
		return (0);
}
