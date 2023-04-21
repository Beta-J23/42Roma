/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:00:31 by alpelliz          #+#    #+#             */
/*   Updated: 2023/04/21 12:54:34 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
void initializer(t_stack_a *a, t_stack_b *b)
{
	(void)b;
	a->size = ft_strlen(a->array_a);
	a->array_a = malloc(sizeof(char) * a->size + 1);
}*/

int	array_filler(t_stack_a *a, char **argv, int argc)
{
	int		i;
	int		j;
	int		z;

	i = 0;
	j = 0;
	z = 0;
	if (argc == 1)
	{
		write (1, "invalid number of args", 23);
		return (1);
	}
	if (argc == 2)
	{
		a->array_a = (char *)ft_calloc(ft_strlen(argv[1]) - 1, sizeof(char));
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
			while (argv[i][j] != '\0')
			{
				j++;
			}
			j++;
			i++;
		}
		free (a->array_a);
		a->array_a = (char *)ft_calloc(j + 1, sizeof(char));
		//ft_printf ("J = %d\n", j);
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

/* check_argv: check if: argv is a number; it's double, calculate size, convert array to int, determine Size jumping spaces,*/
int		check_argv(t_stack_a *a)
{
	ft_printf("array di z = %s\n", a->array_a);
	int		i;

	int		z;
	char *argv = NULL;
	(void)argv;
	i = 0;
	z = 0;
	// searching doubles and converting argvChars to int;
	while (a->array_a[i] != '\0')
	{
		if (a->array_a[i] != ' ')
		{
			if ((ft_isdigit(a->array_a[i]) == 0) && (a->array_a[i] != '-') && (a->array_a[i] != '+'))
			{
				ft_printf("INCRIMINATED: %d\n", a->array_a[i]);
				write(1, "Invalid value", 14);
				return (1);
			}
			if (((a->array_a[i] == '-') || (a->array_a[i] == '+')) && ((a->array_a[i + 1] == ' ') || (a->array_a[i + 1] == '+') || (a->array_a[i + 1] == '-')))
			{
				write(1, "+ o - alone! INVALID VALUE\n", 28);
				return (1);
			}
			a->size++;
		}
		i++;
	}
	create_int_array(a, argv);	
	return (0);
}
	
int		create_int_array(t_stack_a *a, char *argv)
{
	int		i;
	int		j;
	int		z;
	char	*str;
	(void)(argv);

	i = 0;
	j = 0;
	z = 0;
	a->array_int_a = (int *)ft_calloc(a->size, sizeof(int));
	str = (char *)ft_calloc( a->size, sizeof(char));
	while (a->array_a[i] != '\0')
	{
		j = 0;
		while ((a->array_a[i] != ' ' && a->array_a[i] != '\0') || (a->array_a[i] == '-') || (a->array_a[i] == '+'))
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
			break;
		}
		i++;
	}
	free (str);
	a->size_of_int = z;
	if (check_double(a) == 1)
		return (1);
	return (0);
}

int		check_double(t_stack_a *a)
{
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	ft_printf("SIZE OF INT = %d\n", a->size_of_int);
	while (i < a->size_of_int)
	{
		j = i + 1;
		//ft_printf("%d  ", a->array_int_a[i]);
		while (j < a->size_of_int)
		{
			if (a->array_int_a[j] == a->array_int_a[i])
			{
				write (1, "Error: Double INT", 18);
				return (1);
			}
			j++;
		}
		i++;
	}
	if (already_sorted(a) == 1)
		return (1);
	return(0);
}

int		already_sorted(t_stack_a *a)
{
	int i;

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