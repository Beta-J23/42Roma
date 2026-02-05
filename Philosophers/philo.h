/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:01:25 by alpelliz          #+#    #+#             */
/*   Updated: 2023/05/13 18:23:24 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include <pthread.h>
# include <sys/time.h>

struct	s_data;

typedef struct s_superv
{
	int					*action_sleep;
	unsigned long		*eat;
	int					*action_eat;
	int					*fork;
	int					death_alarm;
	int					time_to_eat;
	pthread_mutex_t		*forks;
	pthread_mutex_t		death_mutex;
}	t_superv;

typedef struct s_start
{
	int						number_of_philosophers;
	int						time_to_die;
	int						time_to_eat;
	int						time_to_sleep;
	int						number_of_times_each_philosopher_must_eat;
	unsigned long			start_time;
}	t_start;

typedef struct s_philoz
{
	int					id;
	pthread_mutex_t		mutex;
	pthread_mutex_t		forks_pre;
	pthread_mutex_t		forks_post;
	pthread_t			t;
	t_start				*start;
	t_superv			superv;
}	t_philoz;

typedef struct s_data
{
	pthread_mutex_t		lock;
	u_int64_t			start_time;
	t_philoz			*philoz;
	t_superv			superv;
	t_start				*start;
}	t_data;

//	threads.c
int					thread_creator(t_data *data, t_philoz *philoz,
						t_start *start, int argc);
int					thread_starter(t_data *data, t_philoz *philoz,
						t_start *start, int i);
int					thread_destroyer(t_data *data, t_philoz *philoz,
						t_start *start, int i);
// basic_utils.c
int					ft_strlen(const char *s);
int					ft_isdigit(int c);
int					atoi_limit(long long nb);
int					ft_atoi_mod(char *str);

// utils.c
unsigned long		ms_time(void);
void				usleep_re(useconds_t time);
// arg_checker.c
int					arg_checker(int argc, char **argv);
int					number_checker(int argc, char **argv, int i, int j);
int					minimum_checker(int argc, char **argv, int i, int j);
int					max_num(int x);
//initializer
int					initializer(t_data *data, t_start *start,
						int argc, char **argv);
int					super_v_initializer(t_data *data, t_start *start);
int					starter_struct(t_data *data, t_start *start);
int					clean_all(t_data *data, t_start *start, t_philoz *philoz);
// log_printer
int					log_printer(t_philoz *philoz, int x);
//routines.c
void				*my_first_routine(void *datas);
void				*p_routine(void *datas);
int					p_routine_helper(t_philoz *philoz, int i, int j);
int					eat(t_philoz *philoz, int j);
int					eat_last(t_philoz *philoz, int j);
int					alone(t_philoz *philoz);
int					die_cycle(t_philoz *philoz, int j);
int					sleep_check(t_philoz *philoz);

#endif