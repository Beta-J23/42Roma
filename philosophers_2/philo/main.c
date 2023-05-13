/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:07:48 by alpelliz          #+#    #+#             */
/*   Updated: 2023/05/13 16:49:36 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philoz	philoz;
	t_data		data;
	t_start		start;

	arg_checker(argc, argv);
	initializer(&data, &start, argc, argv);
	thread_creator(&data, &philoz, &start, argc);
	clean_all(&data, &start, &philoz);
	return (0);
}
