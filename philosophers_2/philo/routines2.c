/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:13:57 by alpelliz          #+#    #+#             */
/*   Updated: 2023/05/09 11:32:52 by alpelliz         ###   ########.fr       */
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
	//t_data *data = (t_data *)datas;
	t_philoz *philoz = (t_philoz *) datas;
	
	//(void)data;
	//philoz->datax = (t_data *)malloc(sizeof(t_data) * 1);
	printf("Thread Started\n");
	usleep(100);
	//printf ("n of philz = %d\n", data->number_of_philosophers);
	printf ("n of philz = %d\n", philoz->id);
	usleep(100);
	printf("experiment 1 data n of philo = %d\n", philoz->datax->number_of_philosophers);
	//printf("n_of_phil = %d\n", philoz->datax->number_of_times_each_philosopher_must_eat);
	printf("philoz->datax->superv.fork[philoz->id - 1] = %d\n", philoz->datax->superv.fork[philoz->id - 1]);
	printf("death alarm = %d\n", philoz->datax->superv.death_alarm);
	// while non abbiamo raggiunto il numero dell'argomento opzionale && non ci sono filosofi died
	while (i < philoz->datax->number_of_times_each_philosopher_must_eat && philoz->datax->superv.death_alarm == 0)
	{
		//thinkin
		//log_printer(data, 1);
		//die checker
		//printf("philoz id = %d\n", data->philoz->id);
		printf("1superv ourtine2: %p\n", philoz->datax->superv.action_array);
		//printf("1superv ourtine2: %d\n", philoz->datax->superv.action_array[philoz->id][1]);
		if ((ms_time() - philoz->datax->superv.time_array[philoz->id][1]) > (unsigned long long)philoz->datax->time_to_die)
		//	//data->superv->death_alarm = 1;
			philoz->datax->superv.action_array[philoz->id][3] = 1;
		// eating
		printf("TEST\n");
		// if fork precedente is available, take it, take also next fork. And eat!
		if (philoz->datax->superv.fork[philoz->id - 1] == 0)
		{
			printf("2superv ourtine2: %p\n", philoz->datax->superv.action_array);
			pthread_mutex_lock(&philoz->mutex);
			//data->superv->fork[data->philo->philo_num] - 1 = 1; //array - 1 is not modifiable
			//printf("philo %d has taken a fork", data->philo->philo_num);
			log_printer(philoz->datax, 2);
			philoz->datax->superv.fork[philoz->id] = 1;
			printf("fork situation = %d \n", philoz->datax->superv.fork[philoz->id]);
			philoz->datax->superv.time_array[philoz->id][1] = ms_time();
			//printf("philo %d is eating", data->philo->philo_num);
			log_printer(philoz->datax, 3);
			usleep(philoz->datax->time_to_eat);
			//data->superv->fork[data->philo->philo_num] - 1 = 0; //array - 1 is not modifiable
			philoz->datax->superv.fork[philoz->id] = 0;
			pthread_mutex_unlock(&philoz->mutex);
		}
		
		philo_big_brother(philoz->datax);
		//sleep
		printf ("philo %d is sleeping\n", philoz->id);
		//log_printer(data, 4);
		i++;
	}
	// develop similar semaphore
	printf("Ending thread\n");
	usleep (1000);
	/*data->superv->think[data->philo->philo_num] = 0;
	data->superv->sleep[data->philo->philo_num] = 0;
	data->superv->eat[data->philo->philo_num] = 0;
	data->superv->die[data->philo->philo_num] = 0;
	data->philo->philo_num++;*/
	return (0);
}
/*
int		initializer(t_data *data, int argc, char **argv)
{
	t_start *start = NULL;
	start = (t_start *)malloc(sizeof(t_start));
	//(void)argv;
	//data->number_of_philosophers = (int)malloc(sizeof(int) * 1);
	//data->number_of_philosophers = 0;
	//data = (t_data *)malloc(sizeof(t_data) * 1);
	start->number_of_philosophers = ft_atoi_mod(argv[1]);
	data->number_of_philosophers = ft_atoi_mod(argv[1]);
	data->time_to_die = ft_atoi_mod(argv[2]);
	data->time_to_eat = ft_atoi_mod(argv[3]);
	data->time_to_sleep = ft_atoi_mod(argv[4]);
	data->start_time = ms_time();
	//data->philo_num_i = malloc(sizeof(int) * data->number_of_philosophers);
	if (argc == 6)
		data->number_of_times_each_philosopher_must_eat = ft_atoi_mod(argv[5]);
	super_v_initializer(data);
	//data->superv->fork = data->number_of_philosophers;
	return (0);
}*/

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
