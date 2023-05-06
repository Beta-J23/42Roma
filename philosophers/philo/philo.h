/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:01:25 by alpelliz          #+#    #+#             */
/*   Updated: 2023/05/06 16:56:08 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

struct s_philo;
struct s_superv;
struct s_time;


typedef struct s_data
{
	int					number_of_philosophers;
	//int					**forks_array;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					number_of_times_each_philosopher_must_eat;
	pthread_mutex_t 	*mutex;
	pthread_t			*thread;
	pthread_mutex_t		*forks;
	pthread_mutex_t		lock;
	struct	s_superv	*superv;
	struct	s_philo		*philo;
	struct	s_philo		*time;
} t_data;

typedef struct s_superv
{
	t_data				*data;
	int					**action_array;
	//int					**time_array;
	unsigned long long	**time_array;
	int					*think;
	int					*sleep;
	int					*eat;
	int					*fork;
	int					*die;
	int					death_alarm;
} t_superv;

typedef struct s_philo
{
	t_data	*data;
	int		philo_num;
} t_philo;

struct s_time 
{
	time_t       tv_sec;   /* seconds since Jan. 1, 1970 */
	suseconds_t  tv_usec;  /* and microseconds */
} t_time;

//	main.c
int		thread_creator(t_data *data, t_philo *philo, int argc);
// basic_utils.c
int		ft_strlen(const char *s);
int		ft_isdigit(int c);
int		atoi_limit(long long nb);
int		ft_atoi_mod(char *str);
// utils.c
unsigned long long		ms_time(void);
// arg_checker.c
int		arg_checker(int argc, char **argv);
int		number_checker(int argc, char **argv, int i, int j);
int		minimum_checker(int argc, char **argv, int i, int j);
//initializer
int		initializer(t_data *data, t_philo *philo, int argc, char **argv);
int		super_v_initializer(t_data *data, t_philo *philo);
// log_printer
int		log_printer(t_data *data, int	x);
//routines.c
void 	*my_first_routine(void *datas);
int 	philo_big_brother(t_data *data);

#endif