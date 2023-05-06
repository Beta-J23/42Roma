/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:07:48 by alpelliz          #+#    #+#             */
/*   Updated: 2023/05/06 16:51:07 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// args to pass to main are: number_of_philosophers, time_to_die, time_to_eat, time_to_sleep, 
// optional argument: number_of_times_each_philosopher_must_eat: 
// If all philosophers have eaten at least number_of_times_each_philosopher_must_eat
//times, the simulation stops. If not specified, the simulation stops when a
//philosopher dies.


//creating threads
//creating a thread more than number of philo for a clock monitor;
int		thread_creator(t_data *data, t_philo *philo, int argc)
{
	(void)philo;
	(void)argc;
	//pthread_t *thread = NULL;
	int		i;
	
	i = 1;
	data->thread = malloc(sizeof(pthread_t) * data->number_of_philosophers);
	data->mutex= malloc(sizeof(pthread_t) * data->number_of_philosophers);
	while (i <= data->number_of_philosophers)
	{
		//data->thread = malloc(sizeof(pthread_t) * 1);
		//pthread_mutex_init(&data->mutex, NULL);
		data->philo->philo_num = i;
		//pthread_mutex_lock(&data->mutex);
		if (pthread_create(&data->thread[i], NULL, &my_first_routine, (void *)data) != 0)
			return (1);
		pthread_mutex_init(&data->mutex[i], NULL);
		i++;
	}
	i = 0;
	while (i <= data->number_of_philosophers)
	{
		pthread_join(data->thread[i], NULL);
		i++;
	}
	free (data->mutex);
	free (data->thread);
	return 0;
}

int main(int argc, char **argv)
{
	t_philo philo;
	t_data data;
	arg_checker(argc, argv);
	//initializing mutex;
	//pthread_mutex_init(&data.mutex, NULL);
	initializer(&data, &philo, argc, argv);
	thread_creator(&data, &philo, argc);
	return (0);
}