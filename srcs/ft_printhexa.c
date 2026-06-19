/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 21:07:27 by tlavared          #+#    #+#             */
/*   Updated: 2025/08/22 21:08:03 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhexalower(va_list ap)
{
	char			*hex;
	unsigned int	num;
	int				len;

	hex = "0123456789abcdef";
	num = va_arg(ap, unsigned int );
	len = ft_puthex(hex, num, 0);
	return (len + 1);
}

int	ft_printhexaupper(va_list ap)
{
	char			*hex;
	unsigned int	num;
	int				len;

	hex = "0123456789ABCDEF";
	num = va_arg(ap, unsigned int );
	len = ft_puthex(hex, num, 0);
	return (len + 1);
}
