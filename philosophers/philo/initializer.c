/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:39:11 by alpelliz          #+#    #+#             */
/*   Updated: 2023/05/06 14:51:06 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//args to pass to main are: number_of_philosophers, time_to_die, time_to_eat, time_to_sleep, 
// optional argument: number_of_times_each_philosopher_must_eat: 

int		initializer(t_data *data, t_philo *philo, int argc, char **argv)
{
	(void)philo;
	(void)argc;
	//(void)argv;
	//data->number_of_philosophers = (int)malloc(sizeof(int) * 1);
	//data->number_of_philosophers = 0;
	data->number_of_philosophers = ft_atoi_mod(argv[1]);
	data->time_to_die = ft_atoi_mod(argv[2]);
	data->time_to_eat = ft_atoi_mod(argv[3]);
	data->time_to_sleep = ft_atoi_mod(argv[4]);
	if (argc == 6)
		data->number_of_times_each_philosopher_must_eat = ft_atoi_mod(argv[5]);
	super_v_initializer(data, philo);
	//data->superv->fork = data->number_of_philosophers;
	return (0);
}

int		super_v_initializer(t_data *data, t_philo *philo)
{
	(void)philo;
	data->superv->think = malloc(sizeof(int) * data->number_of_philosophers);
	data->superv->sleep = malloc(sizeof(int) * data->number_of_philosophers);
	data->superv->eat = malloc(sizeof(int) * data->number_of_philosophers);
	data->superv->fork = malloc(sizeof(int) * data->number_of_philosophers);
	data->superv->die = malloc(sizeof(int) * data->number_of_philosophers);
	return (0);
}