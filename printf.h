/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:52:43 by tlavared          #+#    #+#             */
/*   Updated: 2025/08/20 17:33:09 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

// Para testes - remover depois
# include <stdio.h>

# include "libft.h"
# include <stdarg.h>

int		ft_printf(const char *fmt, ...);
void	ft_printchar(va_list ap);
void	ft_printstr(va_list ap);
void	ft_printpointer(va_list ap);
void	ft_printdecimal(va_list ap);
void	ft_printunsigned(va_list ap);

#endif
