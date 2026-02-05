/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:59:12 by alpelliz          #+#    #+#             */
/*   Updated: 2022/06/07 15:08:46 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count(unsigned int nb, char type)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb = nb / 16;
		i++;
	}
	if (type == 'p')
		i = (i + 2);
	return (i);
}

int	ft_hex(unsigned int nb, char type)
{
	if (nb >= 16)
	{
		ft_hex(nb / 16, type);
		ft_hex(nb % 16, type);
	}
	else if (nb <= 9)
		ft_putchar(nb + '0');
	else if (nb > 9 && nb < 16)
	{
		if (type == 'x' || type == 'p')
			ft_putchar(nb - 10 + 'a');
		if (type == 'X')
			ft_putchar(nb - 10 + 'A');
	}
	else
		ft_putchar(nb + '0');
	return (0);
}

int	ft_count_p(unsigned long long nb)
{
	int	i;

	i = 0;
	while (nb != 0)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}

void	ft_hex_g(unsigned long long nb)
{
	if (nb >= 16)
	{
		ft_hex_g(nb / 16);
		ft_hex_g(nb % 16);
	}
	else
	{
		if (nb <= 9)
			ft_putchar(nb + '0');
		else
			ft_putchar(nb - 10 + 'a');
	}
}

int	hex_converter(unsigned long long nb, char type)
{
	if (type == 'p')
	{
		write(1, "0x", 2);
		if (nb == 0)
			return (write(1, "0", 1) + 2);
		else
			ft_hex_g(nb);
		return (ft_count_p(nb) + 2);
	}
	ft_hex(nb, type);
	return (ft_count(nb, type));
}
