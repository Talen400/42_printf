#include "ft_printf.h"

int	ft_printdecimal(va_list ap)
{
	int		len;
	char	*str;

	str = ft_itoa(va_arg(ap, int ));
	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}
