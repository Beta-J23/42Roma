/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_array_creator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 11:01:31 by alpelliz          #+#    #+#             */
/*   Updated: 2023/04/22 11:01:33 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	create_int_array(t_stack_a *a)
{
	int		i;
	int		z;
	char	*str;

	i = 0;
	z = 0;
	a->array_int_a = (int *)ft_calloc(a->size, sizeof(int));
	str = (char *)ft_calloc(a->size, sizeof(char));
	z = create_int_array_helper(a, str, i, z);
	free (str);
	a->size_of_int = z;
	return (0);
}

int	create_int_array_helper(t_stack_a *a, char *str, int i, int z)
{
	int		j;

	j = 0;
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
			break ;
		if (a->array_a[i] == '\0')
			break ;
		i++;
	}
	return (z);
}
