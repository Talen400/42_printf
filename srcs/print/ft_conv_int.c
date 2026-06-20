#include "../../includes/ft_printf.h"

static long	ft_get_int_arg(va_list *ap, t_flags *flags)
{
	if (flags->lenght == 3)
		return (va_arg(*ap, long));
	if (flags->lenght == 4)
		return ((long) va_arg(*ap, long long));
	return ((long) va_arg(*ap, int));
}

static char	*ft_digits_with_precision(unsigned long n, int precision)
{
	char	*digits;
	char	*body;
	int		len;

	digits = ft_ultoa_base(n, 10);
	if (n == 0 && precision == 0)
	{
		free(digits);
		return (ft_strdup(""));
	}
	if (precision < 0)
		return (digits);
	len = ft_strlen(digits);
	if (len >= precision)
		return (digits);
	body = ft_str_zero_pad(digits, precision - len);
	free(digits);
	return (body);
}

t_conv	ft_conv_int(va_list *ap, t_flags *flags)
{
	t_conv			conv;
	long			n;
	unsigned long	abs_n;

	n = ft_get_int_arg(ap, flags);
	conv.sign = 0;
	if (n < 0)
		conv.sign = '-';
	else  if (flags->force_sign)
		conv.sign = '+';
	else if (flags->space_sign)
		conv.sign = ' ';
	if (n < 0)
		abs_n = -(unsigned long) n;
	else
		abs_n = (unsigned long) n;
	conv.prefix = NULL;
	conv.body = ft_digits_with_precision(abs_n, flags->precision);
	conv.is_numeric = 1;
	return (conv);
}
