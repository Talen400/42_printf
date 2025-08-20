#include "printf.h"

static void	ft_type(va_list ap, char *fmt)
{
	if (*fmt == 'c')
		ft_printchar(ap);
	else if (*fmt == 's')
		ft_printstr(ap);
	else if (*fmt == 'p')
		ft_printpointer(ap);
	else if (*fmt == 'd')
		return ;
	else if (*fmt == 'i')
		return ;
	else if (*fmt == 'u')
		return ;
	else if (*fmt == 'x')
		return ;
	else if (*fmt == 'X')
		return ;
	else if (*fmt == '%')
		write(1, "%", 1);
}

int	ft_printf(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	while (*(fmt))
	{
		if (*(fmt) == '%')
		{
			fmt++;
			ft_type(ap, (char *) fmt);
			fmt++;
		}
		ft_putchar_fd(*fmt, 1);
		fmt++;
	}
	va_end(ap);
	return (0);
}
