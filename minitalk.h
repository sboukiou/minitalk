#ifndef MINITALK_H
# define MINITALK_H

/*#including needed headers for std functions*/
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>


/*Including dependencies -> libft + ft_printf*/
#include "./dependencies/libft/libft.h"
#include "./dependencies/ft_printf/ft_printf.h"

/* Defined costum types*/
typedef struct s_serverinfo
{
	int	byte;
	int	idx;
}	t_serverinfo;

/*Prototypes for utils functions defined int --> utils.c */
int _pow(int base, int power);

#endif
