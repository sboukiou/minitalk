/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:27:29 by sboukiou          #+#    #+#             */
/*   Updated: 2025/02/13 17:37:34 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <strings.h>

t_tracker   tracker;

void    siguser_handler(int signal, siginfo_t *signal_sender_info, void *ucontext)
{
    (void)ucontext;
    if (signal == SIGUSR2)
        tracker.bit_counter++;
    if (signal == SIGUSR1)
    {
        tracker.byte += _pow(2, tracker.bit_counter);
        tracker.bit_counter++;
    }
    if (tracker.bit_counter == 8)
    {
        tracker.buffer[tracker.byte_counter] = tracker.byte;
        tracker.byte_counter++;
        tracker.bit_counter = 0;
        if (tracker.byte == 3)
        {
            write(STDOUT_FILENO, tracker.buffer, tracker.byte_counter);
                kill(signal_sender_info->si_pid, SIGUSR1);
            ft_bzero(tracker.buffer, 1024);
            tracker.byte_counter = 0;
        }
        tracker.byte = 0;
    }
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
    tracker.bit_counter = 0;
    tracker.byte_counter = 0;
    tracker.byte = 0;
	pid_t	self_pid;
    int signals_list[31];
    signals_list[0] = SIGUSR1;
    signals_list[1] = SIGUSR2;

	init_signal(siguser_handler, 2, signals_list);

	self_pid = getpid();
	ft_printf("Server Pid is : %d\n", self_pid);
	while (1)
		pause();
	return (0);
}
