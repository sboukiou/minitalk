#include "minitalk.h"

/*void properly_quit(int signal)*/
/*{*/
/*	printf("Recieved a %d signal , quitting ...\n", signal);*/
/*	exit(0);*/
/*}*/

void	print_signal(int signal)
{
	printf("recieved --> %d\n", signal);
	if (signal == SIGINT)
		exit(0);
}


int main(int ac, char **av)
{
	pid_t	my_pid;
	int		i;

	(void)ac;
	(void)av;
	/*signal(SIGINT, properly_quit);*/
	printf("Sigint is %d\n", SIGINT);
	for (int i = 2; i < 33; i++)
		signal(i, print_signal);
	my_pid = getpid();
	printf("My Process ID is %d\n", my_pid);
	i = 0;
	while (1)
		i++;
	return (0);
}
