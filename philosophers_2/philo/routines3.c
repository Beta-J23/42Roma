/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:47:22 by alpelliz          #+#    #+#             */
/*   Updated: 2023/05/12 16:52:03 by alpelliz         ###   ########.fr       */
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
	//usleep_re(philoz->id);
	// while non ci sono filosofi died
	while (philoz->superv.death_alarm == 0)
	{
		//printf("philoz->superv.death_alarm == %d\n", philoz->superv.death_alarm);
		//if (philoz->superv.death_alarm == 1)
		//	break;
		usleep_re(10);
		log_printer(philoz, 1);
		if (philoz->start->number_of_philosophers == 1)
		{
			alone(philoz);
			return(0);
		}
		//die cycle
		if ((((ms_time()) - (philoz->superv.time_array[philoz->id][1]) > 
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
		if (j == philoz->start->number_of_times_each_philosopher_must_eat)
			break;
		if (philoz->superv.action_array[philoz->id][1] == 1)
		{
			log_printer(philoz, 4);
			philoz->superv.action_array[philoz->id][2] = 1;
			usleep_re(philoz->start->time_to_sleep);
			philoz->superv.action_array[philoz->id][1] = 0;
		}
		//sleep
		philo_big_brother(philoz);
		i++;
	}

	printf("id = %d, j = %d\n",philoz->id, j);
	printf("END philoz->superv.death_alarm == %d\n", philoz->superv.death_alarm);
	printf("Ending thread, %d\n", philoz->id);
	return (0);
}

int		eat(t_philoz *philoz, int j)
{
	//if ((philoz->superv.fork[philoz->id - 1] == 0) && j != philoz->start->number_of_times_each_philosopher_must_eat)
	if (j != philoz->start->number_of_times_each_philosopher_must_eat)
	{
		//philoz->superv.fork[philoz->id] = 1;
		//pthread_mutex_lock(&philoz->mutex);
		usleep_re(10);
		if ((pthread_mutex_lock(&philoz->superv.forks[philoz->id - 1]) == 0) && (pthread_mutex_lock(&philoz->superv.forks[philoz->id]) == 0))
		{
			log_printer(philoz, 2);
		//if ((pthread_mutex_lock(&philoz->superv.forks[philoz->id -1]) == 0))
		//{
			//log_printer(philoz, 2);
			philoz->superv.time_array[philoz->id][1] = ms_time();
			philoz->superv.action_array[philoz->id][1] = 1;
			//philoz->superv.fork[philoz->id] = 1;
			log_printer(philoz, 3);
			usleep_re(philoz->start->time_to_eat);
			j++;
			//philoz->superv.fork[philoz->id] = 0;
			pthread_mutex_unlock(&philoz->superv.forks[philoz->id - 1]);
			pthread_mutex_unlock(&philoz->superv.forks[philoz->id]);
			//log_printer(philoz, 6);
			//log_printer(philoz, 6);
		//}
		}
		//pthread_mutex_unlock(&philoz->mutex);
	}
	return (j);
}

int		eat_last(t_philoz *philoz, int j)
{
	//if ((philoz->superv.fork[philoz->start->number_of_philosophers] == 0) && j != philoz->start->number_of_times_each_philosopher_must_eat)
	//if (j != philoz->start->number_of_times_each_philosopher_must_eat)
	{
		//philoz->superv.fork[philoz->id] = 1;
		//pthread_mutex_lock(&philoz->mutex);
		usleep_re(10);

		if ((pthread_mutex_lock(&philoz->superv.forks[philoz->start->number_of_philosophers]) == 0) && (pthread_mutex_lock(&philoz->superv.forks[philoz->id]) == 0))
		{
			log_printer(philoz, 2);
		//usleep_re(1000);
		//if (pthread_mutex_lock(&philoz->superv.forks[philoz->id - 1]) == 0)
		//{
			//log_printer(philoz, 2);
			philoz->superv.time_array[philoz->id][1] = ms_time();
			philoz->superv.action_array[philoz->id][1] = 1;
			//philoz->superv.fork[philoz->id] = 1;
			log_printer(philoz, 3);
			usleep_re(philoz->start->time_to_eat);
			j++;
			//philoz->superv.fork[philoz->id] = 0;
			pthread_mutex_unlock(&philoz->superv.forks[philoz->start->number_of_philosophers]);
			pthread_mutex_unlock(&philoz->superv.forks[philoz->id]);
			//log_printer(philoz, 6);
			//log_printer(philoz, 6);
			//pthread_mutex_unlock(&philoz->mutex);
		//}
		}
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
