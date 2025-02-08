#include "minitalk.h"
#include <math.h>

int byte = 0;
int	idx = 0;

void	print_signal(int signal)
{
	if (signal == SIGUSR1)
	{
		/*ft_printf("recieved a 1\n");*/
		byte += pow(2, idx);
		idx++;
	}
	else if (signal == SIGUSR2)
		idx++;
	else if (signal == SIGINT)
	{
		ft_printf("%c", byte);
		idx = 0;
		byte = 0;
	}
}

int main(int ac, char **av)
{
	pid_t	my_pid;

	(void)ac;
	(void)av;
	signal(SIGUSR1, print_signal);
	signal(SIGUSR2, print_signal);
	signal(SIGINT, print_signal);
	my_pid = getpid();
	ft_printf("My Process ID is %d\n", my_pid);
	int i = 1;
	while (1)
		i += 0;
	return (0);
}
