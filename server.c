#include "minitalk.h"
#include <math.h>

char byte = 0;

void	print_signal(int signal)
{
	/*ft_printf("Signal is %d\n", signal);*/
	if (signal == SIGINT)
	{
		ft_printf("%c", byte);
		byte = 0;
	}
	else if (signal == 11)
	{
		ft_printf("\nMessage ended. leaving .. \n");
		exit(0);
	}
	else
		byte += pow(2, signal - 15);
}

void	handle_zero_signal(int signal)
{
	ft_printf("A zero -> %d signal recieved\n", signal);
	exit(0);
}


int main(int ac, char **av)
{
	pid_t	my_pid;
	int		i;

	(void)ac;
	(void)av;
	for (int i = 20; i < 30; i++)
		signal(i, print_signal);
	my_pid = getpid();
	ft_printf("My Process ID is %d\n", my_pid);
	i = 0;
	while (1)
		i++;
	return (0);
}
