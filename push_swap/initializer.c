/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:13:24 by alpelliz          #+#    #+#             */
/*   Updated: 2023/04/21 12:37:35 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initializer(t_stack_a *a, t_stack_b *b)
{
	a->index = 0;
	b->index = 0;
	b->size_of_int = 0;
	a->size = 0;
	b->size = 0;
}
