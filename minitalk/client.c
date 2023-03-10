/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:33:34 by alpelliz          #+#    #+#             */
/*   Updated: 2023/02/15 17:40:59 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

int	ft_isalnum(int c)
{
	if ((c < 48 || c > 57) && (c < 65 || (c > 90 && c < 97) || c > 122))
		return (0);
	else
		return (1);
}

//minitalk can only send 2 types of signal: SIGUSR1 SIGUSR2, int 10 e int 12, that will become 1 e 0. These will be converted into binary and sent to server. TRY MORSE for letters and numbers;
void	morse_converter(char	c)
{
	ft_printf("ARRIVED IN MORSE CONVERTER! c is:%c\n", c);
}

int		send_0(char c, int pid)
{
	ft_printf("0 FUNCTION: %c\n", c);
	kill(pid, SIGUSR1);
	return (0);
}

int		send_1(char c, int	pid)
{
	ft_printf("1 FUNCTION: %c\n", c);
	kill(pid, SIGUSR2);
	return (1);
}

int		bit_maker(char c, int pid)
{

	if (ft_isalpha(c) == 1)
		{
			ft_printf("isapha is: %d\n", ft_isalpha(c));
			send_0(c, pid);
		}
	else
		send_1(c, pid);
	return(0);
}

int		client_function(char	c, int	pid)
{
	ft_printf("client is handling correct argv that is: %c\n", c);
	kill(pid, SIGUSR1);
	return (0);
}

void	ascii_to_binary(int	pid, char word)
{
	int bitshift;

	bitshift = -1;
   	//printf("%c[%d]: ", word, word);
   	while (++bitshift < 8)
   	{
   		if (word & 0x80 >> bitshift)
		{
   			//ft_printf("1");
			kill(pid, SIGUSR1);
		}
   		else
		{
   			//ft_printf("0");
			kill(pid, SIGUSR2);
		}
		usleep(700);
   	}
}

void	succesfull_operation(int sig_num)
{
	(void)sig_num;
	signal(SIGUSR1, succesfull_operation);
	// if (signum == 10)
	ft_printf("!!!SUCCESFULL OPERATION!!!\n");
}

int	main(int argc, char **argv)
{
	int		pid;
	int		client_pid;
	char	*str;
	int		i;
	char	*word;

	
	word = argv[2];
	client_pid = (getpid());
	i = 0;
	str = ft_strdup(argv[2]);
	if (argc != 3)
   	{
   		ft_printf("number of argument is invalid\n");
   		exit(EXIT_FAILURE);
   	}
	signal(SIGUSR1, succesfull_operation);
   	pid = ft_atoi(argv[1]);
   	ft_printf("PID: %d\n", pid);
   	ft_printf("string: %s\n", str);
	ft_printf("client pid is: %d\n", client_pid);
	while (word[i] != '\0')
	{
		ascii_to_binary(pid, word[i]);
		i++;
	}
	ascii_to_binary(pid, '\n');
	ascii_to_binary(pid, '\0');
	//signal(SIGUSR1, succesfull_operation);
   	return (0);
}