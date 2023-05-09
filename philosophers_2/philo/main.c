/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:07:48 by alpelliz          #+#    #+#             */
/*   Updated: 2023/05/09 11:39:05 by alpelliz         ###   ########.fr       */
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
int		thread_creator(t_data *data, t_philoz *philoz, int argc)
{
	(void)argc;
	int		i;
	
	philoz->id = 0;
	i = 1;
	data->philoz = (t_philoz *)malloc(sizeof(t_philoz) * data->number_of_philosophers);
	
	//data->philoz[i].t = malloc(sizeof(pthread_t) * data->number_of_philosophers);
	//printf("n_of_phil EAT = %d\n", data->number_of_times_each_philosopher_must_eat);
	
	while (i <= data->number_of_philosophers)
	{
		data->philoz[i].id = i;
		data->philoz[i].datax = data;
		//philoz[i].datax = (t_data *)malloc(sizeof(t_data) * 1);
		if (pthread_create(&data->philoz[i].t, NULL, &p_routine, (void *)&data->philoz[i]) != 0)
			return (1);
		pthread_mutex_init(&data->philoz[i].mutex, NULL);
		i++;
	}
	i = 1;
	while (i <= data->number_of_philosophers)
	{
		pthread_join(data->philoz[i].t, NULL);
		i++;
	}
	return 0;
}

int main(int argc, char **argv)
{
	t_philoz philoz;
	t_data data;
	arg_checker(argc, argv);
	initializer(&data, argc, argv);
	thread_creator(&data, &philoz, argc);
	clean_all(&data);
	return (0);
}