#include "minitalk.h"

t_serverinfo	server_info;

static void handler(int signal, siginfo_t *signal_info, void *context) {
	(void)context;
	/*(void)signal_info;*/
	if (signal == SIGINT)
	{
		ft_printf("%c", server_info.byte);
		server_info.idx = 0;
		server_info.byte = '\0';
	}
	else
	{
		if (signal == SIGUSR1)
			server_info.byte += _pow(2, server_info.idx);
		server_info.idx++;
	}
	kill(signal_info->si_pid, SIGUSR2);
}

int main() {
    struct sigaction signal_data;
    signal_data.sa_sigaction = handler;
    sigemptyset(&signal_data.sa_mask);
    signal_data.sa_flags = SA_SIGINFO;
    if (sigaction(SIGUSR1, &signal_data, NULL) == -1 || sigaction(SIGUSR2, &signal_data, NULL) == -1 || sigaction(SIGINT, &signal_data, NULL) == -1) {
		exit(0);
    }
	ft_printf("%d\n", getpid());
	int	idx;
	while (1)
		idx += 0;

}
