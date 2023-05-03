/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:01:25 by alpelliz          #+#    #+#             */
/*   Updated: 2023/05/03 19:13:24 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>

struct s_philo;

typedef struct s_data
{
	struct	s_philo		*philo;
	int					number_of_philosophers;
	int					forks;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					number_of_times_each_philosopher_must_eat;
	pthread_mutex_t 	mutex;
	pthread_t			*thread;
} t_data;

typedef struct s_philo
{
	t_data	*data;
	int		philo_num;
} t_philo;

int		thread_creator(t_data *data, t_philo *philo, int argc);
// utils.c
int		ft_strlen(const char *s);
int		ft_isdigit(int c);
int		atoi_limit(long long nb);
int		ft_atoi_mod(char *str);
// arg_checker.c
int		arg_checker(int argc, char **argv);
int		number_checker(int argc, char **argv, int i, int j);
int		minimum_checker(int argc, char **argv, int i, int j);
//initializer
int		initializer(t_data *data, t_philo *philo, int argc, char **argv);
void 	*my_first_routine(void *datas);

#endif