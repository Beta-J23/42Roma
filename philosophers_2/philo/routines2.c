/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:13:57 by alpelliz          #+#    #+#             */
/*   Updated: 2023/05/09 17:00:06 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// create array of timestamp per fare le differenze per i time
//1	 eat
//2  sleep
//3  die


void *p_routine(void *datas)
{
	int		i;

	i = 0;
	t_philoz *philoz = (t_philoz *) datas;
	
	printf("Thread Started\n");
	usleep(100);
	printf("philoz->superv.fork[philoz->id - 1] = %d\n", philoz->superv.fork[philoz->id - 1]);
	// while non abbiamo raggiunto il numero dell'argomento opzionale && non ci sono filosofi died
	while (i < philoz->start->number_of_times_each_philosopher_must_eat && philoz->superv.death_alarm == 0)
	{
		//printf("philoz->superv.time_array[philoz->id][1] = \n %lld", philoz->superv.time_array[philoz->id][1]);
		printf("ms_time() = %lld \n", ms_time());
		if (((ms_time() - philoz->superv.time_array[philoz->id][1]) > (unsigned long long)philoz->start->time_to_die))
			philoz->superv.action_array[philoz->id][3] = 1;
		// eating
		// if fork precedente is available, take it, take also next fork. And eat!
		if (philoz->superv.fork[philoz->id - 1] == 0)
		{
			pthread_mutex_lock(&philoz->mutex);
			log_printer(philoz, 2);
			philoz->superv.fork[philoz->id] = 1;
			philoz->superv.time_array[philoz->id][1] = ms_time();
			log_printer(philoz, 3);
			usleep(philoz->start->time_to_eat);
			philoz->superv.fork[philoz->id] = 0;
			pthread_mutex_unlock(&philoz->mutex);
		}
		philo_big_brother(philoz);
		//sleep
		log_printer(philoz, 4);
		i++;
	}
	// develop similar semaphore
	printf("Ending thread\n");
	usleep (1000);
	return (0);
}

int philo_big_brother(t_philoz *philoz)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (i < philoz->start->number_of_philosophers)
	{
		j = 0;
		while (j < 4)
		{
			if (philoz->superv.action_array[i][j] == 1)
			{
				printf("philo number %d is dead", i);
				philoz->superv.death_alarm = 1;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
