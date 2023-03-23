/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:33:34 by alpelliz          #+#    #+#             */
/*   Updated: 2023/03/13 15:28:34 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ascii_to_binary(int pid, char word)
{
	int	bitshift;

	bitshift = -1;
	while (++bitshift < 8)
	{
		if (word & 0x80 >> bitshift)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(900);
	}
}

void	succesfull_operation(int sig_num)
{
	(void)sig_num;
	signal(SIGUSR1, succesfull_operation);
	ft_printf("!!!SUCCESFULL OPERATION!!!\n");
}

int	main(int argc, char **argv)
{
	int		pid;
	int		i;
	char	*word;

	word = argv[2];
	i = 0;
	if (argc != 3)
	{
		ft_printf("number of argument is invalid\n");
		exit(EXIT_FAILURE);
	}
	signal(SIGUSR1, succesfull_operation);
	pid = ft_atoi(argv[1]);
	while (word[i] != '\0')
	{
		ascii_to_binary(pid, word[i]);
		i++;
	}
	ascii_to_binary(pid, '\n');
	ascii_to_binary(pid, '\0');
	return (0);
}
