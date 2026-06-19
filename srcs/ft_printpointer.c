/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 21:08:13 by tlavared          #+#    #+#             */
/*   Updated: 2025/08/22 21:08:28 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(char *hex, unsigned long long num, int start)
{
	static int	len;

	len = start;
	if (num >= 16)
		ft_puthex(hex, num / 16, len + 1);
	ft_putchar_fd(hex[num % 16], 1);
	return (len);
}

int	ft_printpointer(va_list ap)
{
	int					len;
	char				*hex;
	unsigned long long	num;

	hex = "0123456789abcdef";
	num = va_arg(ap, unsigned long long );
	if (!num)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	len = 2;
	len += ft_puthex(hex, num, 0) + 1;
	return (len);
}
