/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:34:01 by alpelliz          #+#    #+#             */
/*   Updated: 2023/05/13 18:04:53 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	thread_creator(t_data *data, t_philoz *philoz, t_start *start, int argc)
{
	int		i;

	(void)argc;
	philoz->id = 0;
	i = 0;
	philoz = (t_philoz *)malloc(sizeof(t_philoz)
			* start->number_of_philosophers);
	philoz->start = start;
	philoz->superv = data->superv;
	thread_starter(data, philoz, start, i);
	i = 0;
	thread_destroyer(data, philoz, start, i);
	free(philoz);
	return (0);
}

int	thread_starter(t_data *data, t_philoz *philoz, t_start *start, int i)
{
	while (i < start->number_of_philosophers)
	{
		philoz[i].id = i + 1;
		philoz[i].start = start;
		philoz[i].superv = data->superv;
		if (pthread_create(&philoz[i].t, NULL, &p_routine,
				(void *)&philoz[i]) != 0)
			return (1);
		pthread_mutex_init(&data->superv.forks[0], NULL);
		pthread_mutex_init(&data->superv.forks[i + 1], NULL);
		pthread_mutex_init(&data->superv.death_mutex, NULL);
		usleep_re(1);
		i++;
	}
	return (0);
}

int	thread_destroyer(t_data *data, t_philoz *philoz, t_start *start, int i)
{
	while (i < start->number_of_philosophers)
	{
		pthread_join(philoz[i].t, NULL);
		pthread_mutex_destroy(&data->superv.forks[0]);
		pthread_mutex_destroy(&data->superv.forks[i]);
		pthread_mutex_destroy(&data->superv.death_mutex);
		i++;
	}
	return (0);
}
