/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:13:13 by alpelliz          #+#    #+#             */
/*   Updated: 2023/04/19 23:52:05 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//per sapere il numero piu alto di pb salvo tmp prima di inviarlo.
//scorro l'array_a controllo il numero piu piccolo,
//calcolo le mosse che servono per portarlo in cima ad A. 
//calcolo le mosse che servono per metterlo al posto corretto in b.
//sommo i due risultati.
//controllo il prossimo numero.
//
//

int number_100(t_stack_a *a, t_stack_b *b)
{
	int		i;
	int		j;
	int		z;
	int		x;
    int     tmp; //store in tmp smallest number before pb. (per avere il numero piu alto di stack b)
	//int		k;
	int		w;
	int		value;
	//int		*fake_array;

    tmp = 0;
	i = 0;
	j = 0;
	w = 0;
	x = 0;
	value = 0;
	z = a->size_of_int;
	//k = biggest_number(a, b);
	//i = smallest_number(a, b);
	//ft_printf("\n\n\nsmallest number is: %d\n\n\n\n", a->array_int_a[i]);
	//moving_convenience(a, b, i);
	//fake_order(a, b);
	b->array_int_b = malloc(sizeof(int) * a->size_of_int);
	//trying sort with moves prevision (previsione delle mosse)
	b->array_int_b[0] = 0;
	while (j < z - 1)
	{
		//i = smallest_number_modified(a, b, w); //smallest number + 1 in loop
		//w++;
		x = moving_convenience_2(a, b, 0, 0);
		value = array_comparator(a, b, x);
		ft_printf("Array comparator value %d\n", value);
		moving_convenience_b(a, b, value);
		if (moving_convenience(a, b, value) == 0)
			pb(a, b);
		j++;
	}
	j = 0;
	
	while (j < z - 1)
	{
		pa(a, b);
		j++;
	}
	free(b->array_int_b);
	return (0);
}

//COMPARATORE ARRAY A per trovare la posizione in cui si trova il numero consigliato.
int array_comparator(t_stack_a *a, t_stack_b *b, int x)
{
	(void)b;
	int		i;
	i = 1;
	while (i <= a->size_of_int)
	{
		if (x == a->array_int_a[i])
			break;
		i++;
	}
	return (i);
}

//CALCOLO POSIZIONE IN B
int		position_number_b(t_stack_a *a, t_stack_b *b, int number_a)
{
	(void)a;
	int		i;
	
	i = 0;
	while (i < b->size_of_int - 1)
	{
		if ((number_a > b->array_int_b[i]) && (number_a < b->array_int_b[i + 1]))
		{
			break;
		}	
		i++; 
	}
	ft_printf("POSITION NUMBER B I = %d, array_int_b[i]= %d\n", i, b->array_int_b[i]);
	ft_printf("b->size_of_int = %d\n", b->size_of_int);
	return(i);
}

int	moving_convenience_2(t_stack_a *a, t_stack_b *b, int pos_a, int pos_b)
{
	(void)b;
	int		i;
	int		j;
	int		tmp[99];
	int		y;
	int		z;
	int		number_a;

	i = 0;
	j = 0;
	//tmp = malloc(sizeof(int) * a->size_of_int);
	//y = a->size_of_int - pos_a;
	//z = b->size_of_int - pos_b;
	
	//int		*total_moves;
	int		minimum_a;
	int		minimum_b;

	int		number_to_choose;
	
	//CREARE UN CICLO CON TUTTI GLI IF SOTTO
/*
	// calcolo se piu vicino al top o bottom (stack_A) -- minimum = soluzione migliore per a
	if (y <= pos_a)
		minimum_a = y;
	if (pos_a < y)
		minimum_a = pos_a;
	
	//calcolo se piu vicino al top o bottom (stack_B)
	pos_b = position_number_b(a, b);
	if (z <= pos_b)
		minimum_b = z;
	if (pos_b < z)
		minimum_b = pos_b;

	//calcolo tra i due minimum quale da il minor numero di mosse e salvo il valore in un array -- l'array dovra poi passare in un ciclo per vedere il valore con il numero piu basso di mosse.
	//if (minimum_b < minimum_a)
	//	tmp[i] = minimum_b;
	//if (minimum_a <= minimum_b)
	//	tmp[i] = minimum_a;

	//calcolo la somma dei due minimum e salvo il valore in un array -- l'array dovra poi passare in un ciclo per vedere il valore con il numero piu basso di mosse.
	tmp[i] = (minimum_a + minimum_b);
	// return valore con numero piu conveniente (tmp alla posizione i corrispondera al valore dell'array)
	*/

	// riempio array tmp di valori
	while (i < a->size_of_int - 1)
	{
		pos_a = smallest_number_position(a, b, j);
		number_a = smallest_number_mod(a, b, j);
		pos_b = position_number_b(a, b, number_a);
		ft_printf("pos b = %d number_a = %d\n", pos_b, number_a);
		//exit(0);
		y = a->size_of_int - pos_a;
		z = b->size_of_int - pos_b;
		if (y <= pos_a)
			minimum_a = y;
		if (pos_a < y)
			minimum_a = pos_a;
		
		//calcolo se piu vicino al top o bottom (stack_B)
		if (z <= pos_b)
			minimum_b = z;
		if (pos_b < z)
			minimum_b = pos_b;
		tmp[i] = (minimum_a + minimum_b);
		j++;
		i++;
	}
	//array print
	ft_printf("\nI = %d\n", i);
	ft_printf("tmp is: ");
	i = 0;
	while (tmp[i] < a->size_of_int)
	{
		ft_printf("%d ", tmp[i]);
		i++;
	}
	ft_printf("\na->size_of_int = %d", a->size_of_int);
	// trova il numero pu basso dell array TMP
	ft_printf("BEFORE NUMBER TO CHOOSE: tmp[i] = %d, i = %d\n", tmp[i], i);
	exit(0);
	number_to_choose = smallest_usable(tmp, i);
	ft_printf("number to choose = %d\n", number_to_choose);
	//exit(0);
	free(tmp);
	return(number_to_choose);
}

int	smallest_number_position(t_stack_a *a, t_stack_b *b, int i)
{
	(void)b;
	//int		i;
	int		j;
	int		z;

	//i = 0;
	j = i;
	z = 0;
	while (i < a->size_of_int)
	{
		j = i;
		z = 0;
		while (j < a->size_of_int)
		{
			if (a->array_int_a[i] <= a->array_int_a[j])
				z++;
			if (z == a->size_of_int - i)
			{
				//ft_printf("numero piu basso trovato e: %d\n", tmp);
				break;
			}
			j++;
		}
		if (z == a->size_of_int - i)
		{
			//ft_printf("numero piu basso trovato e: %d\n", tmp);
			break;
		}
		i++;
	}
	return (i);
}

// Return il valore dell'array nella posizione cercata.
int	smallest_number_mod(t_stack_a *a, t_stack_b *b, int i)
{
	(void)b;
	//int		i;
	int		j;
	int		z;

	//i = 0;
	j = i;
	z = 0;
	while (i < a->size_of_int)
	{
		j = i;
		z = 0;
		while (j < a->size_of_int)
		{
			if (a->array_int_a[i] <= a->array_int_a[j])
				z++;
			if (z == a->size_of_int - i)
			{
				//ft_printf("numero piu basso trovato e: %d\n", tmp);
				break;
			}
			j++;
		}
		if (z == a->size_of_int - i)
		{
			//ft_printf("numero piu basso trovato e: %d\n", tmp);
			break;
		}
		i++;
	}
	return (a->array_int_a[i]);
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
				break;
			j++;
		}
		if (z == size)
		{
			//ft_printf("numero piu basso trovato e: %d\n", tmp);
			break;
		}
		i++;
	}
	return (tmp[i]);
}



int	moving_convenience(t_stack_a *a, t_stack_b *b, int x)
{
	(void)b;
	int		i;
	int		y;

	i = 0;
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

int	move_up_b(t_stack_a *a, t_stack_b *b, int	x)
{
	(void)a;
	
	while (x > 0)
	{
		rb(b);
		x--;
	}
	//ft_printf("MOVING UP");
	return (0);
}

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

int	move_down_b(t_stack_a *a, t_stack_b *b, int	y)
{
	(void)a;

	while (y < b->size_of_int)
	{
		rrb(b);
		y++;
	}
	//ft_printf("MOVING DOWN");
	return (0);
}



int	moving_convenience_b(t_stack_a *a, t_stack_b *b, int x)
{
	(void)a;
	int		i;
	int		*tmp;
	int		y;

	i = 0;
	tmp = malloc(sizeof(int) * a->size_of_int);
	//int		z;
	y = b->size_of_int - x;
	//z = a->size_of_int - k;
	
	if (y <= x)
	{
		move_down_b(a, b, x);
	}
	if (x < y)
	{
		move_up_b(a, b, x);
	}

	return(0);
}