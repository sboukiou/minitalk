#include "ft_printf.h"

int	ft_printf(const char *buffer, ...)
{
	int		total_length;
	int		idx;
	va_list	args_list;
	va_start(args_list, buffer);

	if (!buffer)
		return (-1);
	idx = 0;
	total_length = 0;
	while (buffer[idx])
	{
		if (buffer[idx] == '%')
			total_length += handle_format(buffer, args_list, idx++);
		else
			total_length += print_char(buffer[idx]);
		idx++;
	}
	return (total_length);
}
