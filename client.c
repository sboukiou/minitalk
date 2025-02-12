/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:48:25 by sboukiou          #+#    #+#             */
/*   Updated: 2025/02/05 15:51:41 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_acknow(int signal)
{
	(void)signal;
}

void	send_one_byte(char byte, int server_pid)
{
		while (byte)
		{
			if (byte % 2 == 0)
				kill(server_pid, SIGUSR2);
			else if (byte % 2 == 1)
				kill(server_pid, SIGUSR1);
			byte = byte / 2;
			pause();
		}
		kill(server_pid, SIGINT);
}

int main(int ac, char **av)
{
	int	server_pid;
	int	byte;
	int	idx;

	if (ac != 3)
	{
		ft_printf("Invalid number of arguments\n");
		return (0);
	}
	signal(SIGUSR2, signal_acknow);
	signal(SIGUSR1, signal_acknow);
	server_pid = ft_atoi(av[1]);
	idx = 0;
	while (av[2][idx])
	{
		byte = av[2][idx];
		send_one_byte(byte, server_pid);
		pause();
		idx++;
	}
	send_one_byte('\n', server_pid);
return (0);
}
