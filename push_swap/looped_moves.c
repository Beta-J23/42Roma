/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   looped_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:28:20 by alpelliz          #+#    #+#             */
/*   Updated: 2023/04/20 17:29:01 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	//ft_printf("MOVING UP B, X = %d\n", x);
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