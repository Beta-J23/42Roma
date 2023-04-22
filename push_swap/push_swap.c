/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:01:32 by alpelliz          #+#    #+#             */
/*   Updated: 2023/04/21 18:17:29 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_a	a;
	t_stack_b	b;

	initializer(&a, &b);
	if (array_filler(&a, argv, argc) == 1)
		return (1);
	b.array_int_b = malloc(sizeof(int) * 6);
	check_argv(&a);
	error_checker(&a);
	case_redirection(&a, &b);
	free(a.array_a);
	//free(a.array_int_a);
	//free(b.array_int_b);
	if (a.array_int_a[0] > a.array_int_a[1])
		sa(&a);
	array_printer(&a, &b);
	if (sorting_check(&a, &b) == 0)
		ft_printf("array sorted!\n");
	return (0);
}
