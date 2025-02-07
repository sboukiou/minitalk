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

void	send_byte(int byte, pid_t server_pid)
{

	int idx = 0;
	while (idx < 8)
	{
		if (byte % 2)
			kill(server_pid, idx + 15);
		byte = byte / 2;
		idx++;
		sleep(0.4);
	}
	kill (server_pid, SIGINT);
}

void	send_message(char *message, pid_t server_pid)
{
	int	idx;

	if (!message)
		return ;
	idx = 0;
	while (message[idx])
	{
		send_byte(message[idx], server_pid);
		idx++;
	}
	kill(server_pid, 11);
}

int main(int ac, char **av)
{
	int	server_pid;

	if (ac != 3)
	{
		ft_printf("Invalid number of arguments\n");
		return (0);
	}
	server_pid = ft_atoi(av[1]);
	send_message(av[2], server_pid);
	return (0);
}
