/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:13:57 by alpelliz          #+#    #+#             */
/*   Updated: 2023/05/12 11:48:06 by alpelliz         ###   ########.fr       */
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
	j = 0;
	
	printf("Thread Started, %d\n", philoz->id);
	usleep_re(100);
	// while non ci sono filosofi died
	while (philoz->superv.death_alarm == 0)
	{
		printf("philoz->superv.death_alarm == %d\n", philoz->superv.death_alarm);
		//if (philoz->superv.death_alarm == 1)
		//	break;
		log_printer(philoz, 1);
		//die cycle
		if ((((ms_time()) - (philoz->superv.time_array[philoz->id][1])  > 
			((unsigned long)philoz->start->time_to_die) && i > 0)) || 
			(((ms_time() - (unsigned long)philoz->start->start_time) > (unsigned long)philoz->start->time_to_die) && (i == 0)))
		{
			philoz->superv.action_array[philoz->id][3] = 1;
			log_printer(philoz, 5);
			philoz->superv.death_alarm = 1;
			break;
		}
		// eating
		// if fork precedente is available, take it, take also next fork. And eat!
		if (philoz->id == 1)
			j = eat_last(philoz, j);
		if (philoz->id != 1)
			j = eat(philoz, j);
		if (j == 0)
			break;
		log_printer(philoz, 4);
		usleep_re(philoz->start->time_to_sleep);
		//sleep
		philo_big_brother(philoz);
		i++;
	}

	printf("Ending thread, %d\n", philoz->id);
	return (0);
}

int		eat(t_philoz *philoz, int j)
{
	if ((philoz->superv.fork[philoz->id - 1] == 0) && j != philoz->start->number_of_times_each_philosopher_must_eat)
	{
		philoz->superv.fork[philoz->id] = 1;
		pthread_mutex_lock(&philoz->mutex);
		log_printer(philoz, 2);
		philoz->superv.time_array[philoz->id][1] = ms_time();
		log_printer(philoz, 3);
		usleep_re(philoz->start->time_to_eat);
		j++;
		philoz->superv.fork[philoz->id] = 0;
		pthread_mutex_unlock(&philoz->mutex);
	}
	return (j);
}

int		eat_last(t_philoz *philoz, int j)
{
	if ((philoz->superv.fork[philoz->start->number_of_philosophers] == 0) && j != philoz->start->number_of_times_each_philosopher_must_eat)
	{
		philoz->superv.fork[philoz->id] = 1;
		pthread_mutex_lock(&philoz->mutex);
		log_printer(philoz, 2);
		if (philoz->start->number_of_philosophers == 1)
		{
			alone(philoz);
			return(0);
		}
		philoz->superv.time_array[philoz->id][1] = ms_time();
		log_printer(philoz, 3);
		usleep_re(philoz->start->time_to_eat);
		j++;
		philoz->superv.fork[philoz->id] = 0;
		pthread_mutex_unlock(&philoz->mutex);
	}
	return(j);
}

int		alone(t_philoz *philoz)
{
	usleep_re(philoz->start->time_to_die);
	log_printer(philoz, 5);
	philoz->superv.death_alarm = 1;
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
	return (j);
}
