
#include "push_swap.h"

// rra Shift down all elements of stack a by 1.
int	rra(t_stack_a *a)
{
	int		i;
	int		tmp;

	tmp = a->array_int_a[a->size_of_int - 1];
	i = a->size_of_int - 1;
	while (i >= 0)
	{
		ft_swap (&a->array_int_a[i - 1], &a->array_int_a[i]);
		i--;
	}
	a->counter++;
	a->array_int_a[0] = tmp;
	ft_printf("rra\n");
	return (0);
}

// rrb Shift down all elements of stack b by 1
int	rrb(t_stack_b *b)
{
	int		i;
	int		tmp;

	tmp = b->array_int_b[b->size_of_int - 1];
	i = b->size_of_int - 1;
	while (i >= 0)
	{
		ft_swap (&b->array_int_b[i - 1], &b->array_int_b[i]);
		i--;
	}
	b->array_int_b[0] = tmp;
	ft_printf("rrb\n");
	return (0);
}

// rrr : rra and rrb at the same time.
int	rrr(t_stack_a *a, t_stack_b *b)
{
	int		i;
	int		tmp;

	tmp = a->array_int_a[a->size_of_int - 1];
	i = a->size_of_int;
	while (i > 0)
	{
		ft_swap (&a->array_int_a[i - 1], &a->array_int_a[i]);
		i--;
	}
	a->counter++;
	a->array_int_a[0] = tmp;
	tmp = b->array_int_b[b->size_of_int - 1];
	i = b->size_of_int;
	while (i > 0)
	{
		ft_swap (&b->array_int_b[i - 1], &b->array_int_b[i]);
		i--;
	}
	b->array_int_b[0] = tmp;
	ft_printf("rrr\n");
	return (0);
}
