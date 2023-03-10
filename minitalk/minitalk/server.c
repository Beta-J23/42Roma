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
#include <sys/types.h>
#include <stdio.h>

void    binary_handler(int x)
{
    static char     c = 255;
    static int      y;
    
    if (x == 0)
    {
        //ft_printf("0");
   	    c ^= 0x80 >> y;
    }
    else if (x == 1)
    {
        //ft_printf("1");
        c |= 128 >> y;
    }
    //ft_printf("c is:%d\n", c);
    y++;
    //ft_printf("y is:%d\n", y);
    if (y == 8)
    {
        //ft_printf("-> %c\n", c);
        ft_printf("%c", c);
        y = 0;
        c = 255;
    }
}

void    server_signal_handler_2(int   sig_num)
{
    (void)sig_num;
    signal(SIGUSR2, server_signal_handler_2);
    binary_handler(0);
}

void    server_signal_handler(int   sig_num)
{
    (void)sig_num;
    signal(SIGUSR1, server_signal_handler);
    binary_handler(1);
}
/*
int client_pid(int pid)
{

}

struct sigaction {
               void         (*sa_handler)(int);
               void         (*sa_sigaction)(int, siginfo_t *, void *);
               sigset_t     sa_mask;
               int          sa_flags;
               void         (*sa_restorer)(void);
           } to_client;

int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact)
{

}
*/


// argc + argv to have a string from terminal, string have to be passed as parameter to client.
int main()
{
    //sigset_t            myset;    
    int     pid;

    //sigemptyset(&sact.sa_mask);
    pid = getpid();
    ft_printf("main writes: Process id (PID) is: %d\n", pid);
    // CALL signal handler function if compatible signal arrive
    signal(SIGUSR1, server_signal_handler);
    signal(SIGUSR2, server_signal_handler_2);
    // //to_client.sa_handler = 0;
    // sigaction(SIGUSR1, SA_SIGINFO, NULL);
	// to_client.sa_mask = block_mask;
	// to_client.sa_sigaction = server_signal_handler;
   //client_pid(pid);
    while (1)
        pause();
    return(0);
}
