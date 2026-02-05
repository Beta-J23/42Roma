/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:59:59 by alpelliz          #+#    #+#             */
/*   Updated: 2023/05/13 17:34:45 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	log_printer(t_philoz *philoz, int x)
{
	int		timestamp;

	timestamp = ms_time() - philoz->start->start_time;
	if (x == 1)
		printf("%d, %d, is thinking\n", timestamp, philoz->id);
	if (x == 2)
		printf("%d, %d, has taken a fork\n", timestamp, philoz->id);
	if (x == 3)
		printf("%d, %d, is eating\n", timestamp, philoz->id);
	if (x == 4)
		printf("%d, %d, is sleeping\n", timestamp, philoz->id);
	if (x == 5)
	{
		printf("%d, %d, died\n", timestamp, philoz->id);
		philoz->superv.death_alarm = 1;
	}
	return (0);
}
/*
int	log_printer(t_philoz *philoz, int x)
{
	int		timestamp;

	timestamp = ms_time() - philoz->start->start_time;
	if (x == 1)
	{	
		printf("%d, %d, is thinking\n", timestamp, philoz->id);
		return (1);
	}
	if (x == 2)
	{	
		printf("%d, %d, has taken a fork\n", timestamp, philoz->id);
		return (2);
	}
	if (x == 3)
	{	
		printf("%d, %d, is eating\n", timestamp, philoz->id);
		return (3);
	}
	if (x == 4)
	{	
		printf("%d, %d, is sleeping\n", timestamp, philoz->id);
		return (4);
	}
	if (x == 5)
	{
		printf("%d, %d, died\n", timestamp, philoz->id);
		philoz->superv.death_alarm = 1;
		return (5);
	}
	return (0);
}*/
