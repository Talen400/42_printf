/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 15:05:04 by tlavared          #+#    #+#             */
/*   Updated: 2025/07/23 15:10:22 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	c_chr;
	char			*str;

	str = (char *) s;
	c_chr = (unsigned char) c;
	while (*str)
	{
		if ((unsigned char ) *str == c_chr)
			return (str);
		str++;
	}
	if (c_chr == '\0')
		return (str);
	return ((void *) 0);
}
