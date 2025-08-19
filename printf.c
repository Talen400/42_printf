#include "printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	while (*(fmt++))
	{
		if (*(fmt) == '%')
		{
			ft_putstr_fd((char *) fmt, 1);
			ft_putstr_fd("\n", 1);
		}
	}
	va_end(ap);
	return (0);
}
