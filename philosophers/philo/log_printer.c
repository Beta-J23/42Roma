/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:59:59 by alpelliz          #+#    #+#             */
/*   Updated: 2023/05/06 16:05:15 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


//gettimeofday()
//About the logs of your program:
//• Any state change of a philosopher must be formatted as follows:
//◦ timestamp_in_ms X has taken a fork
//◦ timestamp_in_ms X is eating
//◦ timestamp_in_ms X is sleeping
//◦ timestamp_in_ms X is thinking
//◦ timestamp_in_ms X died
//Replace timestamp_in_ms with the current timestamp in milliseconds
//and X with the philosopher number.
//• A displayed state message should not be mixed up with another message.
//• A message announcing a philosopher died should be displayed no more than 10 ms
//after the actual death of the philosopher.
//• Again, philosophers should avoid dying!
//Your program must not have any data races.

int		log_printer(t_data *data, int	x)
{
	unsigned long long		timestamp;

	// capire come mettere time 0;
	timestamp = ms_time();
	if (x == 1)
	{	
		printf("%lld, %d, is thinking", timestamp, data->philo->philo_num);
		return (1);
	}
	if (x == 2)
	{	
		printf("%lld, %d, has taken a fork", timestamp, data->philo->philo_num);
		return (2);
	}
	if (x == 3)
	{	
		printf("%lld, %d, is eating", timestamp, data->philo->philo_num);
		return (3);
	}
	if (x == 4)
	{	
		printf("%lld, %d, is sleeping", timestamp, data->philo->philo_num);
		return (4);
	}
	return (0);
}

//check gettimeoftheday function

//clock_gettime()