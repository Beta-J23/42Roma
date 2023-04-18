/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_arrays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 19:09:29 by alpelliz          #+#    #+#             */
/*   Updated: 2023/04/18 19:40:23 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int fake_array(t_stack_a *a, t_stack_b *b, t_fake *c)
{
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	size = a->size_of_int / 5;
	c->chunk1 = malloc(sizeof(int) * a->size_of_int / 5); 
	while (i < size)
	{
		j = 0;
		while (c->chunk1[j] != a->array_int_a[i])
		{
			if (c->chunk1[j] == a->array_int_a[i])
			j++;
		}
		i++;
	}
}