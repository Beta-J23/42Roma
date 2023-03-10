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
#include <signal.h>
#include <sys/types.h>
#include <stdio.h>

//int pid_of_client;

void    binary_handler(int x, int client_pid)
{
    static char     c = 255;
    static int      y;
	//(void)client_pid;
    
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
		if (c == '\0')
		{
			//ft_printf("CLIENT PID IN FUNCTION NUMBER IS: %d\n", client_pid);
			kill(client_pid, SIGUSR1);
		}
        c = 255;
		//pid_of_client = client_pid;
		// if (c == '\n')
		// 	ft_printf("CLIENT PID IN FUNCTION NUMBER IS: %d\n", client_pid);
    }
}
/*
void    server_signal_handler_2(int   sig_num)
{
    (void)sig_num;
    signal(SIGUSR2, server_signal_handler_2);
    binary_handler(0);
}
/
void    server_signal_handler(int   sig_num)
{
    (void)sig_num;
    signal(SIGUSR1, server_signal_handler);
    binary_handler(1);
}
*/

int client_pid_number(int pid)
{
	ft_printf("CLIENT PID IN FUNCTION NUMBER IS: %d", pid);
	return(0);
}

void	client_pid(int sig, siginfo_t *siginfo, void *context)
{
	int client_pid;

	client_pid = siginfo->si_pid;
	(void)sig;
	(void)context;
	(void)client_pid;
	//kill(client_pid, SIGUSR1);
	if (sig == 10)
	{
		//signal(SIGUSR1, server_signal_handler_2);
		//sigaction(SIGUSR1, &to_client, NULL);
		//ft_printf("CLIENT PID SIGINFO is:%d\n", client_pid);
		binary_handler(1, client_pid);
	}
	if (sig == 12)
	{
		//signal(SIGUSR2, server_signal_handler);
		//sigaction(SIGUSR1, &to_client, NULL);
		binary_handler(0, client_pid);
	}

	// if (siginfo ->si_pid)
	//  	client_pid = siginfo->si_pid;
	// if (!sig)
	//  	client_pid_number(client_pid);
}
/*
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
/*
static struct sigaction siga;

static void multi_handler(int sig, siginfo_t *siginfo, void *context) {
    // get pid of sender,
    pid_t sender_pid = siginfo->si_pid;
}
*/
/*
void		new_handler(int sig, siginfo_t *siginfo, void *context)
{
	int client_pid = 0;

	client_pid = siginfo->si_pid;
	(void)sig;
	(void)context;
	kill(client_pid, SIGUSR1);
	//ft_printf("CLIENT PID SIGINFO is:%d\n", client_pid);
	binary_handler(1);

	// if (siginfo ->si_pid)
	//  	client_pid = siginfo->si_pid;
}
*/

// argc + argv to have a string from terminal, string have to be passed as parameter to client.
int main()
{
	struct sigaction	to_client;
    sigset_t            myset;    	
    int     pid;

	sigemptyset(&myset);
	sigaddset(&myset, SIGINT);
	sigaddset(&myset, SIGQUIT);
    pid = getpid();
    ft_printf("main writes: Process id (PID) is: %d\n", pid);
    // CALL signal handler function if compatible signal arrive
    //signal(SIGUSR1, server_signal_handler);
    //signal(SIGUSR2, server_signal_handler_2);
    // //to_client.sa_handler = 0;
    // sigaction(SIGUSR1, SA_SIGINFO, NULL);
	//to_client.sa_mask = block_mask;
	
	to_client.sa_flags = SA_SIGINFO;
	/*
	client_pid = to_client.siginfo.si_pid;
	(void)to_client;
	*/
	to_client.sa_sigaction = client_pid;
	sigaction(SIGUSR1, &to_client, NULL);
	sigaction(SIGUSR2, &to_client, NULL);
	//ft_printf("AFTER WHILE AFTER WHILE!!!!!!!: %d\n\n", pid_of_client);


	
	//client_pid(SIGUSR1, &to_client, NULL);
	//new_handler(SIGUSR1, &to_client, NULL);
	//client_pid(pid);
	while (1)
	{
        pause();
		//ft_printf("PID OF CLIENT: %d", pid_of_client);
	}
	//kill(pid_of_client, SIGUSR1);
    return(0);
}
