/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@1339.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:27:29 by sboukiou          #+#    #+#             */
/*   Updated: 2025/02/18 11:33:25 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <strings.h>

volatile sig_atomic_t signal_received = 0;
pid_t   client_pid = 0;

void    signal_handler(int signal, siginfo_t *signal_sender_info, void *ucontext)
{
    (void)ucontext;

    signal_received = signal;
    if (!client_pid)
        client_pid = signal_sender_info->si_pid;
}

void	init_signal(void (*sighandler)(int, siginfo_t *, void *), int size, int *signals_list)
{
	int		            idx;
    struct sigaction    new_action;
    sigset_t            new_act_mask;

    new_action.sa_flags = SA_SIGINFO;
    new_action.sa_sigaction = sighandler;
    sigemptyset(&new_act_mask);
    sigaddset(&new_act_mask, SIGUSR1);
    sigaddset(&new_act_mask, SIGUSR2);
    new_action.sa_mask = new_act_mask;
	idx = 0;
	while (idx < size)
	{
        if (sigaction(signals_list[idx], &new_action, NULL) == -1)
        {
            ft_printf("Error: Failed to init_signal %d \n", signals_list[idx]);
            exit(0);
        }
		idx++;
	}
}
int main(void)
{
    int bit_counter = 0;
    int byte_counter  = 0;
    char    buffer[4096];
    unsigned char    byte = 0;
    int signals_list[31];
	pid_t	self_pid;


    signals_list[0] = SIGUSR1;
    signals_list[1] = SIGUSR2;
    ft_bzero(buffer, 4096);

	/*init_signal(siguser_handler, 2, signals_list);*/
	init_signal(signal_handler, 2, signals_list);

	self_pid = getpid();
	ft_printf("Server Pid is : %d\n", self_pid);
	while (1)
    {
		pause();
        if (signal_received == SIGUSR2)
            bit_counter++;
        else if (signal_received == SIGUSR1)
        {
            byte += _pow(2, bit_counter);
            bit_counter++;
        }
        if (bit_counter == 8 && signal_received)
        {
            buffer[byte_counter] = byte;
            byte_counter++;
            if (byte_counter == BUFFER_SIZE)
            {
                write(STDOUT_FILENO, buffer, byte_counter);
                ft_bzero(buffer, BUFFER_SIZE);
                byte_counter = 0;
            }
            else if (byte == 0)
            {
                write(STDOUT_FILENO, buffer, byte_counter);
                byte_counter = 0;
            }
            bit_counter = 0;
            byte = 0;
        }
        kill (client_pid, SIGUSR1);
    }
	return (0);
}
