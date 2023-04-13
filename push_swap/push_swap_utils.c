/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:44:43 by alpelliz          #+#    #+#             */
/*   Updated: 2023/04/13 19:28:32 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int atoi_limit(long long nb)
{
	if ((nb < -2147483648) || (nb > 2147483647))
	{
		write(1, "int limit overflowed!\n", 23);
		exit (0);
	}
	else 
		return ((int)nb);
}

int ft_atoi_mod(char *str)
{
	int			i;
	int			var;
	long long	intero;

	var = 1;
	i = 0;
	intero = 0;
	while ((str[i] == '\t') || (str[i] == '\n') || (str[i] == '\v')
		|| (str[i] == '\f') || (str[i] == '\r') || (str[i] == ' '))
	{
		i++;
	}
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			var = var * -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		intero = intero * 10 + (str[i] - 48);
		i++;
	}
	return(atoi_limit(intero * var));
}

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

void array_printer(t_stack_a *a, t_stack_b *b)
{
	int i;
	
	i = 0;
	ft_printf("\nnew array A is: ");
	while (i < a->size_of_int)
	{
		ft_printf("%d ", a->array_int_a[i]);
		i++;
	}
	i = 0;
	ft_printf("\nnew array B is: ");
	while (i < b->size_of_int)
	{
		ft_printf("%d ", b->array_int_b[i]);
		i++;
	}
}