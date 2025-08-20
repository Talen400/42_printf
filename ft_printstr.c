#include "printf.h"

void	ft_printstr(va_list ap)
{
	char	*str;

	str = va_arg(ap, char *);
	ft_putstr_fd(str, 1);
}
