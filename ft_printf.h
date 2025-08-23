/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:52:43 by tlavared          #+#    #+#             */
/*   Updated: 2025/08/22 21:05:19 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// Para testes - remover depois
# include "libft/libft.h"
# include <stdarg.h>

int	ft_printf(const char *fmt, ...);
int	ft_printchar(va_list ap);
int	ft_printstr(va_list ap);
int	ft_printpointer(va_list ap);
int	ft_printdecimal(va_list ap);
int	ft_printunsigned(va_list ap);
int	ft_puthex(char *hex, unsigned long long num, int start);
int	ft_printhexalower(va_list ap);
int	ft_printhexaupper(va_list ap);

#endif
