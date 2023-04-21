#include "push_swap.h"

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
		//move_down_b(a, b, biggest_b(a, b, b->array_int_b[b->size_of_int - 1]));
	}
	if (value > b->array_int_b[biggest_number_b(a, b)])
	{
		while (b->array_int_b[0] != b->array_int_b[biggest_number_b(a, b)])
		{
			rrb(b);
		}
		//ft_printf("BIG B = %d\n", b->array_int_b[biggest_number_b(a, b)]);
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
}