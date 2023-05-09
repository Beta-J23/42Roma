/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:39:11 by alpelliz          #+#    #+#             */
/*   Updated: 2023/05/09 11:56:48 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//args to pass to main are: number_of_philosophers, time_to_die, time_to_eat, time_to_sleep, 
// optional argument: number_of_times_each_philosopher_must_eat: 

int		initializer(t_data *data, int argc, char **argv)
{
	//t_start *start = NULL;
	(void)argc;
	//start = (t_start *)malloc(sizeof(t_start));
	//(void)argv;
	//data->number_of_philosophers = (int)malloc(sizeof(int) * 1);
	//data->number_of_philosophers = 0;
	//data = (t_data *)malloc(sizeof(t_data) * 1);
	//start->number_of_philosophers = ft_atoi_mod(argv[1]);
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
}

int		super_v_initializer(t_data *data)
{
	int		i;

	i = 0;
	
	//malloc or not malloc the arrays of actions and time?
	//data->superv.time_array = NULL;
	data->superv.time_array = (unsigned long long **)malloc(sizeof(unsigned long long *) * (data->number_of_philosophers));
	data->superv.fork = malloc(sizeof(int) * data->number_of_philosophers);
	//data->superv.fork = NULL;
	////data->superv.action_array = (int **)malloc(sizeof(int *) * (data->number_of_philosophers * 4));
	printf("superv1: %p\n", data->superv.action_array);
	data->superv.action_array = (int **)malloc(sizeof(int *) * data->number_of_philosophers);
	while (i < data->number_of_philosophers)
	{
		data->superv.action_array[i] = (int *)malloc(sizeof(int) * 4);
		data->superv.time_array[i] = (unsigned long long *)malloc(sizeof(unsigned long long) * 4);
		//data->superv.action_array[i] = NULL;
		i++;
	}
	//data->superv.action_array = NULL;
	printf("superv2: %p\n", data->superv.action_array);
	data->superv.death_alarm = 0;
	//int *mat = (int *)malloc(rows * cols * sizeof(int));
	//data->superv.think = malloc(sizeof(int) * data->number_of_philosophers);
	//data->superv.sleep = malloc(sizeof(int) * data->number_of_philosophers);
	//data->superv.eat = malloc(sizeof(int) * data->number_of_philosophers);
	//data->superv.fork = malloc(sizeof(int) * data->number_of_philosophers);
	//data->superv.die = malloc(sizeof(int) * data->number_of_philosophers);
	return (0);
}

int clean_all(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		free(data->superv.action_array[i]);
		free(data->superv.time_array[i]);
		//data->superv.action_array[i] = NULL;
		i++;
	}
	free(&data->philoz);
	free(&data->forks);
	free(&data->superv.time_array);
	free(&data->superv.action_array);
	return (0);
}