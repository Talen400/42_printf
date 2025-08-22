#include "ft_printf.h"

static int	ft_type(va_list ap, char *fmt)
{
	int len;

	len = 0;
	if (*fmt == 'c')
		len = ft_printchar(ap);
	else if (*fmt == 's')
		len = ft_printstr(ap);
	else if (*fmt == 'p')
		len = ft_printpointer(ap);
	else if (*fmt == 'd' || *fmt == 'i')
		len = ft_printdecimal(ap);
	else if (*fmt == 'u')
		len = ft_printunsigned(ap);
	else if (*fmt == 'x')
		return (0);
	else if (*fmt == 'X')
		return (0);
	else if (*fmt == '%')
	{
		write(1, "%", 1);
		len++;
	}
	return (len);
}

int	ft_printf(const char *fmt, ...)
{
	va_list ap;
	int		len;

	len = 0;
	if (!fmt)
		return (0);
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*(fmt) == '%')
		{
			fmt++;
			len += ft_type(ap, (char *) fmt);
		}
		else
		{
			ft_putchar_fd(*fmt, 1);
			len++;
		}
		fmt++;
	}
	va_end(ap);
	return (len);
}
