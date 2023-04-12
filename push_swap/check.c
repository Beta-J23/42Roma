/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:00:31 by alpelliz          #+#    #+#             */
/*   Updated: 2023/04/12 19:10:12 by alpelliz         ###   ########.fr       */
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
	int		j;
	int		z;
	//char	*str = NULL;
	//int		value;

	i = 0;
	j = 0;
	z = 0;
	/*
	a->array_int_a = (int *)ft_calloc(a->size, sizeof(int));

	while (a->array_a[i] != '\0')
	{
		if (a->array_a[i] != ' ')
		{
			str[z] = a->array_a[i];
			z++;
			i++;
		}
		if (a->array_a[i] == ' ')
		{
			value = ft_atoi(str);
			a->array_int_a[j] = value;
			j++;
		}
		i++;
	}*/

	ft_printf("array is a->array_int_a = %d\n", a->array_int_a);
	
	a->array_int_a = (int *)ft_calloc(a->size, sizeof(int));
	i = 0;
	j = 1;
	
	// searching doubles and converting argvChars to int;
	while (a->array_a[i] != '\0')
	{
		if (a->array_a[i] != ' ')
		{
			j = i + 1;
			a->array_int_a[i] = a->array_a[i] - 48;
			//ft_printf("digit = %d\n", a->array_a[i] - 48);
			if (ft_isdigit(a->array_a[i]) == 0)
			{
				write(1, "Invalid value", 14);
				return (1);
			}
			while (a->array_a[j] != '\0')
			{
				if (a->array_a[j] != ' ')
				{
					if (a->array_a[j] == a->array_a[i])
					{
						write(1, "number is double!", 18);
						return (2);
					}
				}
				j++;
			}
			a->size++;
		}
		i++;
	}
	ft_printf("size is: %d\n", a->size);
	return (0);
}
/*
int create_b(t_stack_a a, t_stack_b b)
{
	
}*/