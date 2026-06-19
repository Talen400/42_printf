/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 21:08:49 by tlavared          #+#    #+#             */
/*   Updated: 2025/08/22 21:09:07 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr(unsigned int num, int start)
{
	char		rest;
	static int	len;

	len = start;
	if (num >= 10)
		len = ft_putnbr(num / 10, len + 1);
	rest = (num % 10) + '0';
	ft_putchar_fd(rest, 1);
	return (len);
}

int	ft_printunsigned(va_list ap)
{
	int				len;
	unsigned int	num;

	num = va_arg(ap, unsigned int );
	len = ft_putnbr(num, 0) + 1;
	return (len);
}
