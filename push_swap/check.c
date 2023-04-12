/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:00:31 by alpelliz          #+#    #+#             */
/*   Updated: 2023/04/12 13:25:56 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.c"

// Check if value is a number
int		is_num(char x)
{
	if (x >= 48 && x <= 57)
		return (0);
	else
	{
		write (1, "Invalid value", 14);
		return (1);
	}
}

// Check if value has already been submitted
int		double_num(t_stack c, char x, char y)
{
	
	while (stack[i] != '\0')
	{
		int	i;

		i = 0;
		if (x == y)
		{
			write(1, "number is double!", 18);
			return (1);
		}
		i++;
	}
	return (0);
}