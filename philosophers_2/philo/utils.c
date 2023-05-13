/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:47:03 by alpelliz          #+#    #+#             */
/*   Updated: 2023/05/13 15:41:50 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	ms_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == 1)
	{
		write(2, "Error!, gettime failed.\n", 25);
		return (1);
	}
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	usleep_re(useconds_t time)
{
	u_int64_t	start;

	start = ms_time();
	while ((ms_time() - start) < time)
		usleep(time / 10);
}

/*unsigned long long		ms_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == 1)
	{
		write(2, "Error!, gettime failed.\n", 25);
		return(1);
	}
	return(tv.tv_sec * (unsigned long long)1000) + (tv.tv_usec / 1000);
	//return (tv.tv_usec / 1000);
}*/

/*u_int64_t	get_time(void)
{
	struct timeval	tv;
	
	if (gettimeofday(&tv, NULL))
		return (error("gettimeofday() FAILURE\n", NULL));
	return ((tv.tv_sec * (u_int64_t)1000) + (tv.tv_usec / 1000));
}*/


//clear function

//exit function

//error function

//usleep function