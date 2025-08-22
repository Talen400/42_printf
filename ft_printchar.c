#include "ft_printf.h"

int	ft_printchar(va_list ap)
{
	char	c;

	c = va_arg(ap, int );
	ft_putchar_fd(c, 1);
	return (1);
}
