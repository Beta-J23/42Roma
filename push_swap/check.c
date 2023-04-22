/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:00:31 by alpelliz          #+#    #+#             */
/*   Updated: 2023/04/21 18:26:05 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_checker(t_stack_a *a)
{
	if (a->size_of_int == 1)
		exit (0);
	check_double(a);
	already_sorted(a);
	return (0);
}

// check_argv: check if: argv is a number; it's double,
// calculate size, convert array to int, determine Size jumping spaces
int	check_argv(t_stack_a *a)
{
	int		i;

	i = 0;
	while (a->array_a[i] != '\0')
	{
		if (a->array_a[i] != ' ')
		{
			check_argv_helper(a, i);
			a->size++;
		}
		i++;
	}
	create_int_array(a);
	return (0);
}

int	check_argv_helper(t_stack_a *a, int i)
{
	if ((ft_isdigit(a->array_a[i]) == 0) && (a->array_a[i] != '-')
		&& (a->array_a[i] != '+'))
	{
		write(1, "Error: Invalid value found in array\n", 37);
		exit (0);
	}
	if (((a->array_a[i] == '-') || (a->array_a[i] == '+'))
		&& ((a->array_a[i + 1] == ' ') || (a->array_a[i + 1] == '+')
			|| (a->array_a[i + 1] == '-')))
	{
		write(1, "Error: + o - alone! INVALID VALUE\n", 35);
		exit (0);
	}
	return (0);
}

int	check_double(t_stack_a *a)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < a->size_of_int)
	{
		j = i + 1;
		while (j < a->size_of_int)
		{
			if (a->array_int_a[j] == a->array_int_a[i])
			{
				write (1, "Error: Double INT\n", 19);
				exit (0);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	already_sorted(t_stack_a *a)
{
	int	i;

	i = 0;
	while (a->array_int_a[i] < a->array_int_a[i + 1])
	{
		i++;
	}
	if (i == a->size_of_int - 1)
	{
		write(1, "Error: Array already sorted!\n", 30);
		exit (0);
	}
	else
		return (0);
}
