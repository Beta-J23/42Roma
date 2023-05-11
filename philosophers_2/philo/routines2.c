/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:13:57 by alpelliz          #+#    #+#             */
/*   Updated: 2023/05/11 16:10:18 by alpelliz         ###   ########.fr       */
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
	int		j;

	i = 0;
	t_philoz *philoz = (t_philoz *) datas;
	j = philoz->start->number_of_philosophers;
	
	printf("Thread Started\n");
	usleep_re(100);
	//printf("philoz->superv.fork[philoz->id - 1] = %d\n", philoz->superv.fork[philoz->id - 1]);
	// while non abbiamo raggiunto il numero dell'argomento opzionale && non ci sono filosofi died
	if (philoz->start->number_of_times_each_philosopher_must_eat == - 1)
		philoz->start->number_of_times_each_philosopher_must_eat = 2147483647;
	while (philoz->superv.death_alarm == 0)
	{
		usleep_re(100);
		log_printer(philoz, 1);
		//printf("philoz->superv.time_array[philoz->id][1] = \n %lld", philoz->superv.time_array[philoz->id][1]);
		//printf("ms_time() = %lld \n", ms_time());
		// se time attuale - time dell'ultima volta che ha mangiato > time to die
		
		//printf("philoz id = %d\n", philoz->id);
		//printf("philoz->superv.time_array[philoz->id][1] = %lld, philoz_id = %d\n", philoz->superv.time_array[philoz->id][1], philoz->id);
		//printf ("ms_time() = %lu\n", ms_time());
		//printf("philoz->start->start_time %lld\n", philoz->start->start_time);
		//printf("(philoz->superv.time_array[philoz->id][1] - philoz->start->start_time) = %lu\n", (philoz->superv.time_array[philoz->id][1] - philoz->start->start_time));
		//printf("ms_time() - philoz->start->start_time = %lu\n", ms_time() - philoz->start->start_time);
		//usleep_re(100);
		//printf("AFTER ms_time() - philoz->start->start_time = %lu\n", ms_time() - philoz->start->start_time);
		//printf("philoz->superv.time_array[philoz->id][1] %lu\n", philoz->superv.time_array[philoz->id][1]);
		//printf("ms_time()) - (philoz->superv.time_array[philoz->id][1] = %lu, I = %i, philoz->id = %d\n", 
		//	(ms_time() - philoz->superv.time_array[philoz->id][1]), i, philoz->id);
		if ((((ms_time()) - (philoz->superv.time_array[philoz->id][1])  > 
			((unsigned long)philoz->start->time_to_die) && i > 0)) || 
			(((ms_time() - (unsigned long)philoz->start->start_time) > (unsigned long)philoz->start->time_to_die) && (i == 0)))
		{
			philoz->superv.action_array[philoz->id][3] = 1;
			log_printer(philoz, 5);
			philoz->superv.death_alarm = 1;
			break;
			
			//printf("start_time = %lld\n", philoz->start->start_time);
			//exit (0);
			//printf("philoz->superv.time_array[philoz->id][1] = %lu\n", ms_time() - philoz->superv.time_array[philoz->id][1]);
			//printf("(unsigned long long)philoz->start->time_to_die = %lu\n", (unsigned long)philoz->start->time_to_die);
		}
		if (philoz->superv.death_alarm == 1)
			break;
		// eating
		// if fork precedente is available, take it, take also next fork. And eat!

		if (philoz->id == 1)
			eat_last(philoz, j);
		if (philoz->id != 1)
			eat(philoz, j);
		log_printer(philoz, 4);
		usleep_re(philoz->start->time_to_sleep);
		//sleep
		philo_big_brother(philoz);
		i++;
	}
	// develop similar semaphore
	//usleep (100);
	printf("Ending thread\n");
	return (0);
}

int		eat(t_philoz *philoz, int j)
{
	if ((philoz->superv.fork[philoz->id - 1] == 0) && j > 0)
	{
		philoz->superv.fork[philoz->id] = 1;
		pthread_mutex_lock(&philoz->mutex);
		log_printer(philoz, 2);
		philoz->superv.time_array[philoz->id][1] = ms_time();
		log_printer(philoz, 3);
		usleep_re(philoz->start->time_to_eat);
		j--;
		philoz->superv.fork[philoz->id] = 0;
		pthread_mutex_unlock(&philoz->mutex);
	}
	return (0);
}

int		eat_last(t_philoz *philoz, int j)
{
	if ((philoz->superv.fork[philoz->start->number_of_philosophers] == 0) && j > 0)
	{
		philoz->superv.fork[philoz->id] = 1;
		pthread_mutex_lock(&philoz->mutex);
		log_printer(philoz, 2);
		philoz->superv.time_array[philoz->id][1] = ms_time();
		log_printer(philoz, 3);
		usleep_re(philoz->start->time_to_eat);
		j--;
		philoz->superv.fork[philoz->id] = 0;
		pthread_mutex_unlock(&philoz->mutex);
	}
	return(0);
}

int philo_big_brother(t_philoz *philoz)
{
	int		i;
	int		j;

	j = 0;
	i = 1;
	while (i <= philoz->start->number_of_philosophers)
	{
		if (philoz->superv.action_array[i][3] == 1)
		{
			//printf("philo number %d is dead\n", i);
			philoz->superv.death_alarm = 1;
			return (1);
		}
		i++;
	}
	return (0);
}
