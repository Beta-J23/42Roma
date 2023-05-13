/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:47:22 by alpelliz          #+#    #+#             */
/*   Updated: 2023/05/13 13:12:02 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// create array of timestamp per fare le differenze per i time
//1	 eat
//2  sleep
//3  die


void	*p_routine(void *datas)
{
	int		i;
	int		j;
	int		x;
	t_philoz *philoz = (t_philoz *) datas;

	i = 0;
	j = 0;
	x = 0;

	printf("Thread Started, %d\n", philoz->id);
	//usleep_re(philoz->id);
	// while non ci sono filosofi died
	while (philoz->superv.death_alarm != 1)// && (pthread_mutex_lock(&philoz->superv.death_mutex) == 1))
	{
		if (j == philoz->start->number_of_times_each_philosopher_must_eat)
			break;
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
		if (philoz->superv.death_alarm == 1)
			break;
		// eating
		// if fork precedente is available, take it, take also next fork. And eat!
		if (philoz->id == 1)
			j = eat_last(philoz, j);
		if (philoz->id != 1)
			j = eat(philoz, j);
		//usleep_re(10);
		//if (philoz->superv.action_array[philoz->id][1] == 1)
		if (philoz->superv.action_eat[philoz->id] == 1)
		{
			//philoz->superv.action_array[philoz->id][1] = 0;
			philoz->superv.action_eat[philoz->id] = 0;
			log_printer(philoz, 4);
			//philoz->superv.action_array[philoz->id][2] = 1;
            philoz->superv.action_sleep[philoz->id] = 1;
			usleep_re(philoz->start->time_to_sleep);
			//philoz->superv.action_array[philoz->id][2] = 0;
			philoz->superv.action_sleep[philoz->id] = 0;
		//die cycle
		//if ((((ms_time()) - (philoz->superv.time_array[philoz->id][1]) > 
		//	(unsigned long)philoz->start->time_to_die && j > 0 && i > 0)) || //prova con j
		if (((((ms_time()) - (philoz->superv.eat[philoz->id]) > 
			(unsigned long)philoz->start->time_to_die)) && j > 0 && i > 0) || //prova con j
			(((ms_time() - (unsigned long)philoz->start->start_time) > (unsigned long)philoz->start->time_to_die) && (j == 0)))
		{	
			printf("ms_time = %lu\n", ms_time());
			printf("(philoz->superv.eat[philoz->id]) = %lu, philoz->id = %d\n", philoz->superv.eat[philoz->id], philoz->id);
			printf("time_to_die = %lu\n", (unsigned long)philoz->start->time_to_die);
			printf("((ms_time()) - (philoz->superv.eat[philoz->id]) = %lu\n", ((ms_time()) - (philoz->superv.eat[philoz->id])));
			printf("i = %d\n", i);
			//printf("(philoz->superv.time_array[philoz->id][1]) = %lu, philoz->id = %d\n", philoz->superv.time_array[philoz->id][1], philoz->id);
			//printf("(ms_time()) - (philoz->superv.time_array[philoz->id][1]) = %lu\n", (ms_time() - philoz->superv.time_array[philoz->id][1]));
			//printf("(unsigned long)philoz->start->time_to_die) = %lu\n", (unsigned long)philoz->start->time_to_die);
			philoz->superv.death_alarm = 1;
			//philoz->superv.action_array[philoz->id][3] = 1;
			log_printer(philoz, 5);
			pthread_mutex_lock(&philoz->superv.death_mutex);
			//while (x <= philoz->start->number_of_philosophers)
			//{
			//	pthread_mutex_lock(&philoz->superv.forks[x]);
			//	x++;
			//}
			break;
		}
		if (philoz->superv.death_alarm == 1)
			break;
		}
		//sleep
		//philo_big_brother(philoz);
		i++;
	}
	//printf("id = %d, j = %d\n",philoz->id, j);
	printf("END philoz->superv.death_alarm == %d\n", philoz->superv.death_alarm);
	printf("Ending thread, %d\n", philoz->id);
	return (0);
}

int	eat(t_philoz *philoz, int j)
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
			//if ((pthread_mutex_lock(&philoz->superv.forks[philoz->id]) == 0))
		//{
			log_printer(philoz, 2);
			//printf("ms_time in EAT = %lu, philoz->id = %d\n", ms_time(), philoz->id);
			//philoz->superv.time_array[philoz->id][1] = ms_time();
			philoz->superv.eat[philoz->id] = ms_time();
			//philoz->superv.action_array[philoz->id][1] = 1;
			philoz->superv.action_eat[philoz->id] = 1;
			//philoz->superv.fork[philoz->id] = 1;
			log_printer(philoz, 3);
			usleep_re(philoz->start->time_to_eat);
			j++;
			//philoz->superv.fork[philoz->id] = 0;
			pthread_mutex_unlock(&philoz->superv.forks[philoz->id - 1]);
			pthread_mutex_unlock(&philoz->superv.forks[philoz->id]);
			usleep_re(1);
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
	if (j != philoz->start->number_of_times_each_philosopher_must_eat)
	{
		//philoz->superv.fork[philoz->id] = 1;
		//pthread_mutex_lock(&philoz->mutex);
		usleep_re(10);
		if ((pthread_mutex_lock(&philoz->superv.forks[philoz->start->number_of_philosophers]) == 0) && (pthread_mutex_lock(&philoz->superv.forks[philoz->id]) == 0))
		{
			log_printer(philoz, 2);
		//usleep_re(1000);
		//if (pthread_mutex_lock(&philoz->superv.forks[philoz->id]) == 0)
		//{
			log_printer(philoz, 2);
			//philoz->superv.time_array[philoz->id][1] = ms_time();
			philoz->superv.eat[philoz->id] = ms_time();
			//philoz->superv.action_array[philoz->id][1] = 1;
			philoz->superv.action_eat[philoz->id] = 1;
			//philoz->superv.fork[philoz->id] = 1;
			log_printer(philoz, 3);
			usleep_re(philoz->start->time_to_eat);
			j++;
			//philoz->superv.fork[philoz->id] = 0;
			pthread_mutex_unlock(&philoz->superv.forks[philoz->start->number_of_philosophers]);
			pthread_mutex_unlock(&philoz->superv.forks[philoz->id]);
			usleep_re(1);
			//log_printer(philoz, 6);
			//log_printer(philoz, 6);
			//pthread_mutex_unlock(&philoz->mutex);
		//}
		}
	}
	return (j);
}

int	alone(t_philoz *philoz)
{
	usleep_re(philoz->start->time_to_die);
	log_printer(philoz, 5);
	philoz->superv.death_alarm = 1;
	return (0);
}

int	philo_big_brother(t_philoz *philoz)
{
	int		i;

	i = 1;
	while (i <= philoz->start->number_of_philosophers)
	{
		if (philoz->superv.action_array[i][3] == 1)
		{
			philoz->superv.death_alarm = 1;
			return (1);
		}
		i++;
	}
	return (0);
}
