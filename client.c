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

int main(int ac, char **av)
{
	int	server_pid;

	if (ac != 3)
	{
		ft_printf("Invalid number of arguments\n");
		return (0);
	}
	server_pid = ft_atoi(av[1]);
	kill(server_pid, SIGUSR1);
	kill(server_pid, SIGUSR2);
	return (0);
}
