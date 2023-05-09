/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:39:11 by alpelliz          #+#    #+#             */
/*   Updated: 2023/05/09 18:08:03 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//args to pass to main are: number_of_philosophers, time_to_die, time_to_eat, time_to_sleep, 
// optional argument: number_of_times_each_philosopher_must_eat: 

int		initializer(t_data *data, int argc, char **argv)
{
	data->number_of_philosophers = ft_atoi_mod(argv[1]);
	data->time_to_die = ft_atoi_mod(argv[2]);
	data->time_to_eat = ft_atoi_mod(argv[3]);
	data->time_to_sleep = ft_atoi_mod(argv[4]);
	data->start_time = ms_time();
	if (argc == 6)
		data->number_of_times_each_philosopher_must_eat = ft_atoi_mod(argv[5]);
	//data->start = (t_start *)malloc(sizeof(t_start));
	starter_struct(data, data->start);
	super_v_initializer(data);
	//data->superv->fork = data->number_of_philosophers;
	return (0);
}

int		super_v_initializer(t_data *data)
{
	int		i;

	i = 1;
	
	//malloc or not malloc the arrays of actions and time?
	data->superv.time_array = (unsigned long long **)malloc(sizeof(unsigned long long *) * (data->number_of_philosophers));
	data->superv.fork = malloc(sizeof(int) * data->number_of_philosophers);
	printf("fork %p\n",data->superv.fork);
	printf("superv.time_array %p\n",data->superv.time_array);
	printf("superv1: %p\n", data->superv.action_array);
	data->superv.action_array = (int **)malloc(sizeof(int *) * data->number_of_philosophers);
	while (i <= data->number_of_philosophers)
	{
		data->superv.fork[i] = 0;
		data->superv.action_array[i] = (int *)malloc(sizeof(int) * 4);
		data->superv.time_array[i] = (unsigned long long *)malloc(sizeof(unsigned long long) * 4);
		//data->superv.action_array[i] = NULL;
		i++;
	}
	printf("superv2: %p\n", data->superv.action_array);
	data->superv.death_alarm = 0;
	return (0);
}

int starter_struct(t_data *data, t_start *start)
{
	start = malloc(sizeof(t_start *));
	printf("start %p\n",start);
	start->number_of_philosophers = data->number_of_philosophers;
	start->time_to_die = data->time_to_die;
	start->time_to_eat = data->time_to_eat;
	start->time_to_sleep = data->time_to_sleep;
	start->number_of_times_each_philosopher_must_eat = data->number_of_times_each_philosopher_must_eat;
	start->start_time = data->start_time;
	return (0);
}

int clean_all(t_data *data)
{
	int		i;

	i = 1;
	(void)data;
	/*while (i <= data->number_of_philosophers)
	{
		free(data->superv.action_array[i]);
		free(data->superv.time_array[i]);
		//data->superv.action_array[i] = NULL;
		i++;
	}*/
	/*
	free(&data->philoz);
	free(&data->superv.fork);
	free(&data->superv.time_array);
	free(&data->superv.action_array);*/
	return (0);
}