#include "minitalk.h"
#include <math.h>

char byte = 0;

void	print_signal(int signal)
{
	if (signal == SIGINT)
	{
		ft_printf("Exiting \n");
		exit(0);
	}
	else if (signal == SIGUSR1)
		ft_printf("Sigusr1 tirggered .. \n");
	else if (signal == SIGUSR2)
		ft_printf("Sigusr2 tirggered .. \n");
	else
		return ;
}

int main(int ac, char **av)
{
	pid_t	my_pid;

	(void)ac;
	(void)av;
	signal(SIGUSR1, print_signal);
	signal(SIGUSR2, print_signal);
	my_pid = getpid();
	ft_printf("My Process ID is %d\n", my_pid);
	while (1)
		pause();
	return (0);
}
