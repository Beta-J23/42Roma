/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:59:59 by alpelliz          #+#    #+#             */
/*   Updated: 2023/05/12 12:02:25 by alpelliz         ###   ########.fr       */
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

int		log_printer(t_philoz *philoz, int	x)
{
	int		timestamp;

	//printf("start_t = %lld\n", data->start_time);
	//printf("ms_time = %lld\n", ms_time());
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
		//exit (0);
		return (5);
	}
	if (x == 6)
	{	
		printf("%d, %d, has dropped a fork\n", timestamp, philoz->id);
		return (6);
	}
	return (0);
}

//check gettimeoftheday function

//clock_gettime()