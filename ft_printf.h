/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:52:43 by tlavared          #+#    #+#             */
/*   Updated: 2025/08/22 20:41:54 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

// Para testes - remover depois
# include <stdio.h>

# include "libft/libft.h"
# include <stdarg.h>

int		ft_printf(const char *fmt, ...);
int	ft_printchar(va_list ap);
int	ft_printstr(va_list ap);
int	ft_printpointer(va_list ap);
int	ft_printdecimal(va_list ap);
int	ft_printunsigned(va_list ap);
int ft_
#endif
