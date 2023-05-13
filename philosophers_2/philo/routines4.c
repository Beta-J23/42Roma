/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:47:22 by alpelliz          #+#    #+#             */
/*   Updated: 2023/05/13 17:08:45 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// create array of timestamp per fare le differenze per i time
//1	 eat
//2  sleep
//3  die

void	*p_routine(void *datas)
{
	int			i;
	int			j;
	int			x;
	t_philoz	*philoz;

	i = 0;
	j = 0;
	x = 0;
	philoz = (t_philoz *) datas;
	printf("Thread Started, %d\n", philoz->id);
	if (philoz->start->number_of_philosophers == 1)
	{
		alone(philoz);
		return (0);
	}
	while (philoz->superv.death_alarm != 1)
	{
		if (j == philoz->start->number_of_times_each_philosopher_must_eat)
			break ;
		if (philoz->superv.death_alarm == 1)
			break ;
		usleep_re(1);
		if (philoz->superv.death_alarm != 1)
		{
			if ((die_cycle(philoz, j, x)) == 1)
				break ;
		}
		if (philoz->superv.death_alarm != 1)
			log_printer(philoz, 1);
		if (philoz->superv.death_alarm == 1)
			break ;
		if (philoz->id == 1 && philoz->superv.death_alarm != 1)
			j = eat_last(philoz, j);
		if (philoz->id != 1 && philoz->superv.death_alarm != 1)
			j = eat(philoz, j);
		if (philoz->superv.action_eat[philoz->id] == 1 && philoz->superv.death_alarm != 1)
		{
			philoz->superv.action_eat[philoz->id] = 0;
			log_printer(philoz, 4);
			philoz->superv.action_sleep[philoz->id] = 1;
			usleep_re(philoz->start->time_to_sleep);
			philoz->superv.action_sleep[philoz->id] = 0;
		}
		if (philoz->superv.death_alarm == 1)
			break ;
		i++;
	}
	printf("Ending thread, %d\n", philoz->id);
	return (0);
}

int	eat(t_philoz *philoz, int j)
{
	if (j != philoz->start->number_of_times_each_philosopher_must_eat)
	{
		usleep_re(10);
		if ((pthread_mutex_lock(&philoz->superv.forks[philoz->id - 1]) == 0) &&
			(pthread_mutex_lock(&philoz->superv.forks[philoz->id]) == 0))
		{
			log_printer(philoz, 2);
			log_printer(philoz, 2);
			philoz->superv.eat[philoz->id] = ms_time();
			philoz->superv.action_eat[philoz->id] = 1;
			log_printer(philoz, 3);
			usleep_re(philoz->start->time_to_eat);
			j++;
			pthread_mutex_unlock(&philoz->superv.forks[philoz->id - 1]);
			pthread_mutex_unlock(&philoz->superv.forks[philoz->id]);
			usleep_re(1);
		}
	}
	return (j);
}

int	eat_last(t_philoz *philoz, int j)
{
	if (j != philoz->start->number_of_times_each_philosopher_must_eat)
	{
		usleep_re(10);
		if ((pthread_mutex_lock(&philoz->superv.forks[philoz->start->number_of_philosophers]) == 0) 
			&& (pthread_mutex_lock(&philoz->superv.forks[philoz->id]) == 0))
		{
			log_printer(philoz, 2);
			log_printer(philoz, 2);
			philoz->superv.eat[philoz->id] = ms_time();
			philoz->superv.action_eat[philoz->id] = 1;
			log_printer(philoz, 3);
			usleep_re(philoz->start->time_to_eat);
			j++;
			pthread_mutex_unlock(&philoz->superv.forks[philoz->start->number_of_philosophers]);
			pthread_mutex_unlock(&philoz->superv.forks[philoz->id]);
			usleep_re(1);
		}
	}
	return (j);
}

int	alone(t_philoz *philoz)
{
	log_printer(philoz, 1);
	log_printer(philoz, 2);
	usleep_re(philoz->start->time_to_die);
	log_printer(philoz, 5);
	philoz->superv.death_alarm = 1;
	exit (0);
}

int	die_cycle(t_philoz *philoz, int j, int x)
{
	(void)x;
	if (((((ms_time()) - (philoz->superv.eat[philoz->id])
			> (unsigned long)philoz->start->time_to_die)) && j > 0)
			|| (((ms_time() - (unsigned long)philoz->start->start_time)
			> (unsigned long)philoz->start->time_to_die) && (j == 0)))
	{
		philoz->superv.death_alarm = 1;
		log_printer(philoz, 5);
		exit (0);
		//return (1);
		//if ((pthread_mutex_lock(&philoz->superv.death_mutex)) == 0)
		//if ((pthread_mutex_lock(&philoz->superv.forks[0])) == 0)
		//{
		//	printf("\n\nmutex active for philoz ID %d\n\n", philoz->id);
		//	log_printer(philoz, 5);
		//	philoz->superv.death_alarm = 1;
		//	x++;
		//	pthread_mutex_unlock(&philoz->superv.forks[0]);
		//	return (x);
		//	//return(0);
		//}
		//while (x <= philoz->start->number_of_philosophers)
		//{
		//	pthread_mutex_lock(&philoz->superv.forks[x]);
		//	x++;
		//}
	}
	return (0);
}

//int	philo_big_brother(t_philoz *philoz)
//{
//	int		i;

//	i = 1;
//	while (i <= philoz->start->number_of_philosophers)
//	{
//		if (philoz->superv.action_array[i][3] == 1)
//		{
//			philoz->superv.death_alarm = 1;
//			return (1);
//		}
//		i++;
//	}
//	return (0);
//}
