/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:59:34 by alpelliz          #+#    #+#             */
/*   Updated: 2023/05/13 18:25:02 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	arg_checker(int argc, char **argv)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	if ((argc > 6) || (argc < 5))
	{
		write(2, "Invalid number of args\n", 23);
		exit (0);
	}
	number_checker(argc, argv, i, j);
	minimum_checker(argc, argv, i, j);
	max_num(ft_atoi_mod(argv[1]));
	return (0);
}

int	number_checker(int argc, char **argv, int i, int j)
{
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0' )
		{
			if (ft_isdigit(argv[i][j]) != 0)
			{
				write(2, "Error, only number are allowed\n", 32);
				exit (0);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	minimum_checker(int argc, char **argv, int i, int j)
{
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0' )
		{
			if (argv[i][j] < '1')
			{
				write(2, "Error\n", 7);
				exit (0);
			}
			break ;
		}
		i++;
	}
	return (0);
}

int	max_num(int x)
{
	if (x > 200)
	{
		write(2, "Too many philos\n", 17);
		exit (0);
	}
	return (0);
}
