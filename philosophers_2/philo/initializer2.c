/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:42:11 by alpelliz          #+#    #+#             */
/*   Updated: 2023/05/13 17:05:04 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	initializer(t_data *data, t_start *start, int argc, char **argv)
{
	start->number_of_philosophers = ft_atoi_mod(argv[1]);
	start->time_to_die = ft_atoi_mod(argv[2]);
	start->time_to_eat = ft_atoi_mod(argv[3]);
	start->time_to_sleep = ft_atoi_mod(argv[4]);
	start->start_time = ms_time();
	if (argc == 5)
		start->number_of_times_each_philosopher_must_eat = -1;
	if (argc == 6)
		start->number_of_times_each_philosopher_must_eat = ft_atoi_mod(argv[5]);
	super_v_initializer(data, start);
	return (0);
}

int	super_v_initializer(t_data *data, t_start *start)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	data->superv.forks = malloc(sizeof(pthread_mutex_t)
			* start->number_of_philosophers + 1);
	data->superv.eat = malloc(sizeof(unsigned long)
			* start->number_of_philosophers + 1);
	data->superv.action_eat = malloc(sizeof(int)
			* start->number_of_philosophers + 1);
	data->superv.action_sleep = malloc(sizeof(int)
			* start->number_of_philosophers + 1);
	data->superv.death_alarm = 0;
	return (0);
}

int	clean_all(t_data *data, t_start *start, t_philoz *philoz)
{
	(void)philoz;
	(void)start;
	free(data->superv.forks);
	free(data->superv.eat);
	free(data->superv.action_eat);
	free(data->superv.action_sleep);
	return (0);
}