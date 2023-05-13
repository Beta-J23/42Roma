/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:47:22 by alpelliz          #+#    #+#             */
/*   Updated: 2023/05/13 17:58:53 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*p_routine(void *datas)
{
	int			i;
	int			j;
	t_philoz	*philoz;

	i = 0;
	j = 0;
	philoz = (t_philoz *) datas;
	if (philoz->start->number_of_philosophers == 1)
	{
		alone(philoz);
		return (0);
	}
	p_routine_helper(philoz, i, j);
	return (0);
}

int	p_routine_helper(t_philoz *philoz, int i, int j)
{
	while (philoz->superv.death_alarm != 1)
	{
		if (j == philoz->start->number_of_times_each_philosopher_must_eat)
			break ;
		if (philoz->superv.death_alarm != 1)
		{
			if ((die_cycle(philoz, j)) == 1)
				break ;
		}
		if (philoz->superv.death_alarm != 1)
			log_printer(philoz, 1);
		if (philoz->id == 1 && philoz->superv.death_alarm != 1)
			j = eat_last(philoz, j);
		if (philoz->id != 1 && philoz->superv.death_alarm != 1)
			j = eat(philoz, j);
		sleep_check(philoz);
		i++;
	}
	return (0);
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
