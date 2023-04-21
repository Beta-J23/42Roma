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

int	array_filler(t_stack_a *a, char **argv, int argc)
{
	int		i;
	int		j;
	int		z;
	int		k;

	i = 0;
	j = 0;
	z = 0;
	k = 0;
	if (argc == 1)
	{
		write (1, "Error: invalid number of args\n", 31);
		return (1);
	}
	if (argc == 2)
	{
		a->array_a = (char *)ft_calloc(ft_strlen(argv[1]), sizeof(char));
		while (argv[1][i] != '\0')
		{
			a->array_a[i] = argv[1][i];
			i++;
		}
		a->array_a[i] = '\0';
	}
	if (argc > 2)
	{
		i = 1;
		j = 0;
		while (i < argc)
		{
			while (argv[i][k] != '\0')
			{
				j++;
				k++;
				//ft_printf("J = %d\n", j);
			}
			j++;
			i++;
		}
		// ft_printf ("J FINE CICLO = %d\n", j);
		a->array_a = (char *)ft_calloc(j, sizeof(char));
		j = 0;
		i = 1;
		while (i < argc)
		{
			j = 0;
			while (argv[i][j] != '\0')
			{
				a->array_a[z] = argv[i][j];
				j++;
				z++;
			}
			a->array_a[z] = ' ';
			i++;
			z++;
		}
		a->array_a[z] = '\0';
	}
	//free (a->array_a);
	return (0);
}
/*
int	error_checker(t_stack_a *a, t_stack_b *b)
{
	check_double(a);
	already_sorted(a);
	//check double
	//invalid values
	// already sorted
	return (0);
}*/

// check_argv: check if: argv is a number; it's double,
// calculate size, convert array to int, determine Size jumping spaces
int	check_argv(t_stack_a *a)
{
	int		i;

	i = 0;
	// searching doubles and converting argvChars to int;
	while (a->array_a[i] != '\0')
	{
		if (a->array_a[i] != ' ')
		{
			if ((ft_isdigit(a->array_a[i]) == 0) && (a->array_a[i] != '-')
				&& (a->array_a[i] != '+'))
			{
				write(1, "Invalid value found in array", 29);
				return (1);
			}
			if (((a->array_a[i] == '-') || (a->array_a[i] == '+'))
				&& ((a->array_a[i + 1] == ' ') || (a->array_a[i + 1] == '+')
					|| (a->array_a[i + 1] == '-')))
			{
				write(1, "+ o - alone! INVALID VALUE\n", 28);
				return (1);
			}
			a->size++;
		}
		i++;
	}
	create_int_array(a);
	return (0);
}

int	create_int_array(t_stack_a *a)
{
	int		i;
	int		j;
	int		z;
	char	*str;

	i = 0;
	j = 0;
	z = 0;
	a->array_int_a = (int *)ft_calloc(a->size, sizeof(int));
	str = (char *)ft_calloc(a->size, sizeof(char));
	while (a->array_a[i] != '\0')
	{
		j = 0;
		while ((a->array_a[i] != ' ' && a->array_a[i] != '\0')
			|| (a->array_a[i] == '-') || (a->array_a[i] == '+'))
		{
			str[j] = a->array_a[i];
			j++;
			i++;
		}
		str[j] = '\0';
		a->array_int_a[z] = ft_atoi_mod(str);
		z++;
		if (a->array_a[i + 1] == ' ')
		{
			write(1, "Ignoring the spaces if they are at the end of argv!!!\n", 55);
			break;
		}
		if (a->array_a[i] == '\0')
		{
			write(1, "End of array, starting sort\n", 29);
			break ;
		}
		i++;
	}
	free (str);
	a->size_of_int = z;
	if (check_double(a) == 1)
		return (1);
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
		//ft_printf("%d  ", a->array_int_a[i]);
		while (j < a->size_of_int)
		{
			if (a->array_int_a[j] == a->array_int_a[i])
			{
				write (1, "Error: Double INT", 18);
				exit (0);
			}
			j++;
		}
		i++;
	}
	if (already_sorted(a) == 1)
		return (1);
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
		write(1, "\nArray already sorted!\n", 23);
		//exit (0);
		return (1);
	}
	else
		return (0);
}
