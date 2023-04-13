/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:01:32 by alpelliz          #+#    #+#             */
/*   Updated: 2023/04/13 19:44:28 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int argc, char **argv)
{
	t_stack_a a;
	t_stack_b b;

	(void)b;
	if (array_filler(&a, argv, argc) == 1)
		return (1);
	check_argv(&a);
	b.array_int_b = malloc(sizeof(int) * 6);
	b.size_of_int = 0;
	//sa(&a);
	//pb(&a, &b);
	//pb(&a, &b);
	//pb(&a, &b);
	array_printer(&a, &b);
	free(a.array_a);
	return (0);
}
