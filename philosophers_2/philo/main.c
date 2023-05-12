/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:07:48 by alpelliz          #+#    #+#             */
/*   Updated: 2023/05/12 16:25:45 by alpelliz         ###   ########.fr       */
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
int		thread_creator(t_data *data, t_philoz *philoz, t_start *start, int argc)
{
	(void)argc;
	int		i;
	
	philoz->id = 0;
	i = 0;
	philoz = (t_philoz *)malloc(sizeof(t_philoz) * start->number_of_philosophers);
	philoz->start = start;
	philoz->superv = data->superv;
	while (i < start->number_of_philosophers)
	{
		philoz[i].id = i + 1;
		philoz[i].start = start;
		philoz[i].superv = data->superv;
		//philoz[i].datax = (t_data *)malloc(sizeof(t_data) * 1);
		if (pthread_create(&philoz[i].t, NULL, &p_routine, (void *)&philoz[i]) != 0)
			return (1);
		//pthread_mutex_init(&philoz[i].mutex, NULL);
		pthread_mutex_init(&data->superv.forks[i + 1], NULL);
		usleep_re(1);
		//usleep_re(100);
		//printf ("i = %d\n", i);
		i++;
	}
	//while (++i < start->number_of_philosophers)	
	//	pthread_create(&philoz[i].t, NULL, &p_routine, (void *)&philoz[i]);
	i = 0;
	while (i < start->number_of_philosophers)
	{
		pthread_join(philoz[i].t, NULL);
		//pthread_mutex_destroy(&philoz[i].mutex);
		pthread_mutex_destroy(&data->superv.forks[i]);
		i++;
	}
	//free (philoz);
	return 0;
}

int main(int argc, char **argv)
{
	t_philoz philoz;
	t_data data;
	t_start start;
	arg_checker(argc, argv);
	initializer(&data, &start, argc, argv);
	thread_creator(&data, &philoz, &start, argc);
	clean_all(&data, &start, &philoz);
	return (0);
}
