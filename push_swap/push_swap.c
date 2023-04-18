/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:01:32 by alpelliz          #+#    #+#             */
/*   Updated: 2023/04/18 18:23:49 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int argc, char **argv)
{
	t_stack_a a;
	t_stack_b b;

	initializer(&a, &b);
	if (array_filler(&a, argv, argc) == 1)
		return (1);
	check_argv(&a);
	b.array_int_b = malloc(sizeof(int) * 6);
	b.size_of_int = 0;
	case_redirection(&a, &b);
	//ft_printf("Total moves: %d\n", a.counter);

	array_printer(&a, &b);
	free(a.array_a);
	return (0);
}
