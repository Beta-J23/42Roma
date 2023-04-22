/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:01:32 by alpelliz          #+#    #+#             */
/*   Updated: 2023/04/22 14:42:58 by alpelliz         ###   ########.fr       */
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
	check_argv(&a);
	error_checker(&a);
	free(a.array_a);
	case_redirection(&a, &b);
	if (a.array_int_a[0] > a.array_int_a[1])
		sa(&a);
	free(a.array_int_a);
	return (0);
}
