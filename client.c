/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:48:25 by sboukiou          #+#    #+#             */
/*   Updated: 2025/02/18 11:30:41 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t signal_received = 0;

void    send_one_byte(unsigned char byte, pid_t target_pid)
{
    int  idx = 0;
    while (idx < 8)
    {
        if (byte > 0 && byte % 2)
        {
            kill(target_pid, SIGUSR1);
            while (!signal_received)
                pause();
        }
        else
        {
            kill(target_pid, SIGUSR2);
            while (!signal_received)
                pause();
        }
        signal_received = 0;
        byte = byte / 2;
        idx++;
    }
}

void    send_string(char *string, pid_t target_pid)
{
    int     idx;

    idx = 0;
    while (string[idx])
    {
        send_one_byte(string[idx], target_pid);
        idx++;
    }
    send_one_byte(0, target_pid);
}

void handle_sigusr(int signal)
{
    (void)signal;
    signal_received = 1;
    if (signal == SIGUSR2)
        ft_printf("Message recieved on the server successfully\n");
}

pid_t	check_arguments(int ac, char **av)
{
	pid_t	target_pid;

	if (ac != 3)
	{
		ft_printf("Usage: ./client [SERVER_PID] [MESSAGE]");
		return (-1);
	}
	target_pid = (pid_t)ft_atoi(av[1]);
	if (target_pid <= 0)
	{
		ft_printf("Error: Invalid process Id given\n");
		return (-1);
	}
	if (kill(target_pid, SIGPING) == -1)
	{
		ft_printf("Error: No process with that ID was found\n");
		return (-1);
	}
	return (target_pid);
}

int main(int ac, char **av)
{
	pid_t	server_pid;
	char	*message;

	server_pid = check_arguments(ac, av);
	if (server_pid == -1)
		return (0);
	message = av[2];
    signal(SIGUSR1, handle_sigusr);
    signal(SIGUSR2, handle_sigusr);
    send_string(message, server_pid);
	return (0);
}
