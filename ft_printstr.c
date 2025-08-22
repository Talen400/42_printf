#include "ft_printf.h"

int	ft_printstr(va_list ap)
{
	int		len;
	char	*str;

	str = va_arg(ap, char *);
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	return (len);
}
