
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
	int		biggest;

	biggest = 0;
	j = 0;
	x = 0;
	value = 0;
	z = a->size_of_int;
	b->array_int_b = malloc(sizeof(int) * (a->size_of_int));
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
	j = 0;
	biggest = biggest_number_b(a, b);
	moving_convenience_b(a, b, biggest);
	while (j < z)
	{
		pa(a, b);
		j++;
	}
	//free(b->array_int_b);
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

// riempio array tmp di valori
// calcolo se piu vicino al top o bottom (stack_B)
// inserisco nell'array la somma dei valori

int	moving_convenience_2(t_stack_a *a, t_stack_b *b, int pos_a, int pos_b)
{
	int		i;
	int		j;
	int		*tmp;
	int		y;
	int		z;
	int		number_a;
	int		minimum_a;
	int		minimum_b;
	int		number_to_choose;

	i = 0;
	j = 0;
	tmp = ft_calloc(a->size_of_int, sizeof(int));
	pos_a = 0;
	pos_b = 0;
	while (i < a->size_of_int)
	{
		number_a = a->array_int_a[pos_a];
		pos_b = position_number_b(a, b, number_a);
		y = a->size_of_int - pos_a;
		z = b->size_of_int - pos_b;
		if (y < pos_a)
			minimum_a = y;
		if (pos_a <= y)
			minimum_a = pos_a;
		if (z < pos_b)
			minimum_b = z;
		if (pos_b <= z)
			minimum_b = pos_b;
		tmp[i] = (minimum_a + minimum_b);
		pos_a++;
		j++;
		i++;
	}
	number_to_choose = smallest_usable(tmp, a->size_of_int);
	free(tmp);
	return (number_to_choose);
}

int	smallest_usable(int *tmp, int size)
{
	int		i;
	int		j;
	int		z;

	i = 0;
	j = 0;
	z = 0;
	while (i < size)
	{
		j = 0;
		z = 0;
		while (j < size)
		{
			if (tmp[i] <= tmp[j])
				z++;
			if (z == size)
				break ;
			j++;
		}
		if (z == size)
			break ;
		i++;
	}
	return (i);
}

int	biggest_b(t_stack_a *a, t_stack_b *b, int num)
{
	int		i;

	(void)a;
	i = 0;
	while (i < b->size_of_int)
	{
		if (num < b->array_int_b[i])
			break ;
		i++;
	}
	return (i - 1);
}
