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

void	decode_byte(int byte, int server_pid)
{
	while (byte > 0)
	{
		if (byte % 2)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		byte = byte / 2;
		sleep(0.5);
	}
	kill(server_pid, SIGINT);
	sleep(0.5);
}

int main(int ac, char **av)
{
	int	server_pid;
	int	idx;

	if (ac != 3)
	{
		ft_printf("Invalid number of arguments\n");
		return (0);
	}
	server_pid = ft_atoi(av[1]);
	idx = 0;
	while (av[2][idx])
	{
		decode_byte(av[2][idx], server_pid);
		idx++;
	}
	decode_byte('\n', server_pid);
	return (0);
}
