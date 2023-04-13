/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:00:31 by alpelliz          #+#    #+#             */
/*   Updated: 2023/04/13 12:50:51 by alpelliz         ###   ########.fr       */
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

int array_filler(t_stack_a *a, char *arg)
{
	int		i;

	i = 0;
	//a->array_a = malloc(sizeof(char) * a->size); 
	while (arg[i] != '\0')
	{
		a->array_a[i] = arg[i];
		i++;
	}
	//a->size = i;
	return (0);
}
/*
int		create_int_array(t_stack_a *a, char *argv)
{
	int		i;
	int		j;
	int		z;
	char	*str = NULL;

	i = 0;
	j = 0;
	z = 0;
	while (argv[i] != '\0')
	{
		while (a->array_a[i] != ' ')
		{
			str[j] = a->array_a[i];
			j++;
			i++;
		}
		a->array_int_a[z] = ft_atoi(str);
		ft_printf("array is a->array_int_a = %d\n", a->array_int_a);
		j = 0;
		z++;
		i++;
	}
	return (0);
}*/

/* check_argv: check if: argv is a number; it's double, calculate size, convert array to int, determine Size jumping spaces,*/
int		check_argv(t_stack_a *a)
{
	int		i;

	int		z;
	char *argv = NULL;
	(void)argv;
	//char	*str = NULL;
	//int		value;

	i = 0;

	z = 0;

	//ft_printf("array is a->array_int_a = %d\n", a->array_int_a);
	
	i = 0;

	
	// searching doubles and converting argvChars to int;
	while (a->array_a[i] != '\0')
	{
		if (a->array_a[i] != ' ')
		{

			//a->array_int_a[i] = a->array_a[i] - 48;
			//ft_printf("digit = %d\n", a->array_a[i] - 48);
			if ((ft_isdigit(a->array_a[i]) == 0) && (a->array_a[i] != '-') && (a->array_a[i] != '+'))
			{
				ft_printf("INCRIMINATED: %d\n", a->array_a[i]);
				write(1, "Invalid value", 14);
				return (1);
			}
			
			// preparing for accepting decimal hundreds etc.
			a->size++;
		}
		i++;
	}
	create_int_array(a, argv);
	//ft_printf("size is: %d\n", a->size);
	
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
	//ft_printf("size is: %d\n", a->size);
	str = (char *)ft_calloc( a->size, sizeof(char));
	//str = (char *)malloc(sizeof(char) * 9999);
	while (a->array_a[i] != '\0')
	{
		j = 0;
		while (a->array_a[i] != ' ' && a->array_a[i] != '\0')
		{
			str[j] = a->array_a[i];
			j++;
			i++;
		}
		str[j] = '\0';
		//ft_printf("STR: %s\n", str);
		a->array_int_a[z] = ft_atoi(str);
		//ft_printf("array int [z]: %d\n", a->array_int_a[z]);
		z++;
		//ft_printf("array: %d\n", a->array_int_a[z]);
		i++;
	}
	free (str);
	//ft_printf("array int [z]: %d\n", a->array_int_a[z]);
	//ft_printf("ZETONA: %d\n",z);
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
		ft_printf("%d  ", a->array_int_a[i]);
		while (j < a->size_of_int)
		{
			if (a->array_int_a[j] == a->array_int_a[i])
			{
				write (1, "Error: Double INT", 20);
				return (1);
			}
			j++;
		}
		//ft_printf("int array is %d  ", i);
		i++;
	}
	return(0);
}
