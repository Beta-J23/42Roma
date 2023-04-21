/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:57:17 by alpelliz          #+#    #+#             */
/*   Updated: 2023/04/21 18:26:33 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int number_100(t_stack_a *a, t_stack_b *b)
{
	int		i;
	int		j;
	int		z;
	int		x;
    int     tmp; //store in tmp smallest number before pb. (per avere il numero piu alto di stack b)
	int		w;
	int		value;
	int		pre_b;
	int		moving_conv;
	int		biggest;

	biggest = 0;
	moving_conv = 0;
    tmp = 0;
	i = 0;
	j = 0;
	w = 0;
	x = 0;
	value = 0;
	z = a->size_of_int;
	b->array_int_b = malloc(sizeof(int) * a->size_of_int);
	//sorting with move prevision, possibili implementazioni:
	//- see if array already sorted.
	//- se numero di mosse e' uguale prediligi nummero piu piccolo per pb.
	//- rivedi algoritmo ra e rra prima del pb.
	//- se pos_a = pos_b vedi se possibile rr e rrr.
	while (j < z)
	{
		x = moving_convenience_2(a, b, 0, 0); // moving_convenience_2 returns number to choose, X E'L'INDICE PER ARRAY COMPARATOR
		value = a->array_int_a[x];
		pre_b = position_number_b(a, b, value); // la posizione che ricoprira'in B
		///////ft_printf("\nArray comparator value %d\n", value);
		///////ft_printf("\npre_b %d\n", pre_b);
		//moving_convenience_b(a, b, pre_b);
		move_b(a, b, pre_b, value);
		if (moving_convenience(a, b, x) == 0)
			pb(a, b);
		j++;
	}
	j = 0;
	biggest = biggest_number_b(a, b);
    ////ft_printf("biggest_number = %d\n", b->array_int_b[biggest]);
	/////ft_printf("pre moving. biggest = %d\n", biggest);
	//move_b(a, b, pre_b, biggest);
	moving_convenience_b(a, b , biggest);
	//array_printer(a, b);
	while (j < z)
	{
		pa(a, b);
		j++;
	}
	//free(b->array_int_b);
	return (0);
}

//COMPARATORE ARRAY A per trovare la posizione in cui si trova il numero consigliato.
int array_comparator(t_stack_a *a, t_stack_b *b, int x)
{
	(void)b;
	int		i;
	i = 0;
	while (i < a->size_of_int)
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
	int		j;
	int		z;
	
	i = 0;
	j = 0;
	z = 0;
	while (i < b->size_of_int)
	{
		if ((number_a < b->array_int_b[i]) && (number_a > b->array_int_b[i + 1]))
		{
			i++;
			break;
		}	
		// if ((number_a > b->array_int_b[i]))
		// {
		// 	break;
		// }
		if (number_a < b->array_int_b[i])
			z++;
		if (z == b->size_of_int - 1)
		{
			j = biggest_number_b(a, b);
			return (j);
		}
		i++; 
	}
	//ft_printf("POSITION NUMBER B I = %d, array_int_b[i]= %d\n", i, b->array_int_b[i]);
	//ft_printf("b->size_of_int = %d\n", b->size_of_int);
	return(i);
}

int	moving_convenience_2(t_stack_a *a, t_stack_b *b, int pos_a, int pos_b)
{
	(void)b;
	int		i;
	int		j;
	int		*tmp = NULL; //ogni posizione e'composta dalla somma del numero di mosse A + B
	int		y;
	int		z;
	int		number_a;
	int		*array_reserve; // accumulare numeri gia utilizzati nella funzione smallest number.
	//int		number_index_a;

	i = 0;
	j = 0;
	//tmp = (int *)malloc(sizeof(int) * a->size_of_int);
	tmp = ft_calloc(a->size_of_int, sizeof(int));
	array_reserve = ft_calloc(a->size_of_int, sizeof(int));
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
	pos_a = 0;
	pos_b = 0;
	// riempio array tmp di valori
	while (i < a->size_of_int)
	{
		//trova index numero piu piccolo, ad ogni ciclo incrementa di uno, saltando i numeri gia visti tramite salvataggio in a array reserve
		//pos_a = smallest_number_position(a, b, j, array_reserve);
		//ft_printf ("pos_a = %d\n", pos_a);
		//trova nello stack_A numero corrispondente all'index pos_a
		number_a = a->array_int_a[pos_a];
		//ft_printf("\n\nNUMBER A= %d, POS A = %d, J = %d \n\n", number_a, pos_a, j);
		pos_b = position_number_b(a, b, number_a); // CONTROLLARE DOVE VIENE UTILIZZATO POS_B POSSIBILE NUMERO MOSSE ERRATO.
		//ft_printf("FUTURE POSITION NUMBER_A IN B I = %d, numero piu vicino = array_int_b[i]= %d\n", pos_b, b->array_int_b[i]);
		//ft_printf("pos b = %d number_a = %d\n", pos_b, number_a);
		y = a->size_of_int - pos_a;
		z = b->size_of_int - pos_b;
		if (y < pos_a)
			minimum_a = y;
		if (pos_a <= y)
			minimum_a = pos_a;
		//calcolo se piu vicino al top o bottom (stack_B)
		if (z < pos_b)
			minimum_b = z;
		if (pos_b <= z)
			minimum_b = pos_b;
		tmp[i] = (minimum_a + minimum_b);
		//ft_printf("number_a = %d, minimum A = %d, minimum B = %d, i = %d, tmp[i] = %d, pos_b %d\n", number_a, minimum_a, minimum_b, i, tmp[i], pos_b);
		//array_printer(a, b);
		pos_a++;
		j++;
		i++;
	}
	//array print
	////////ft_printf("tmp is: ");
	i = 0;
	while (i < a->size_of_int)
	{
		///////ft_printf("%d ", tmp[i]);
		i++;
	}
	// trova il numero pu basso dell array TMP (tmp = somma delle mosse)
	//ft_printf("BEFORE NUMBER TO CHOOSE: tmp[i] = %d, i = %d\n", tmp[i], i);
	number_to_choose = smallest_usable(tmp, a->size_of_int); //smallest usable returns tmp[i] PROBABILE ERRORE!!!!! QUESTO E IL NUMERO DI MOSSE MINIMO NON IL VALORE!!!!!
	/////ft_printf("number to choose = %d\n", a->array_int_a[number_to_choose]);
	/////ft_printf("a->size_of_int = %d\n", a->size_of_int);
	free(tmp);
	free(array_reserve);
	return(number_to_choose);
}


/*int	smallest_number_position(t_stack_a *a, t_stack_b *b, int k, int	*array_reserve)
{
	(void)b;
	int		i;
	int		j;
	int		z;

	i = 0;
	j = 0;
	z = 0;
	while (i < a->size_of_int)
	{
		while (j < a->size_of_int)
		{
			if (a->array_int_a[i] == array_reserve[j])
				i++;
			j++;
		}
		
		j = 0;
		z = 0;
		while (j < a->size_of_int)
		{
			
			if (a->array_int_a[i] <= a->array_int_a[j])// && a->array_int_a[i] != array_reserve[i])
				z++;
			if (z == a->size_of_int - k)
			{
				break;
			}
			j++;
		}
		if (z == a->size_of_int - k)
		{
			//ft_printf("numero piu basso trovato e: %d\n", tmp);
			break;
		}
		i++;
	}
	ft_printf("\n\nA[i]= %d, A[j] = %d, K = %d a->size = %d, Z = %d \n\n", a->array_int_a[i], a->array_int_a[j], k, a->size_of_int, z);
	array_reserve[k] = a->array_int_a[i];
	ft_printf("array rserve[k] = %d\n", array_reserve[k]);
	return (i);
}*/

// Return il valore dell'array nella posizione cercata.
int	smallest_number_mod(t_stack_a *a, t_stack_b *b, int pos_a)
{
	(void)b;
	int		i;
	int		j;
	int		z;

	i = 0;
	j = 0;
	z = 0;
	while (i < a->size_of_int)
	{
		j = 0;
		z = 0;
		while (j < a->size_of_int)
		{
			if (a->array_int_a[i] <= a->array_int_a[j])
				z++;
			if (z == a->size_of_int - pos_a)
			{
				break;
			}
			j++;
		}
		if (z == a->size_of_int - pos_a)
		{
			break;
		}
		i++;
	}
	//////////ft_printf("SMALLEST NUMBER MOD numero piu basso trovato e: %d\n", a->array_int_a[i]);
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
			break;
		}
		i++;
	}
	//////ft_printf("\n\n\nIN SMALLEST USABLE tmp[i]: %d, i = %d\n\n\n", tmp[i], i);
	return (i); // FORSE MEGLIO TORNARE L'INDICE 
}
/*
int	moving_convenience(t_stack_a *a, t_stack_b *b, int x)
{
	(void)b;
	int		y;

	y = a->size_of_int - x;
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

int	moving_convenience_b(t_stack_a *a, t_stack_b *b, int x)
{
	(void)a;
	int		i;
	int		y;

	i = 0;
	y = b->size_of_int - x;
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

int	move_b(t_stack_a *a, t_stack_b *b, int x, int value)
{
	(void)a;
	int		i;
	int		y;

	i = 0;
	y = b->size_of_int - x;
	// se pre_b e'maggiore di tutti, e il piu grande di b si trova alla fine.
	////ft_printf("VALUE A = %d\n", value);
	/////ft_printf("VALUE B = %d\n", b->array_int_b[b->size_of_int - 1]);
	/////ft_printf("BIG B POS = %d\n", biggest_b(a, b, b->array_int_b[b->size_of_int - 1]));	
	if ((value > b->array_int_b[b->size_of_int - 1]) && (biggest_b(a, b, b->array_int_b[b->size_of_int - 1]) == b->size_of_int - 1))
	{
		///////ft_printf("\n\n\n\n\n\nDFEFFRSCVGFDT BOOOOOOOOOOOOOO IF\n\n\n\n\n");
		rrb(b);
	}
	if (y <= x)
	{
		move_down_b(a, b, x);
	}
	if (x < y)
	{
		move_up_b(a, b, x);
	}

	return(0);
}*/

int		biggest_b(t_stack_a *a, t_stack_b *b, int num)
{
	(void)a;
	int		i;
	
	i = 0;
	while (i < b->size_of_int)
	{
		if (num < b->array_int_b[i])
		{
			break;
		}
		i++; 
	}
	//ft_printf("\n\n\n\n\n\nsono nel biggest MOVEB IIIIIII = %d sizeofint = %d\n\n\n\n\n", i, b->size_of_int);
	//ft_printf("POSITION NUMBER B I = %d, array_int_b[i]= %d\n", i, b->array_int_b[i]);
	//ft_printf("b->size_of_int = %d\n", b->size_of_int);
	return(i - 1);
}