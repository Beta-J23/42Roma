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
	printf("ARRIVED IN MORSE CONVERTER! c is:%c\n", c);
}

int		client_function(char c, int	pid)
{
	printf("client is handling correct argv that is: %c\n", c);
	kill(pid, SIGUSR2);
	return (0);
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;
	int		i;

	//str = "prova";
	i = 0;
	str = ft_strdup(argv[2]);
	if (argc != 3)
   	{
   		printf("number of argument is invalid\n");
   		exit(EXIT_FAILURE);
   	}
   	pid = atoi(argv[1]);
   	printf("PID: %d\n", pid);
   	printf("string: %s\n", str);
	while (argv[2][i] != '\0')
	{
		//if (ft_isalnum(argv[2][i] == 1))
		morse_converter(argv[2][i]);
		client_function(argv[2][i], pid);
		//else
			//binary_converter(str[i]);
		i++;
		usleep(2000);
	}
   	kill(pid, SIGUSR1);
   	return (0);
}

/*int main()
{
	int		i;
	char	*test;
	
	test = "prrtvdhrt";
	i = ft_strlen(test);
	ft_printf("TEST is of %d letters\n", i);
	return (0);
}
*/