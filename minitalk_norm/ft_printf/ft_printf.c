/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 17:42:07 by alpelliz          #+#    #+#             */
/*   Updated: 2022/06/07 15:16:36 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	checktype(va_list arg, const char type)
{
	int	counter;

	counter = 0;
	if (type == 'c')
		counter += ft_putchar(va_arg(arg, int));
	if (type == 's')
		counter += ft_putstr(va_arg(arg, char *));
	if (type == 'p')
		counter += hex_converter(va_arg(arg, long long), type);
	if (type == 'd')
		counter += ft_putnbr(va_arg(arg, int));
	if (type == 'i')
		counter += ft_putnbr(va_arg(arg, int));
	if (type == 'u')
		counter += ft_putnbr_unsigned(va_arg(arg, unsigned int));
	if (type == 'x')
		counter += hex_converter(va_arg(arg, int), type);
	if (type == 'X')
		counter += hex_converter(va_arg(arg, int), type);
	if (type == '%')
		counter += ft_putchar('%');
	return (counter);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str)
		return (0);
	va_start (arg, str);
	while (str[i] != '\0')
	{	
		if (str[i] == '%')
		{
			i++;
			j += checktype(arg, str[i]);
		}
		else
		{
			write(1, &str[i], 1);
			j++;
		}
		i++;
	}
	va_end(arg);
	return (j);
}
