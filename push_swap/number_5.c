/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:46:04 by alpelliz          #+#    #+#             */
/*   Updated: 2023/04/18 14:59:05 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		number_5(t_stack_a *a, t_stack_b *b)
{
	(void)b;
	int		i;
	int		j;
	int		z;
	int		tmp;

	i = 0;
	j = 0;
	z = 0;
	tmp = a->array_int_a[0];/*
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
			{
				ft_printf("numero piu basso trovato e: %d\n", tmp);
				break;
			}
			j++;
		}
		if (z == a->size_of_int)
		{
			ft_printf("numero piu basso trovato e: %d\n", tmp);
			break;
		}
		i++;
	}*/
	i = smallest_number(a, b);
	ft_printf("Ï primo = %d\n", i);
	ft_printf("passibnf = %d\n", a->array_int_a[i]);
	pre_pb_5(a, b, i);
	pb(a, b);
	array_printer(a, b);
	i = 0;
	//temp = 0;
	/*
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
			{
				ft_printf("numero piu alto trovato e: %d\n", tmp);
				break;
			}
			j++;
		}
		if (z == a->size_of_int)
		{
			break;
		}
		i++;
	}*/
	i = biggest_number(a, b);
	ft_printf("Ï = %d\n", i);
	if (i > 2)
		pre_pb_5(a, b, i + 1);
	if (i <= 2)
		pre_pb_5(a, b, i);
	//pb(a, b);
	pb(a, b);
	ft_printf("\nTHIS IS ARRAY AFTER PB\n");
	array_printer(a, b);
	number_3(a, b);
	pa(a, b);
	ra(a);
	pa(a, b);
	ft_printf("\n\nCHECK\n\n");
	return (0);
}
/*
int	smallest_number(t_stack_a *a, t_stack_b *b)
{
	(void)b;
	int		i;
	int		j;
	int		z;
	int		tmp;

	i = 0;
	j = 0;
	z = 0;
	tmp = a->array_int_a[0];
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
			{
				ft_printf("numero piu basso trovato e: %d\n", tmp);
				break;
			}
			j++;
		}
		if (z == a->size_of_int)
		{
			ft_printf("numero piu basso trovato e: %d\n", tmp);
			break;
		}
		i++;
	}
	return (i);
}

int	biggest_number(t_stack_a *a, t_stack_b *b)
{
	(void)b;
	int		i;
	int		j;
	int		z;
	int		tmp;

	i = 0;
	j = 0;
	z = 0;
	tmp = a->array_int_a[0];
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
			{
				ft_printf("numero piu alto trovato e: %d\n", tmp);
				break;
			}
			j++;
		}
		if (z == a->size_of_int)
		{
			break;
		}
		i++;
	}
	return (i);
}*/

int pre_pb_5(t_stack_a *a, t_stack_b *b, int x)
{
	(void)b;
	ft_printf("X = %d\n", x);
	if (x == 0)
		return (0);
	if (x == 1)
	{
		sa(a);
		ft_printf("TEST X = 1\n");
		return (1);
	}
	if (x == 2)
	{
		ft_printf("\nTHIS IS ARRAY BEFORE MOVES\n");
		array_printer(a, b);
		ra(a);
		sa(a);
		array_printer(a, b);
		ft_printf("\nTHIS WAS ARRAY INTO AFTER MOVES\n");
		ft_printf("TEST X = 2\n");
		return (2);
	}
	if (x == 3)
	{
		rra(a);
		rra(a);
		ft_printf("TEST X = 3\n");
		return (3);
	}
	if (x == 4)
	{
		rra(a);
		ft_printf("TEST X = 4\n");
		return (4);
	}
	return (0);
}