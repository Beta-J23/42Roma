/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_arrays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 19:09:29 by alpelliz          #+#    #+#             */
/*   Updated: 2023/04/19 20:28:46 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
int fake_order(t_stack_a *a, t_stack_b *b)
{
	(void)b;
	int		*fake_order;
	int		i;
	int		j;

	i = 0;
	j = 0;
	fake_order = malloc(sizeof(int) * (a->size_of_int - 1));
	while(i <= a->size_of_int - 1)
	{
		fake_order[i] = a->array_int_a[i];
		i++;
	}
	i = 0;
	ft_printf("\n\nfake array = ");
	while(i < a->size_of_int - 1)
	{
		ft_printf("%d ", fake_order[i]);
		i++;
	}
	i = -1;
	// bubble transformed
	while (i < a->size_of_int - 1)
	{
		if (fake_order[i] > fake_order[i + 1])
		{	
			//a->array_int_a[i] = a->array_int_a[i + 1];
			ft_swap(&fake_order[i], &fake_order[i + 1]);
			i = -1;
		}
		++i; 
	}
	i = 0;
	ft_printf("\n\nAFTER BUBBLE fake array = ");
	while(i <= a->size_of_int - 1)
	{
		ft_printf("%d ", fake_order[i]);
		i++;
	}
	ft_printf("I = %d", i);
	return (0);
}



int	fake_array(t_stack_a *a, t_stack_b *b)
{
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	a->fake_array = malloc(sizeof(int) * a->size_of_int);
	
	
}

int fake_array_filler(t_stack_a *a, t_stack_b *b)
{
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	a->fake_array = malloc(sizeof(int) * a->size_of_int);
	while (i < a->size_of_int)
	{
		while(j < a->size_of_int / 5) || (j < a->size_of_int % 5)
	}
	a->fake_array[i][j] = '\0';
}



int fake_printer(t_stack_a *a, t_stack_b *b)
{
	while (a->fake_array != )
	{
		while(a->fake_array != )
		ft_printf(a->fake_array[i][j])
	}
}


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
}*/