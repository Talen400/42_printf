#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "../libft/libft.h"
#include <stdarg.h>
#include <stdlib.h>
#include <locale.h>
#include <stdint.h>
#include <stddef.h>

/*
 * left_align => '-'
 * force_sign => '+'
 * space_sign => ' '
 * hash_tag => '#'
 * zero_pad => '0'
 * width => minimal lenght (ex: %5d or %*d)
 * precision => (ex: %.5d or %.*d). -1
 * specifier => (disxXp...)
 *
 * int lenght; // h=1, hh=2, l=3, ll=4, z=5, j=6 etc...
 *
 */

typedef struct s_flags
{
	int	left_align;
	int	force_sign;
	int	space_sign;
	int	hashtag;
	int	zero_pad;
	int	width;
	int	precision;
	int	specifier;
	int	lenght;
} t_flags;

typedef struct	s_conv
{
	char	sign;
	char	*prefix;
	char	*body;
	int		is_numeric;
}	t_conv;

// srcs/ft_printf.c
int			ft_printf(const char *fmt, ...);

// srcs/parse/ft_parse_flags.c
const char	*ft_parse_flags(const char *fmt, t_flags *flags, va_list *ap);

// srcs/print/ft_conv_int.c
t_conv	ft_conv_int(va_list *ap, t_flags *flags);

// srcs/print/helpers.c
char	*ft_ultoa_base(unsigned long n, int base);
char	*ft_str_zero_pad(char *s, int zeros);

#endif
