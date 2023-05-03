/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:25:34 by alpelliz          #+#    #+#             */
/*   Updated: 2023/05/03 19:46:59 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *my_first_routine(void *datas)
{
	int		i;
	
	i = 0;
	t_data *data = (t_data *)datas;
	//pthread_mutex_init(&data->mutex, NULL);
	printf("philo_num = %d\n", data->philo->philo_num);
	//pthread_mutex_lock(&data->mutex);
	printf("first test from threads\n");
	//trying philo routine in the routine;
	while (i < data->number_of_philosophers)
	{
		//data->philo_num =  
		if (pthread_create(&data->thread[i], NULL, &philo_routine, NULL) != 0)
			return (0);
		i++;
	}
	sleep (1);
	printf("Ending thread\n");
	pthread_mutex_unlock(&data->mutex);
	return (0);
}

void *philo_routine()
{
	printf("in philo_routine\n");
	return(0);
}