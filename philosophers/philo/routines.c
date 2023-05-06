/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:25:34 by alpelliz          #+#    #+#             */
/*   Updated: 2023/05/06 17:01:07 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// create array of timestamp per fare le differenze per i time
//1	 eat
//2  sleep
//3  die


void *my_first_routine(void *datas)
{
	int		i;
	int		j;
	int		life;
	
	i = 0;
	j = 0;
	t_data *data = (t_data *)datas;
	//pthread_mutex_init(&data->mutex, NULL);
	//printf("philo_num = %d\n", data->philo->philo_num);
	printf("first test from threads\n");
	printf("data->philo->philo_num %d\n", data->philo->philo_num);
	// while supervisor don-t say to stop thining.
	
	if (data->philo->philo_num != 1 && data->superv->think == 1);
	{
		printf ("philo %d is thinking", data->philo->philo_num);
	}
	while(data->philo->philo_num != 1 && data->superv->think[data->philo->philo_num] != 1)
		i = 0;
	//pthread_mutex_lock(&data->mutex);
	// while non abbiamo raggiunto il numero dell'argomento opzionale && non ci sono filosofi died
	while (i < data->number_of_times_each_philosopher_must_eat && data->superv->death_alarm == 0)
	{
		//thinkin
		printf ("philo %d is thinking", data->philo->philo_num);
		//log_printer(data, 1);
		if (gettimeofday() - data->superv->time_array > data->time_to_die)
			data->superv->death_alarm = 1;
		// eating
		// if fork precedente is available, take it, take also next fork. And eat!
		if (data->superv->fork - 1 == 0)
		{
			pthread_mutex_lock(&data->mutex[data->philo->philo_num]);
			data->superv->fork - 1 == 1;
			printf("philo %d has taken a fork", data->philo->philo_num);
			//log_printer(data, 2);
			data->superv->fork == 1;
			data->superv->time_array[data->philo->philo_num][1] = gettimeofday();
			printf("philo %d is eating", data->philo->philo_num);
			//log_printer(data, 3);
			usleep(data->time_to_eat * 1000);
			data->superv->fork - 1 == 0;
			data->superv->fork == 0;
			pthread_mutex_unlock(&data->mutex[data->philo->philo_num]);
			
		}
		//sleep
		printf ("philo %d is sleeping", data->philo->philo_num);
		//log_printer(data, 4);
		i++;
	}
	//trying philo routine in the routine;
	/*while (i < data->number_of_philosophers)
	{
		//data->philo_num =  
		if (pthread_create(&data->thread[i], NULL, &philo_routine, NULL) != 0)
			return (0);
		i++;
	}*/
	// develop similar semaphore
	usleep (1000);
	printf("Ending thread\n");
	pthread_mutex_unlock(&data->mutex);
	data->superv->think[data->philo->philo_num] = 0;
	data->superv->sleep[data->philo->philo_num] = 0;
	data->superv->eat[data->philo->philo_num] = 0;
	data->superv->die[data->philo->philo_num] = 0;
	data->philo->philo_num++;
	return (0);
}

int philo_big_brother(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		if (&data->superv[i] == 1)
		{
			printf("philo number %d is dead", i);
			data->superv->death_alarm = 1;
			return (1);
		}
		i++;
	}
	return (0);
}

void *philo_routine()
{
	printf("in philo_routine\n");
	return(0);
}