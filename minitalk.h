#ifndef MINITALK_H
# define MINITALK_H

/*#including needed headers for std functions*/
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

/*Defining Macros*/
# define SIGPING 0
# define BUFFER_SIZE 4096


/*Including dependencies -> libft + ft_printf*/
#include "./dependencies/libft/libft.h"
#include "./dependencies/ft_printf/ft_printf.h"

/* Defined costum types*/
typedef struct s_tracker
{
	int	byte;
	int	bit_counter;
	int	byte_counter;
	char	buffer[BUFFER_SIZE];
}	t_tracker;

/*Signals handlers functions*/
/*static void server_handler(int signal, siginfo_t *signal_info, void *context);*/
void	signal_acknow(int signal);

/*Prototypes for utils functions defined int --> utils.c */
int _pow(int base, int power);

#endif
