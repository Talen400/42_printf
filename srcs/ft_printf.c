#include "../includes/ft_printf.h"

int	ft_type(va_list *ap, const char *fmt)
{
	t_flags	*flags;
	int	d;

	d = 0;
	fmt = ft_parse_flags(fmt, flags, ap);
	if (flags->specifier == 'd' || flags->specifier == 'i')
		d = ft_print_int(fmt);
	free(flags);
	return d;
}


int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		d;

	if (!*fmt)
		return (-1);
	va_start(ap, fmt);
	d = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			d += ft_type(&ap, fmt);
		}
		else
		{
			ft_putchar_fd(*fmt, 1);
			d++;
			fmt++;
		}
	}
	va_end(ap);
	return (d);
}
