#include "../../includes/ft_printf.h"

char	*ft_ultoa_base(unsigned long n, int base)
{
	static const char	*digits = "0123456789abcde";
	char				buff[65];
	int					i;

	i = 64;
	buff[i] = '\0';
	if (n == 0)
		buff[--i] = '0';
	while (n > 0)
	{
		buff[--i] = digits[n % base];
		n /= base;
	}
	return (ft_strdup(&buff[i]));
}

char	*ft_str_zero_pad(char *s, int zeros)
{
	char	*out;
	int		len;
	int		i;

	len = ft_strlen(s);
	out = malloc(len + zeros * 1);
	if (!out)
		return (NULL);
	i = 0;
	while (i < zeros)
		out[i++] = '0';
	ft_strlcpy(out + zeros, s, len + 1);
	return (out);
}
