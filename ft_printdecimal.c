#include "printf.h"

void	ft_printdecimal(va_list ap)
{
	char	*str;

	str = ft_itoa(va_arg(ap, int ));
	ft_putstr_fd(str, 1);
}
