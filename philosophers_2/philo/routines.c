/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:25:34 by alpelliz          #+#    #+#             */
/*   Updated: 2023/05/08 17:12:55 by alpelliz         ###   ########.fr       */
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
	//int		life;
	
	i = 0;
	t_data *data = (t_data *)datas;
	//pthread_mutex_init(&data->mutex, NULL);
	//printf("philo_num = %d\n", data->philo->philo_num);
	printf("first test from threads\n");
	//printf("data->philo->philo_num %d\n", data->philo_num_i);
	// while supervisor don-t say to stop thining.	
	printf ("philo %d is thinking\n", data->philo.philo_num);
	//while(data->philo.philo_num != 1 && data->superv.think[data->philo.philo_num] != 1)
	//	i = 0;
	usleep(100);
	//pthread_mutex_lock(&data->mutex);
	// while non abbiamo raggiunto il numero dell'argomento opzionale && non ci sono filosofi died
	while (i < data->number_of_times_each_philosopher_must_eat && data->superv.death_alarm == 0)
	{
		//thinkin
		//printf ("philo %d is thinking", data->philo->philo_num);
		//log_printer(data, 1);
		//die checker
		//printf("philoz id = %d\n", data->philoz->id);
		if ((ms_time() - data->superv.time_array[data->philo.philo_num][1]) > (unsigned long long)data->time_to_die)
		//	//data->superv->death_alarm = 1;
			data->superv.action_array[data->philo.philo_num][3] = 1;
		// eating
		// if fork precedente is available, take it, take also next fork. And eat!
		if (data->superv.fork[data->philo.philo_num - 1] == 0)
		{
			pthread_mutex_lock(&data->mutex[data->philo.philo_num]);
			//data->superv->fork[data->philo->philo_num] - 1 = 1; //array - 1 is not modifiable
			//printf("philo %d has taken a fork", data->philo->philo_num);
			log_printer(data, 2);
			data->superv.fork[data->philo.philo_num] = 1;
			printf("fork situation = %d \n", data->superv.fork[data->philo.philo_num]);
			data->superv.time_array[data->philo.philo_num][1] = ms_time();
			printf("TEST\n");
			//printf("philo %d is eating", data->philo->philo_num);
			log_printer(data, 3);
			usleep(data->time_to_eat);
			//data->superv->fork[data->philo->philo_num] - 1 = 0; //array - 1 is not modifiable
			data->superv.fork[data->philo.philo_num] = 0;
			pthread_mutex_unlock(&data->mutex[data->philo.philo_num]);
		}
		
		philo_big_brother(data);
		//sleep
		printf ("philo %d is sleeping\n", data->philo.philo_num);
		//log_printer(data, 4);
		i++;
	}
	// develop similar semaphore
	usleep (1000);
	printf("Ending thread\n");
	/*data->superv->think[data->philo->philo_num] = 0;
	data->superv->sleep[data->philo->philo_num] = 0;
	data->superv->eat[data->philo->philo_num] = 0;
	data->superv->die[data->philo->philo_num] = 0;
	data->philo->philo_num++;*/
	return (0);
}

// death alarm
int philo_big_brother(t_data *data)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (i < data->number_of_philosophers)
	{
		j = 0;
		while (j < 4)
		{
			if (data->superv.action_array[i][j] == 1)
			{
				printf("philo number %d is dead", i);
				data->superv.death_alarm = 1;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
