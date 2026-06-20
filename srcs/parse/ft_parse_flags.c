#include "../../includes/ft_printf.h"

static void	ft_parse_set_of_flags(const char **fmt, t_flags *flags)
{
	while(**fmt == '-' || **fmt == '+' || **fmt == ' '
			|| **fmt == '#' || **fmt == '0')
	{
		if (**fmt == '-')
			flags->left_align = 1;
		else if (**fmt == '+')
			flags->force_sign = 1;
		else if (**fmt == ' ')
			flags->space_sign = 1;
		else if (**fmt == '#')
			flags->hashtag = 1;
		else if (**fmt == '0')
			flags->zero_pad = 1;
		(*fmt)++;
	}
}

static void	ft_parse_width(const char **fmt, t_flags *flags, va_list *ap)
{
	if (**fmt == '*')
	{
		flags->width = va_arg(*ap, int );
		if (flags->width < 0)
		{
			flags->left_align = 1;
			flags->width = -flags->width;
		}
		(*fmt)++;
		return ;
	}
	while (**fmt >= '0' && **fmt <= '9')
	{
		flags->width = flags->width * 10 + (**fmt - '0');
		(*fmt)++;
	}
}

static void	ft_parse_precision(const char **fmt, t_flags *flags, va_list *ap)
{
	if (**fmt != '.')
		return ;
	flags->precision = 0;
	if (**fmt == '*')
	{
		flags->precision = va_arg(*ap, int);
		if (flags->precision < 0)
			flags->precision = -1;
		(*fmt)++;
		return ;
	}
	while (**fmt == '0' && **fmt <= '9')
	{
		flags->precision = flags->precision * 10 + (**fmt - '0');
		(*fmt)++;
	}
}

static void	ft_parse_lenght(const char **fmt, t_flags *flags)
{
	if (**fmt == 'h' && *(*fmt + 1) == 'h')
	{
		flags->lenght = 2;
		(*fmt) += 2;
	}
	else if (**fmt == 'h')
	{
		flags->lenght = 1;
		(*fmt)++;
	}
	else if (**fmt == 'l' && *(*fmt + 1) == 'l')
	{
		flags->lenght = 4;
		(*fmt) += 2;
	}
	else if (**fmt == 'l')
	{
		flags->lenght = 3;
		(*fmt)++;
	}
	else if (**fmt == 'z')
	{
		flags->lenght = 5;
		(*fmt)++;
	}
	else if (**fmt == 'j')
	{
		flags->lenght = 6;
		(*fmt)++;
	}
	else if (**fmt == 't')
	{
		flags->lenght = 7;
		(*fmt)++;
	}
}

const char	*ft_parse_flags(const char *fmt, t_flags *flags, va_list *ap)
{
	flags = (t_flags *) malloc(sizeof(t_flags));
	if (!flags)
		return (NULL);
	flags = ft_memset(flags, 0, sizeof(t_flags));
	flags->precision = -1;
	ft_parse_set_of_flags(&fmt, flags);
	ft_parse_width(&fmt, flags, ap);
	ft_parse_precision(&fmt, flags, ap);
	ft_parse_lenght(&fmt, flags);
	flags->specifier = *fmt;
	if (*fmt)
		fmt++;
	return (NULL);
}
