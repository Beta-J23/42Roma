/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:01:25 by alpelliz          #+#    #+#             */
/*   Updated: 2023/04/18 19:16:05 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

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
} t_stack_a;


typedef struct s_stack_b 
{
	int		size;
	int		index;
	char	*array_b;
	int		*array_int_b;
	int		size_of_int;
} t_stack_b;

typedef struct s_fake
{
	int		*chunk1;
	int		*chunk2;
	int		*chunk3;
	int		*chunk4;
	int		*chunk5;
} t_fake;

int			create_int_array(t_stack_a *a, char *argv);
int			check_argv(t_stack_a *a);
void		initializer(t_stack_a *a, t_stack_b *b);
int			array_filler(t_stack_a *a, char **argv, int argc);
int			check_double(t_stack_a *a);
int			ft_atoi_mod(char *str);
int			atoi_limit(long long nb);
void		ft_swap(int *a, int *b);
int			already_sorted(t_stack_a *a);
int			sa(t_stack_a *a);
int			sb(t_stack_b *b);
int			ss(t_stack_a *a, t_stack_b *b);
int			pa(t_stack_a *a, t_stack_b *b);
int			pb(t_stack_a *a, t_stack_b *b);
int			ra(t_stack_a *a);
int			rb(t_stack_b *b);
int			rr(t_stack_a *a, t_stack_b *b);
int			rra(t_stack_a *a);
int			rrb(t_stack_b *b);
int			rrr(t_stack_a *a, t_stack_b *b);

int			bubble(t_stack_a *a, t_stack_b *b);
int			number_3(t_stack_a *a, t_stack_b *b);
int			number_5(t_stack_a *a, t_stack_b *b);
int			pre_pb_5(t_stack_a *a, t_stack_b *b, int x);
int			smallest_number(t_stack_a *a, t_stack_b *b);

// TEST FUNCTION TO DELETE
void 		array_printer(t_stack_a *a, t_stack_b *b);
int			move_counter(void);
int			sorting_check(t_stack_a *a, t_stack_b *b);
int			case_redirection(t_stack_a *a, t_stack_b *b);
int			biggest_number(t_stack_a *a, t_stack_b *b);

int			number_100(t_stack_a *a, t_stack_b *b);
int			moving_convenience(t_stack_a *a, t_stack_b *b, int x);
int			stuff_mover(t_stack_a *a, t_stack_b *b, int	i);
int			move_down(t_stack_a *a, t_stack_b *b, int	x);
int			move_up(t_stack_a *a, t_stack_b *b, int	x);





#endif