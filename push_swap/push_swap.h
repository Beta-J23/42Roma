/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:01:25 by alpelliz          #+#    #+#             */
/*   Updated: 2023/04/12 18:55:53 by alpelliz         ###   ########.fr       */
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
	int		index;
	char	*array_a;
	int		*array_int_a;
} t_stack_a;


typedef struct s_stack_b 
{
	int		size;
	int		index;
	char	*array_b;
	int		*array_int_b;
} t_stack_b;

//int		sa(t_stack_a, c);
int		create_int_array(t_stack_a *a, char *argv);
int		check_argv(t_stack_a *a);
void initializer(t_stack_a *a, t_stack_b *b);
int array_filler(t_stack_a *a, char *arg);



#endif