/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:01:25 by alpelliz          #+#    #+#             */
/*   Updated: 2023/04/20 21:51:35 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

typedef struct s_stack_a
{
	int		size;
	int		counter;
	int		index;
	char	*array_a;
	int		*array_int_a;
	int		size_of_int;
}	t_stack_a;

typedef struct s_stack_b
{
	int		size;
	int		index;
	char	*array_b;
	int		*array_int_b;
	int		size_of_int;
}	t_stack_b;

int			create_int_array(t_stack_a *a);
int			create_int_array_helper(t_stack_a *a, char *str, int i, int z);
int			check_argv(t_stack_a *a);
int			check_argv_helper(t_stack_a *a, int i);
int			error_checker(t_stack_a *a);
void		initializer(t_stack_a *a, t_stack_b *b);
int			array_filler(t_stack_a *a, char **argv, int argc);
int			array_filler_helper_1(t_stack_a *a, char **argv, int argc, int i);
int			array_filler_helper_2(t_stack_a *a, int argc, char **argv, int z);
int			array_filler_helper_2_1(t_stack_a *a, int argc, char **argv, int z);
int			check_double(t_stack_a *a);
int			ft_atoi_mod(char *str);
int			atoi_limit(long long nb);
void		ft_swap(int *a, int *b);
int			already_sorted(t_stack_a *a);
int			sa(t_stack_a *a);
int			sb(t_stack_b *b);
int			ss(t_stack_a *a, t_stack_b *b);
int			pa(t_stack_a *a, t_stack_b *b);
int			pa_helper(t_stack_a *a, t_stack_b *b, int i, int tmp);
int			pb(t_stack_a *a, t_stack_b *b);
int			pb_helper(t_stack_a *a, t_stack_b *b, int i, int tmp);
int			ra(t_stack_a *a);
int			rb(t_stack_b *b);
int			rr(t_stack_a *a, t_stack_b *b);
int			rra(t_stack_a *a);
int			rrb(t_stack_b *b);
int			rrr(t_stack_a *a, t_stack_b *b);

int			bubble(t_stack_a *a, t_stack_b *b);
int			number_3(t_stack_a *a, t_stack_b *b);
int			number_3_helper_1(t_stack_a *a, t_stack_b *b);
int			number_3_helper_2(t_stack_a *a, t_stack_b *b);
int			number_5(t_stack_a *a, t_stack_b *b);
int			pre_pb_5(t_stack_a *a, t_stack_b *b, int x);
int			pre_pb_5_helper(t_stack_a *a, t_stack_b *b, int x);
int			smallest_number(t_stack_a *a, t_stack_b *b);
int			smallest_number_helper(t_stack_a *a, int i, int j, int tmp);

// TEST FUNCTION TO DELETE
void		array_printer(t_stack_a *a, t_stack_b *b);
int			move_counter(void);
int			sorting_check(t_stack_a *a, t_stack_b *b);
int			case_redirection(t_stack_a *a, t_stack_b *b);
int			biggest_number(t_stack_a *a, t_stack_b *b);
int			biggest_b(t_stack_a *a, t_stack_b *b, int number_a);
int			biggest_number_b(t_stack_a *a, t_stack_b *b);
int			biggest_number_helper(t_stack_a *a, int i, int j, int tmp);
int			biggest_number_b_helper(t_stack_b *b, int i, int j, int tmp);
int			fake_order(t_stack_a *a, t_stack_b *b);

int			number_100(t_stack_a *a, t_stack_b *b);
int			moving_convenience(t_stack_a *a, t_stack_b *b, int x);
int			stuff_mover(t_stack_a *a, t_stack_b *b, int i);
int			move_down(t_stack_a *a, t_stack_b *b, int x);
int			move_up(t_stack_a *a, t_stack_b *b, int x);

//TESTING SORT FUNCTIONS IN SORT_ALL
//int number_100(t_stack_a *a, t_stack_b *b);
int			position_number_b(t_stack_a *a, t_stack_b *b, int pos_a);
int			moving_convenience_2(t_stack_a *a, t_stack_b *b, int pos_a, int pos_b);
int			smallest_usable(int *tmp, int size);
int			move_down_b(t_stack_a *a, t_stack_b *b, int y);
int			move_up_b(t_stack_a *a, t_stack_b *b, int y);
int			moving_convenience_b(t_stack_a *a, t_stack_b *b, int value);
int			smallest_number_modified(t_stack_a *a, t_stack_b *b, int w);
int			smallest_number_mod(t_stack_a *a, t_stack_b *b, int pos_a);
int			smallest_number_position(t_stack_a *a, t_stack_b *b, int k, int *array_reserve);
int			move_b(t_stack_a *a, t_stack_b *b, int x, int value);

#endif