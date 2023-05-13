/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:55:15 by alpelliz          #+#    #+#             */
/*   Updated: 2023/05/13 18:03:40 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (0);
	else
		return (1);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	atoi_limit(long long nb)
{
	if ((nb < -2147483648) || (nb > 2147483647))
	{
		write(2, "Error\n", 6);
		exit (0);
	}
	else
		return ((int)nb);
}

int	ft_atoi_mod(char *str)
{
	int			i;
	int			var;
	long long	intero;

	var = 1;
	i = 0;
	intero = 0;
	while ((str[i] == '\t') || (str[i] == '\n') || (str[i] == '\v')
		|| (str[i] == '\f') || (str[i] == '\r') || (str[i] == ' '))
	{
		i++;
	}
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			var = var * -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		intero = intero * 10 + (str[i] - 48);
		i++;
	}
	return (atoi_limit(intero * var));
}
