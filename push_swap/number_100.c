/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_100.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:32:35 by alpelliz          #+#    #+#             */
/*   Updated: 2023/04/18 18:32:38 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int number_100(t_stack_a *a, t_stack_b *b)
{
	int		i;
	int		j;
	int		z;

	i = 0;
	j = 0;
	z = a->size_of_int;
	i = smallest_number(a, b);
	//ft_printf("\n\n\nsmallest number is: %d\n\n\n\n", a->array_int_a[i]);
	//moving_convenience(a, b, i);
	//trying loop for all
	b->array_int_b = malloc(sizeof(char) * a->size_of_int);
	while (j < z)
	{
		i = smallest_number(a, b);
		moving_convenience(a, b, i);
		pb(a, b);
		j++;
	}
	j = 0;
	
	while (j < z)
	{
		pa(a, b);
		j++;
	}
	//ft_printf("\n\n\n I is: %d\n\n\n\n", i);
	free(b->array_int_b);
	return (0);
}

int	moving_convenience(t_stack_a *a, t_stack_b *b, int x)
{
	(void)b;

	int		y;
	y = a->size_of_int - x;

	if (y < x)
	{
		move_down(a, b, x);
	}
	if (x < y)
	{
		move_up(a, b, x);
	}

	return(0);
}

int	move_down(t_stack_a *a, t_stack_b *b, int	y)
{
	(void)b;

	while (y < a->size_of_int)
	{
		rra(a);
		y++;
	}
	//ft_printf("MOVING DOWN");
	return (0);
}

int	move_up(t_stack_a *a, t_stack_b *b, int	x)
{
	(void)b;
	
	while (x > 0)
	{
		ra(a);
		x--;
	}
	//ft_printf("MOVING UP");
	return (0);
}


int	stuff_mover(t_stack_a *a, t_stack_b *b, int y)
{
	(void)b;
	//int		i;
	//int		j;

	while (y < a->size_of_int)
	{
		rra(a);
		y++;
	}
	return (0);
}
	/*j = a->size_of_int / 2;
	i = a->size_of_int / 2;
	while (i < a->size_of_int - 1)
	{
		i++;
	}
	while (j >= 0)
	{
		j--;
	}
	if (a->size_of_int - j) >= i;
		return (i);
	if (a->size_of_int - j) < i;
		return (j);
	return(0);*/