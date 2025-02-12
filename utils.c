#include "./minitalk.h"

int	_pow(int base, int power)
{
	int	base_temp;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	base_temp = base;
	while (power > 1)
	{
		base *= base_temp;
		power--;
	}
	return (base);
}
