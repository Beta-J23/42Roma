/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:33:37 by alpelliz          #+#    #+#             */
/*   Updated: 2023/02/21 10:04:07 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void    server_signal_handler_2(int   sig_num)
{
    (void)sig_num;
    signal(SIGUSR2, server_signal_handler_2);
    printf("SIGNAL 2 RECEIVED\n");
    //fflush(stdout);
}

void    server_signal_handler(int   sig_num)
{
    (void)sig_num;
    signal(SIGUSR1, server_signal_handler);
    printf("SIGNAL 1 RECEIVED\n");
    fflush(stdout);
    //signal(SIGUSR2, catch_int);
    //ft_printf("Signal Received by server, str is:");
}


// argc + argv to have a string from terminal, string have to be passed as parameter to client.
int main()
{
    int     pid;
    //char    *str_received;

    pid = getpid();
    printf("main writes: Process id (PID) is: %d\n", pid);
    // CALL signal handler function if compatible signal arrive
    //if 

    //signal(SIGUSR2, catch_int);

    //ft_printf("Signal Received by server, str is:");
    //kill(pid, SIGUSR1);
    //client_function(argv[1], pid);

    // set the INT (Ctrl-C) signal handler to 'catch_int'
    signal(SIGUSR1, server_signal_handler);
    signal(SIGUSR2, server_signal_handler_2);

    while (1)
    {
        pause();
    }
    return(0);
}

/*
// first, here is the signal handler 
void catch_int(int sig_num)
{
    // re-set the signal handler again to catch_int, for next time 
    signal(SIGINT, catch_int);
    printf("Don't do that\n");
    fflush(stdout);
}

int main(int argc, char* argv[])
{
    // set the INT (Ctrl-C) signal handler to 'catch_int' 
    signal(SIGINT, catch_int);

    // now, lets get into an infinite loop of doing nothing. 
    for ( ;; )
        pause();
}
*/
