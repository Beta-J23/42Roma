/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:55:29 by alpelliz          #+#    #+#             */
/*   Updated: 2023/05/13 17:57:08 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h" 

int	sleep_check(t_philoz *philoz)
{
	if (philoz->superv.action_eat[philoz->id] == 1
		&& philoz->superv.death_alarm != 1)
	{
		philoz->superv.action_eat[philoz->id] = 0;
		log_printer(philoz, 4);
		philoz->superv.action_sleep[philoz->id] = 1;
		usleep_re(philoz->start->time_to_sleep);
		philoz->superv.action_sleep[philoz->id] = 0;
	}
	return (0);
}

int	eat(t_philoz *philoz, int j)
{
	if (j != philoz->start->number_of_times_each_philosopher_must_eat)
	{
		usleep_re(1);
		if ((pthread_mutex_lock(&philoz->superv.forks[philoz->id - 1]) == 0)
			&& (pthread_mutex_lock(&philoz->superv.forks[philoz->id]) == 0))
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
		usleep_re(1);
		if ((pthread_mutex_lock(&philoz->superv.forks
					[philoz->start->number_of_philosophers]) == 0)
			&& (pthread_mutex_lock(&philoz->superv.forks[philoz->id]) == 0))
		{
			log_printer(philoz, 2);
			log_printer(philoz, 2);
			philoz->superv.eat[philoz->id] = ms_time();
			philoz->superv.action_eat[philoz->id] = 1;
			log_printer(philoz, 3);
			usleep_re(philoz->start->time_to_eat);
			j++;
			pthread_mutex_unlock(&philoz->superv.forks
			[philoz->start->number_of_philosophers]);
			pthread_mutex_unlock(&philoz->superv.forks[philoz->id]);
			usleep_re(1);
		}
	}
	return (j);
}

int	die_cycle(t_philoz *philoz, int j)
{
	if (((((ms_time()) - (philoz->superv.eat[philoz->id])
					> (unsigned long)philoz->start->time_to_die)) && j > 0)
		|| (((ms_time() - (unsigned long)philoz->start->start_time)
				> (unsigned long)philoz->start->time_to_die) && (j == 0)))
	{
		philoz->superv.death_alarm = 1;
		pthread_mutex_lock(&philoz->superv.forks[0]);
		log_printer(philoz, 5);
		pthread_mutex_unlock(&philoz->superv.forks[0]);
		exit (0);
	}
	return (0);
}
