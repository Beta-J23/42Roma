/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 11:02:17 by alpelliz          #+#    #+#             */
/*   Updated: 2023/04/22 13:24:21 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//appunti per ulteriori implementazioni
//sorting with move prevision, possibili implementazioni:
//- see if array already sorted.
//- se numero di mosse e' uguale prediligi nummero piu piccolo per pb.
//- rivedi algoritmo ra e rra prima del pb.
//- se pos_a = pos_b vedi se possibile rr e rrr.

int	number_100(t_stack_a *a, t_stack_b *b)
{
	int		j;
	int		z;
	int		x;
	int		value;
	int		pre_b;

	j = 0;
	x = 0;
	value = 0;
	z = a->size_of_int;
	b->array_int_b = malloc(sizeof(int) * (b->size_of_int));
	while (j < z)
	{
		x = moving_convenience_2(a, b, 0, 0);
		value = a->array_int_a[x];
		pre_b = position_number_b(a, b, value);
		move_b(a, b, pre_b, value);
		if (moving_convenience(a, b, x) == 0)
			pb(a, b);
		j++;
	}
	number_100_helper(a, b, z);
	return (0);
}

int	number_100_helper(t_stack_a *a, t_stack_b *b, int z)
{
	int		j;
	int		biggest;

	j = 0;
	biggest = 0;
	biggest = biggest_number_b(a, b);
	moving_convenience_b(a, b, biggest);
	while (j < z)
	{
		pa(a, b);
		j++;
	}
	free(b->array_int_b);
	return (0);
}

//CALCOLO POSIZIONE IN B
int	position_number_b(t_stack_a *a, t_stack_b *b, int num_a)
{
	int		i;
	int		j;
	int		z;

	(void)a;
	i = 0;
	j = 0;
	z = 0;
	while (i < b->size_of_int)
	{
		if ((num_a < b->array_int_b[i]) && (num_a > b->array_int_b[i + 1]))
		{
			i++;
			break ;
		}
		if (num_a < b->array_int_b[i])
			z++;
		if (z == b->size_of_int - 1)
		{
			j = biggest_number_b(a, b);
			return (j);
		}
		i++;
	}
	return (i);
}

// v[7] = Array di var per risparmio righe per norma. 
// v[0] = i; v[1] = j; v[2] = y; v[3] = z; v[4] = number_a; v[5] minimum_a
// v[6] = minimum_b

int	moving_convenience_2(t_stack_a *a, t_stack_b *b, int pos_a, int pos_b)
{
	int		v[7];
	int		*tmp;
	int		number_to_choose;

	v[0] = 0;
	v[1] = 0;
	tmp = ft_calloc(a->size_of_int, sizeof(int));
	pos_a = 0;
	pos_b = 0;
	moving_convenience_2_helper(a, b, v, tmp);
	number_to_choose = smallest_usable(tmp, a->size_of_int);
	free(tmp);
	return (number_to_choose);
}

int	*moving_convenience_2_helper(t_stack_a *a, t_stack_b *b, int *v, int *tmp)
{
	int		pos_a;
	int		pos_b;

	pos_a = 0;
	while (v[0] < a->size_of_int)
	{
		v[4] = a->array_int_a[pos_a];
		pos_b = position_number_b(a, b, v[4]);
		v[2] = a->size_of_int - pos_a;
		v[3] = b->size_of_int - pos_b;
		if (v[2] < pos_a)
			v[5] = v[2];
		if (pos_a <= v[2])
			v[5] = pos_a;
		if (v[3] < pos_b)
			v[6] = v[3];
		if (pos_b <= v[3])
			v[6] = pos_b;
		tmp[v[0]] = (v[5] + v[6]);
		pos_a++;
		v[1]++;
		v[0]++;
	}
	return (tmp);
}
