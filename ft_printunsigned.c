#include "printf.h"

static void	ft_putnbr(unsigned int num)
{
	char	rest;

	if (num > 10)
		ft_putnbr(num / 10);
	rest = (num % 10) + '0';
	ft_putchar_fd(rest, 1);
}

void	ft_printunsigned(va_list ap)
{
	unsigned int	num;
	
	num = va_arg(ap, unsigned int );
	ft_putnbr(num);
}
