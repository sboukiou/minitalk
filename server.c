#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>



int main(int ac, char **av)
{
	pid_t	my_pid;
	(void)ac;
	(void)av;

	my_pid = getpid();
	printf("My Process ID is %d\n", my_pid);
	return (0);
}
