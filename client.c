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
#include <signal.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	int	server_pid;

	if (ac != 2)
	{
		printf("Invalid number of arguments\n");
		return (0);
	}
	server_pid = atoi(av[1]);
	for (int i = 0; i < 33; i++)
		kill(server_pid, i);
	kill(server_pid, SIGINT);
	return (0);
}
