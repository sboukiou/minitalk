#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

#include "../libft/libft.h"

/*Printers defintions*/
int	print_char(char c);
int	print_integer(long long number);
int	print_string(char *str);
#endif
