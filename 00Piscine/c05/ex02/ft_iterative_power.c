/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:00:02 by alpelliz          #+#    #+#             */
/*   Updated: 2022/02/24 15:04:57 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	x;

	x = nb;
	i = 1;
	if (power == 0)
		return (1);
	while (i < power)
	{
		x = x * nb;
		i++;
	}
	return (x);
}
