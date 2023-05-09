/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:42:11 by alpelliz          #+#    #+#             */
/*   Updated: 2023/05/09 18:26:57 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//args to pass to main are: number_of_philosophers, time_to_die, time_to_eat, time_to_sleep, 
// optional argument: number_of_times_each_philosopher_must_eat: 

int		initializer(t_data *data, t_start *start, int argc, char **argv)
{
	start->number_of_philosophers = ft_atoi_mod(argv[1]);
	start->time_to_die = ft_atoi_mod(argv[2]);
	start->time_to_eat = ft_atoi_mod(argv[3]);
	start->time_to_sleep = ft_atoi_mod(argv[4]);
	start->start_time = ms_time();
	if (argc == 6)
		start->number_of_times_each_philosopher_must_eat = ft_atoi_mod(argv[5]);
	//data->start = (t_start *)malloc(sizeof(t_start));
	//starter_struct(data, data->start);
	data->superv.time_to_eat = start->time_to_eat;
	super_v_initializer(data, start);
	//data->superv->fork = data->number_of_philosophers;
	return (0);
}

int		super_v_initializer(t_data *data, t_start *start)
{
	int		i;

	i = 0;
	data->superv.time_array = (u_int64_t **)malloc(sizeof(u_int64_t *) * (start->number_of_philosophers));
	data->superv.fork = malloc(sizeof(int) * start->number_of_philosophers);
	//printf("fork %p\n",data->superv.fork);
	//printf("superv.time_array %p\n",data->superv.time_array);
	//printf("superv1: %p\n", data->superv.action_array);
	data->superv.action_array = (int **)malloc(sizeof(int *) * start->number_of_philosophers);
	while (i < start->number_of_philosophers)
	{
		data->superv.fork[i] = 0;
		data->superv.action_array[i] = (int *)malloc(sizeof(int) * 4);
		data->superv.time_array[i] = (u_int64_t *)malloc(sizeof(u_int64_t) * 4);
		i++;
	}
	//printf("superv2: %p\n", data->superv.action_array);
	data->superv.death_alarm = 0;
	return (0);
}

int	clean_all(t_data *data, t_start *start, t_philoz *philoz)
{
	int		i;

	i = 0;
	(void)philoz;
	(void)data;
	while (i < start->number_of_philosophers)
	{
		free(data->superv.action_array[i]);
		free(data->superv.time_array[i]);
		//data->superv.action_array[i] = NULL;
		i++;
	}
	free(data->superv.fork);
	free(data->superv.time_array);
	free(data->superv.action_array);
	return (0);
}