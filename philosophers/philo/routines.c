/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:25:34 by alpelliz          #+#    #+#             */
/*   Updated: 2023/05/03 19:13:48 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *my_first_routine(void *datas)
{
	t_data *data = (t_data *)datas;
	//data = malloc(sizeof(struct) * )
	//pthread_mutex_init(&data->mutex, NULL);
	pthread_mutex_lock(&data->mutex);
	printf("argv3 = %d\n", data->time_to_eat);
	printf("philo_num = %d\n", data->philo->philo_num);
	printf("first test from threads\n");
	sleep (1);
	printf("Ending thread\n");
	pthread_mutex_unlock(&data->mutex);
	return (0);
}