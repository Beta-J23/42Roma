/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:01:32 by alpelliz          #+#    #+#             */
/*   Updated: 2023/04/12 19:10:48 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int argc, char **argv)
{
	t_stack_a a;
	t_stack_b b;

	(void)b;
	//initializer(a, b);
	if (argc != 2)
	{
		write (1, "invalid number of args", 20);
		return (0);
	}
	a.array_a = (char *)malloc(sizeof(char) * ft_strlen(argv[1]));
	array_filler(&a, argv[1]);
	//create_int_array(&a, argv[1]);
	ft_printf("argv1 = %s\n", argv[1]);
	check_argv(&a);
	return (0);
}
