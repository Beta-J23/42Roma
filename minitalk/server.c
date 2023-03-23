/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:33:37 by alpelliz          #+#    #+#             */
/*   Updated: 2023/03/13 15:24:52 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	binary_handler(int x, int client_pid)
{
	static char		c = 0xFF;
	static int		y;

	if (x == 0)
	{
		c ^= 0x80 >> y;
	}
	else if (x == 1)
	{
		c |= 0x80 >> y;
	}
	y++;
	if (y == 8)
	{
		ft_printf("%c", c);
		y = 0;
		if (c == '\0')
		{
			kill(client_pid, SIGUSR1);
		}
		c = 0xFF;
	}
}

void	client_pid(int sig, siginfo_t *siginfo, void *context)
{
	int	client_pid;

	client_pid = siginfo->si_pid;
	(void)sig;
	(void)context;
	(void)client_pid;
	if (sig == SIGUSR1)
	{
		binary_handler(1, client_pid);
	}
	if (sig == SIGUSR2)
	{
		binary_handler(0, client_pid);
	}
}

int	main(void)
{
	struct sigaction	to_client;
	sigset_t			myset;
	int					pid;

	sigemptyset(&myset);
	sigaddset(&myset, SIGINT);
	sigaddset(&myset, SIGQUIT);
	pid = getpid();
	ft_printf("PID: %d\n", pid);
	to_client.sa_flags = SA_SIGINFO;
	to_client.sa_sigaction = client_pid;
	sigaction(SIGUSR1, &to_client, NULL);
	sigaction(SIGUSR2, &to_client, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
