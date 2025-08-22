#include "ft_printf.h"

static int	ft_putnbr(unsigned int num, int start)
{
	char		rest;
	static int	len;

	len = start;
	if (num >= 10)
		len = ft_putnbr(num / 10, len + 1);
	rest = (num % 10) + '0';
	ft_putchar_fd(rest, 1);
	return (len);
}

int	ft_printunsigned(va_list ap)
{
	int				len;
	unsigned int	num;
	
	num = va_arg(ap, unsigned int );
	len = ft_putnbr(num, 0) + 1;
	return (len);
}
