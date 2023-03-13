/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:45:44 by alpelliz          #+#    #+#             */
/*   Updated: 2023/02/15 16:04:59 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

void	binary_handler(int x, int client_pid);
void	client_pid(int sig, siginfo_t *siginfo, void *context);
void	ascii_to_binary(int pid, char word);
void	succesfull_operation(int sig_num);

#endif