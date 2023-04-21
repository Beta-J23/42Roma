/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_100.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:32:35 by alpelliz          #+#    #+#             */
/*   Updated: 2023/04/21 12:24:17 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int number_100(t_stack_a *a, t_stack_b *b)
{
	int		i;
	int		j;
	int		z;
	//int		k;

	i = 0;
	j = 0;
	z = a->size_of_int;
	//k = biggest_number(a, b);
	//i = smallest_number(a, b);
	//ft_printf("\n\n\nsmallest number is: %d\n\n\n\n", a->array_int_a[i]);
	//moving_convenience(a, b, i);
	b->array_int_b = malloc(sizeof(int) * a->size_of_int);
	//fake_order(a, b);
	//trying sort with moves prevision (previsione delle mosse)
	
	while (j < z - 1)
	{
		i = smallest_number(a, b); //smallest number + 1 in loop
		if (moving_convenience(a, b, i) == 0)
			pb(a, b);
		j++;
	}
	j = 0;
	
	while (j < z - 1)
	{
		pa(a, b);
		j++;
	}
	//trying loop for all with smallest number passed as parameter
	/*while (j < z - 1)
	{
		i = smallest_number(a, b);
		if (moving_convenience(a, b, i) == 0)
			pb(a, b);
		j++;
	}
	j = 0;
	
	while (j < z - 1)
	{
		pa(a, b);
		j++;
	}*/
	// TRYing sort putting small up big down
	//while (j < z)
	//{
	//	i = smallest_number(a, b);
	//	//k = biggest_number(a, b);
	//	moving_convenience(a, b, i);
	//	//if (smallest_number(a, b) == 0)
	//	//	pb(a, b);
	//	pb(a, b);
	//	j++;
	//}
	//j = 0;
	
	//while (j < z)
	//{
	//	pa(a, b);
	//	j++;
	//}
	//ft_printf("\n\n\n I is: %d\n\n\n\n", i);
	free(b->array_int_b);
	return (0);
}

int	moving_convenience(t_stack_a *a, t_stack_b *b, int x)
{
	(void)b;
	int		i;
	//int		*tmp;
	int		y;

	i = 0;
	//tmp = malloc(sizeof(int) * a->size_of_int);
	//int		z;
	y = a->size_of_int - x;
	//z = a->size_of_int - k;
	
	
	if (y <= x)
		{
			move_down(a, b, x);
		}
		if (x < y)
		{
			move_up(a, b, x);
		}

	return(0);
}
/*
int	moving_convenience(t_stack_a *a, t_stack_b *b, int x)
{
	(void)b;
	int		y;
	//int		z;
	y = a->size_of_int - x;
	//z = a->size_of_int - k;

	
	//if ((k > x) && (z > y))
	//{
	if (y <= x)
	{
		move_down(a, b, x);
	}
	if (x < y)
	{
		move_up(a, b, x);
	}
	//}
	//
	//if ((k < x) && (z < y))
	//{
	//	//if (z < k)
	//	//{
	//	//	move_up(a, b, k);
	//	//}
	//	if (k < z)
	//	{
	//		move_down(a, b, k);
	//	}
	//}

	return(0);
}*/

/*
int	smallest_number_modified(t_stack_a *a, t_stack_b *b, int w)
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
				//ft_printf("numero piu basso trovato e: %d\n", tmp);
				break;
			}
			j++;
		}
		if (z == a->size_of_int - w)
		{
			//ft_printf("numero piu basso trovato e: %d\n", tmp);
			break;
		}
		i++;
	}
	return (i);
}*/

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