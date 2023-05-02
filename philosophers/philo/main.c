/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:07:48 by alpelliz          #+#    #+#             */
/*   Updated: 2023/05/02 19:02:10 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// args to pass to main are: number_of_philosophers, time_to_die, time_to_eat, time_to_sleep, 
// optional argument: number_of_times_each_philosopher_must_eat: 
// If all philosophers have eaten at least number_of_times_each_philosopher_must_eat
//times, the simulation stops. If not specified, the simulation stops when a
//philosopher dies.

pthread_mutex_t mutex;

void *my_first_routine()
{
	pthread_mutex_lock(&mutex);
	printf("first test from threads\n");
	sleep (2);
	printf("Ending thread\n");
	pthread_mutex_unlock(&mutex);
	return (0);
}

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	//printf("arguments are %d, %s, %s, %s\n", argc, argv[1], argv[2], argv[3]);
	//declaring threads, will be structs.
	pthread_t t1, t2;
	//initializing mutex;
	pthread_mutex_init(&mutex, NULL);
	// creating thread, passing: thread_name, attributes, name of function, args of function.
	if (pthread_create(&t1, NULL, &my_first_routine, NULL) != 0)
		return (1);
	pthread_create(&t2, NULL, &my_first_routine, NULL);
	// it's like a wait but for threads. passing: struct, 
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return (0);
}