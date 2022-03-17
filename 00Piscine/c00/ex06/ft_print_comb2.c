/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:45:09 by alpelliz          #+#    #+#             */
/*   Updated: 2022/02/07 15:05:10 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char x)
{
	write (1, &x, 1);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			print (a / 10 + 48);
			print (a % 10 + '0');
			print (' ');
			print (b / 10 + '0');
			print (b % 10 + '0');
			if (a != 98)
			{	
				print (',');
				print (' ');
			}	
			b++;
		}
		a++;
	}
}
