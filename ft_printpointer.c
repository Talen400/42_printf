#include "printf.h"

static void	ft_puthex(char *hex, unsigned long long num)
{
	if (num > 16)
		ft_puthex(hex, num / 16);
	ft_putchar_fd(hex[num % 16],1);
}

void	ft_printpointer(va_list ap)
{
	char	*hex;
	unsigned long long	num;

	hex = "0123456789abcedf";
	num = va_arg(ap, unsigned long long);
	ft_putstr_fd("0x", 1);
	ft_puthex(hex, num);
}
