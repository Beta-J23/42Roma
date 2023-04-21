
#include "push_swap.h"

// ra (rotate a): Shift up all elements of stack a by 1.
int	ra(t_stack_a *a)
{
	int		i;
	int		tmp;

	tmp = a->array_int_a[0];
	i = 0;
	while (i < a->size_of_int)
	{
		ft_swap (&a->array_int_a[i], &a->array_int_a[i + 1]);
		i++;
	}
	a->counter++;
	a->array_int_a[a->size_of_int - 1] = tmp;
	ft_printf("ra\n");
	return (0);
}

// rb (rotate b): Shift up all elements of stack b by 1.
int	rb(t_stack_b *b)
{
	int		i;
	int		tmp;

	tmp = b->array_int_b[0];
	i = 0;
	while (i < b->size_of_int)
	{
		ft_swap (&b->array_int_b[i], &b->array_int_b[i + 1]);
		i++;
	}
	b->array_int_b[b->size_of_int - 1] = tmp;
	ft_printf("rb\n");
	return (0);
}

// rr : ra and rb at the same time.
int	rr(t_stack_a *a, t_stack_b *b)
{
	int		i;
	int		tmp;

	tmp = a->array_int_a[0];
	i = 0;
	while (i < a->size_of_int)
	{
		ft_swap (&a->array_int_a[i], &a->array_int_a[i + 1]);
		i++;
	}
	a->counter++;
	a->array_int_a[a->size_of_int - 1] = tmp;
	tmp = b->array_int_b[0];
	i = 0;
	while (i < b->size_of_int)
	{
		ft_swap (&b->array_int_b[i], &b->array_int_b[i + 1]);
		i++;
	}
	b->array_int_b[b->size_of_int - 1] = tmp;
	ft_printf("rr\n");
	return (0);
}
